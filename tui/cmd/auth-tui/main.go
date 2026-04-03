package main

import (
	"flag"
	"fmt"
	"os"

	tea "github.com/charmbracelet/bubbletea"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/app"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/engineclient"
)

func main() {
	var enginePath string
	var dataDir string

	flag.StringVar(&enginePath, "engine-path", "", "Path to the engine CLI binary")
	flag.StringVar(&dataDir, "data-dir", "", "Data directory passed to the engine")
	flag.Parse()

	config, err := engineclient.ResolveConfig(enginePath, dataDir)
	if err != nil {
		fmt.Fprintf(os.Stderr, "auth-tui: %v\n", err)
		os.Exit(1)
	}

	client := engineclient.New(config)
	program := tea.NewProgram(app.NewModel(config, client), tea.WithAltScreen())

	if _, err := program.Run(); err != nil {
		fmt.Fprintf(os.Stderr, "auth-tui: %v\n", err)
		os.Exit(1)
	}
}
