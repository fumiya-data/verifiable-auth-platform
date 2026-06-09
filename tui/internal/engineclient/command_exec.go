package engineclient

import (
	"bytes"
	"fmt"
	"os/exec"
)

type processResult struct {
	stdout   []byte
	stderr   string
	exitCode int
}

func runCommand(enginePath string, args ...string) (processResult, error) {
	return runCommandWithInput(enginePath, "", args...)
}

func runCommandWithInput(enginePath string, input string, args ...string) (processResult, error) {
	command := exec.Command(enginePath, args...)
	var stdout bytes.Buffer
	var stderr bytes.Buffer

	if input != "" {
		command.Stdin = bytes.NewBufferString(input)
	}
	command.Stdout = &stdout
	command.Stderr = &stderr

	err := command.Run()
	exitCode := 0
	if err != nil {
		exitError, ok := err.(*exec.ExitError)
		if !ok {
			return processResult{}, fmt.Errorf("start engine process: %w", err)
		}

		exitCode = exitError.ExitCode()
	}

	return processResult{
		stdout:   stdout.Bytes(),
		stderr:   stderr.String(),
		exitCode: exitCode,
	}, nil
}
