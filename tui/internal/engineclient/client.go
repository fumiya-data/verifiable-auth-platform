package engineclient

import (
	"fmt"
	"os"
	"path/filepath"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/types"
)

const (
	enginePathEnvVar = "VERIFIABLE_AUTH_ENGINE_PATH"
	dataDirEnvVar    = "VERIFIABLE_AUTH_DATA_DIR"
)

/**
 * Service defines the engine operations consumed by the TUI.
 */
type Service interface {
	Register(loginID string, password string) (CommandResult[EmptyData], error)
	Login(loginID string, password string) (CommandResult[EmptyData], error)
	ChangePassword(oldPassword string, newPassword string) (CommandResult[EmptyData], error)
	Logout() (CommandResult[EmptyData], error)
	ShowAudit() (CommandResult[AuditData], error)
	ShowMetrics() (CommandResult[MetricsData], error)
}

/**
 * Client invokes the engine CLI and decodes its JSON contract.
 */
type Client struct {
	config types.AppConfig
}

/**
 * New builds a client for one resolved runtime configuration.
 */
func New(config types.AppConfig) *Client {
	return &Client{config: config}
}

/**
 * ResolveConfig resolves engine and data paths from flags, environment, and repo-relative defaults.
 */
func ResolveConfig(enginePathValue string, dataDirValue string) (types.AppConfig, error) {
	repoRoot, _ := locateRepoRoot()

	enginePath := firstNonEmpty(enginePathValue, os.Getenv(enginePathEnvVar))
	if enginePath == "" {
		defaultPath, err := findDefaultEnginePath(repoRoot)
		if err != nil {
			return types.AppConfig{}, err
		}
		enginePath = defaultPath
	} else {
		absolutePath, err := filepath.Abs(enginePath)
		if err != nil {
			return types.AppConfig{}, fmt.Errorf("resolve engine path: %w", err)
		}

		enginePath = absolutePath
	}

	if err := validateExecutablePath(enginePath); err != nil {
		return types.AppConfig{}, err
	}

	dataDir := firstNonEmpty(dataDirValue, os.Getenv(dataDirEnvVar))
	if dataDir == "" {
		baseDir := repoRoot
		if baseDir == "" {
			currentDirectory, err := os.Getwd()
			if err != nil {
				return types.AppConfig{}, fmt.Errorf("resolve working directory: %w", err)
			}

			baseDir = currentDirectory
		}

		dataDir = filepath.Join(baseDir, ".engine-data")
	} else {
		absolutePath, err := filepath.Abs(dataDir)
		if err != nil {
			return types.AppConfig{}, fmt.Errorf("resolve data directory: %w", err)
		}

		dataDir = absolutePath
	}

	return types.AppConfig{
		EnginePath: enginePath,
		DataDir:    dataDir,
	}, nil
}

/**
 * Register invokes the engine register command.
 */
func (c *Client) Register(loginID string, password string) (CommandResult[EmptyData], error) {
	return executeRequest[EmptyData](c, "register", "--login-id", loginID, "--password", password)
}

/**
 * Login invokes the engine login command.
 */
func (c *Client) Login(loginID string, password string) (CommandResult[EmptyData], error) {
	return executeRequest[EmptyData](c, "login", "--login-id", loginID, "--password", password)
}

/**
 * ChangePassword invokes the engine change-password command.
 */
func (c *Client) ChangePassword(oldPassword string, newPassword string) (CommandResult[EmptyData], error) {
	return executeRequest[EmptyData](c, "change-password", "--old-password", oldPassword, "--new-password", newPassword)
}

/**
 * Logout invokes the engine logout command.
 */
func (c *Client) Logout() (CommandResult[EmptyData], error) {
	return executeRequest[EmptyData](c, "logout")
}

/**
 * ShowAudit invokes the engine show-audit command.
 */
func (c *Client) ShowAudit() (CommandResult[AuditData], error) {
	return executeRequest[AuditData](c, "show-audit")
}

/**
 * ShowMetrics invokes the engine show-metrics command.
 */
func (c *Client) ShowMetrics() (CommandResult[MetricsData], error) {
	return executeRequest[MetricsData](c, "show-metrics")
}

func executeRequest[T any](client *Client, command string, args ...string) (CommandResult[T], error) {
	commandArgs := []string{command}
	if client.config.DataDir != "" {
		commandArgs = append(commandArgs, "--data-dir", client.config.DataDir)
	}

	commandArgs = append(commandArgs, args...)

	processResult, err := runCommand(client.config.EnginePath, commandArgs...)
	if err != nil {
		return CommandResult[T]{}, err
	}

	response, err := decodeResponse[T](processResult.stdout)
	if err != nil {
		return CommandResult[T]{}, fmt.Errorf("decode engine response: %w", err)
	}

	return CommandResult[T]{
		Response: response,
		ExitCode: processResult.exitCode,
		Stderr:   processResult.stderr,
	}, nil
}

func firstNonEmpty(values ...string) string {
	for _, value := range values {
		if value != "" {
			return value
		}
	}

	return ""
}

func locateRepoRoot() (string, error) {
	currentDirectory, err := os.Getwd()
	if err != nil {
		return "", err
	}

	directory := currentDirectory
	for {
		if pathExists(filepath.Join(directory, "docs", "system-specification.md")) &&
			pathExists(filepath.Join(directory, "engine")) &&
			pathExists(filepath.Join(directory, "tui")) {
			return directory, nil
		}

		parent := filepath.Dir(directory)
		if parent == directory {
			return "", fmt.Errorf("repository root not found from %s", currentDirectory)
		}

		directory = parent
	}
}

func findDefaultEnginePath(repoRoot string) (string, error) {
	candidates := make([]string, 0, 4)
	if repoRoot != "" {
		candidates = append(candidates,
			filepath.Join(repoRoot, "engine", ".build", "engine_cli.exe"),
			filepath.Join(repoRoot, "engine", ".build", "engine_cli"),
			filepath.Join(repoRoot, "engine", "build", "engine_cli.exe"),
			filepath.Join(repoRoot, "engine", "build", "engine_cli"),
		)
	}

	currentDirectory, err := os.Getwd()
	if err == nil {
		candidates = append(candidates,
			filepath.Join(currentDirectory, "engine", ".build", "engine_cli.exe"),
			filepath.Join(currentDirectory, "engine", ".build", "engine_cli"),
			filepath.Join(currentDirectory, "engine", "build", "engine_cli.exe"),
			filepath.Join(currentDirectory, "engine", "build", "engine_cli"),
			filepath.Join(currentDirectory, "..", "engine", ".build", "engine_cli.exe"),
			filepath.Join(currentDirectory, "..", "engine", ".build", "engine_cli"),
			filepath.Join(currentDirectory, "..", "engine", "build", "engine_cli.exe"),
			filepath.Join(currentDirectory, "..", "engine", "build", "engine_cli"),
		)
	}

	for _, candidate := range candidates {
		if pathExists(candidate) {
			return filepath.Abs(candidate)
		}
	}

	return "", fmt.Errorf("engine binary not found; set %s or use --engine-path", enginePathEnvVar)
}

func validateExecutablePath(path string) error {
	fileInfo, err := os.Stat(path)
	if err != nil {
		return fmt.Errorf("engine binary is not available at %s", path)
	}

	if fileInfo.IsDir() {
		return fmt.Errorf("engine path points to a directory: %s", path)
	}

	return nil
}

func pathExists(path string) bool {
	_, err := os.Stat(path)
	return err == nil
}
