package commands

import (
	tea "github.com/charmbracelet/bubbletea"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/engineclient"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/messages"
)

/**
 * Logout submits one logout command through the engine client.
 */
func Logout(client engineclient.Service) tea.Cmd {
	return func() tea.Msg {
		result, err := client.Logout()
		return messages.LogoutFinished{
			Result: result,
			Err:    err,
		}
	}
}
