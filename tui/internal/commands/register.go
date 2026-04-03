package commands

import (
	tea "github.com/charmbracelet/bubbletea"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/engineclient"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/messages"
)

/**
 * Register submits one register command through the engine client.
 */
func Register(client engineclient.Service, loginID string, password string) tea.Cmd {
	return func() tea.Msg {
		result, err := client.Register(loginID, password)
		return messages.RegisterFinished{
			Result:  result,
			Err:     err,
			LoginID: loginID,
		}
	}
}
