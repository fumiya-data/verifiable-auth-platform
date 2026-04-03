package commands

import (
	tea "github.com/charmbracelet/bubbletea"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/engineclient"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/messages"
)

/**
 * Login submits one login command through the engine client.
 */
func Login(client engineclient.Service, loginID string, password string) tea.Cmd {
	return func() tea.Msg {
		result, err := client.Login(loginID, password)
		return messages.LoginFinished{
			Result:  result,
			Err:     err,
			LoginID: loginID,
		}
	}
}
