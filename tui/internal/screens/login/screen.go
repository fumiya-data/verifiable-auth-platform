package login

import (
	"strings"

	tea "github.com/charmbracelet/bubbletea"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/components"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/style"
)

/**
 * Model stores the login form state.
 */
type Model struct {
	form components.Form
}

/**
 * NewModel creates the login screen.
 */
func NewModel(theme style.Theme) Model {
	return Model{
		form: components.NewForm([]components.InputSpec{
			{Label: "Login ID", Placeholder: "alice"},
			{Label: "Password", Placeholder: "secret", Password: true},
		}, "log in", theme),
	}
}

/**
 * Update advances the login form state.
 */
func (m *Model) Update(msg tea.Msg) tea.Cmd {
	return m.form.Update(msg)
}

/**
 * Reset clears the login form.
 */
func (m *Model) Reset() {
	m.form.Reset()
}

/**
 * SetWidth updates the login form width.
 */
func (m *Model) SetWidth(width int) {
	m.form.SetWidth(width)
}

/**
 * Values returns the current login form values.
 */
func (m Model) Values() (string, string) {
	return m.form.Value(0), m.form.Value(1)
}

/**
 * View renders the login screen.
 */
func (m Model) View(theme style.Theme) string {
	return strings.Join([]string{
		theme.Subtitle("Authenticate through the engine's login command."),
		"",
		m.form.View(),
	}, "\n")
}
