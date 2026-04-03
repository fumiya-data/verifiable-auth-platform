package commands

import (
	tea "github.com/charmbracelet/bubbletea"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/engineclient"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/messages"
)

/**
 * ChangePassword submits one change-password command through the engine client.
 */
func ChangePassword(client engineclient.Service, oldPassword string, newPassword string) tea.Cmd {
	return func() tea.Msg {
		result, err := client.ChangePassword(oldPassword, newPassword)
		return messages.ChangePasswordFinished{
			Result: result,
			Err:    err,
		}
	}
}
