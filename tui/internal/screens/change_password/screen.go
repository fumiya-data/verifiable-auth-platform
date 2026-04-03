package change_password

import (
	"strings"

	tea "github.com/charmbracelet/bubbletea"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/components"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/style"
)

/**
 * Model stores the password-change form state.
 */
type Model struct {
	form components.Form
}

/**
 * NewModel creates the change-password screen.
 */
func NewModel(theme style.Theme) Model {
	return Model{
		form: components.NewForm([]components.InputSpec{
			{Label: "Old Password", Placeholder: "current password", Password: true},
			{Label: "New Password", Placeholder: "new password", Password: true},
		}, "change the password", theme),
	}
}

/**
 * Update advances the password-change form state.
 */
func (m *Model) Update(msg tea.Msg) tea.Cmd {
	return m.form.Update(msg)
}

/**
 * Reset clears the password-change form.
 */
func (m *Model) Reset() {
	m.form.Reset()
}

/**
 * SetWidth updates the password-change form width.
 */
func (m *Model) SetWidth(width int) {
	m.form.SetWidth(width)
}

/**
 * Values returns the current password-change form values.
 */
func (m Model) Values() (string, string) {
	return m.form.Value(0), m.form.Value(1)
}

/**
 * View renders the change-password screen.
 */
func (m Model) View(theme style.Theme) string {
	return strings.Join([]string{
		theme.Subtitle("Rotate the password for the current authenticated user."),
		"",
		m.form.View(),
	}, "\n")
}
