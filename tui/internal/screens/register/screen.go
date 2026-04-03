package register

import (
	"strings"

	tea "github.com/charmbracelet/bubbletea"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/components"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/style"
)

/**
 * Model stores the register form state.
 */
type Model struct {
	form components.Form
}

/**
 * NewModel creates the register screen.
 */
func NewModel(theme style.Theme) Model {
	return Model{
		form: components.NewForm([]components.InputSpec{
			{Label: "Login ID", Placeholder: "alice"},
			{Label: "Password", Placeholder: "secret", Password: true},
		}, "register", theme),
	}
}

/**
 * Update advances the register form state.
 */
func (m *Model) Update(msg tea.Msg) tea.Cmd {
	return m.form.Update(msg)
}

/**
 * Reset clears the register form.
 */
func (m *Model) Reset() {
	m.form.Reset()
}

/**
 * SetWidth updates the register form width.
 */
func (m *Model) SetWidth(width int) {
	m.form.SetWidth(width)
}

/**
 * Values returns the current register form values.
 */
func (m Model) Values() (string, string) {
	return m.form.Value(0), m.form.Value(1)
}

/**
 * View renders the register screen.
 */
func (m Model) View(theme style.Theme) string {
	return strings.Join([]string{
		theme.Subtitle("Register a new user through the engine contract."),
		"",
		m.form.View(),
	}, "\n")
}
