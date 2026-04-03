package engineclient

import (
	"os"
	"path/filepath"
	"testing"
)

func TestResolveConfigPrefersFlagsOverEnvironment(t *testing.T) {
	t.Setenv(enginePathEnvVar, "env-engine")
	t.Setenv(dataDirEnvVar, "env-data")

	root := t.TempDir()
	enginePath := filepath.Join(root, "engine_cli.exe")
	dataDir := filepath.Join(root, ".engine-data")

	if err := os.WriteFile(enginePath, []byte("stub"), 0o600); err != nil {
		t.Fatalf("write fake engine: %v", err)
	}

	config, err := ResolveConfig(enginePath, dataDir)
	if err != nil {
		t.Fatalf("ResolveConfig returned error: %v", err)
	}

	expectedEnginePath, _ := filepath.Abs(enginePath)
	expectedDataDir, _ := filepath.Abs(dataDir)

	if config.EnginePath != expectedEnginePath {
		t.Fatalf("expected engine path %q, got %q", expectedEnginePath, config.EnginePath)
	}

	if config.DataDir != expectedDataDir {
		t.Fatalf("expected data dir %q, got %q", expectedDataDir, config.DataDir)
	}
}

func TestDecodeResponseParsesMetricsPayload(t *testing.T) {
	raw := []byte(`{"ok":true,"result":"success","data":{"login_success_count":2,"login_failure_count":3,"lockout_count":1},"error":null}`)

	response, err := decodeResponse[MetricsData](raw)
	if err != nil {
		t.Fatalf("decodeResponse returned error: %v", err)
	}

	if !response.Ok {
		t.Fatalf("expected ok response")
	}

	if response.Data == nil {
		t.Fatalf("expected metrics payload")
	}

	if response.Data.LoginSuccessCount != 2 || response.Data.LoginFailureCount != 3 || response.Data.LockoutCount != 1 {
		t.Fatalf("unexpected metrics payload: %+v", *response.Data)
	}
}

func TestFindDefaultEnginePathPrefersDotBuildCandidate(t *testing.T) {
	root := t.TempDir()
	dotBuildDir := filepath.Join(root, "engine", ".build")
	if err := os.MkdirAll(dotBuildDir, 0o755); err != nil {
		t.Fatalf("mkdir .build: %v", err)
	}

	enginePath := filepath.Join(dotBuildDir, "engine_cli")
	if err := os.WriteFile(enginePath, []byte("stub"), 0o600); err != nil {
		t.Fatalf("write fake engine: %v", err)
	}

	resolved, err := findDefaultEnginePath(root)
	if err != nil {
		t.Fatalf("findDefaultEnginePath returned error: %v", err)
	}

	expectedPath, _ := filepath.Abs(enginePath)
	if resolved != expectedPath {
		t.Fatalf("expected %q, got %q", expectedPath, resolved)
	}
}
