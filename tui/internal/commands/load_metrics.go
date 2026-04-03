package commands

import (
	tea "github.com/charmbracelet/bubbletea"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/engineclient"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/messages"
)

/**
 * LoadMetrics submits one show-metrics command through the engine client.
 */
func LoadMetrics(client engineclient.Service) tea.Cmd {
	return func() tea.Msg {
		result, err := client.ShowMetrics()
		return messages.MetricsLoaded{
			Result: result,
			Err:    err,
		}
	}
}
