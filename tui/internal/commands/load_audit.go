package commands

import (
	tea "github.com/charmbracelet/bubbletea"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/engineclient"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/messages"
)

/**
 * LoadAudit submits one show-audit command through the engine client.
 */
func LoadAudit(client engineclient.Service) tea.Cmd {
	return func() tea.Msg {
		result, err := client.ShowAudit()
		return messages.AuditLoaded{
			Result: result,
			Err:    err,
		}
	}
}
