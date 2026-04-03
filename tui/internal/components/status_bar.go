package components

import (
	"fmt"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/style"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/types"
)

/**
 * RenderStatusBar renders the bottom status line for the app shell.
 */
func RenderStatusBar(theme style.Theme, status types.Status, busy bool) string {
	label := "[idle]"
	if busy {
		label = "[busy]"
	}

	if status.Message == "" {
		return fmt.Sprintf("%s %s", theme.Muted(label), theme.Muted("Ready"))
	}

	return fmt.Sprintf("%s %s", theme.Muted(label), theme.StatusStyle(status.Level).Render(status.Message))
}
