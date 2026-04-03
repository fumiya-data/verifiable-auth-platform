package components

import (
	"strings"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/style"
)

/**
 * RenderModal renders a simple modal-like box.
 */
func RenderModal(theme style.Theme, title string, body string) string {
	return theme.Modal(strings.Join([]string{
		theme.Title(title),
		"",
		body,
	}, "\n"))
}
