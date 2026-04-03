package home

import (
	"fmt"
	"strings"

	tea "github.com/charmbracelet/bubbletea"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/style"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/types"
)

type menuItem struct {
	selection types.HomeSelection
	label     string
	detail    string
}

var menuItems = []menuItem{
	{selection: types.HomeSelectionRegister, label: "Register", detail: "Create a new account without altering the current session."},
	{selection: types.HomeSelectionLogin, label: "Login", detail: "Authenticate with login_id and password."},
	{selection: types.HomeSelectionChangePassword, label: "Change Password", detail: "Rotate the current authenticated user's password."},
	{selection: types.HomeSelectionLogout, label: "Logout", detail: "Clear the current single-session authentication state."},
	{selection: types.HomeSelectionAudit, label: "Show Audit", detail: "Inspect the structured audit event sequence."},
	{selection: types.HomeSelectionMetrics, label: "Show Metrics", detail: "Inspect aggregate login and lockout counters."},
	{selection: types.HomeSelectionQuit, label: "Quit", detail: "Exit the TUI."},
}

/**
 * Model stores home-screen navigation state.
 */
type Model struct {
	selected int
}

/**
 * NewModel creates the home-screen model.
 */
func NewModel() Model {
	return Model{}
}

/**
 * Update advances the selected home-menu item and reports a confirmed action.
 */
func (m *Model) Update(msg tea.KeyMsg) (types.HomeSelection, bool) {
	switch msg.String() {
	case "up", "k":
		m.selected = (m.selected - 1 + len(menuItems)) % len(menuItems)
	case "down", "j":
		m.selected = (m.selected + 1) % len(menuItems)
	case "enter":
		return menuItems[m.selected].selection, true
	}

	return "", false
}

/**
 * View renders the home screen and current session hint.
 */
func (m Model) View(theme style.Theme, session types.SessionHint) string {
	lines := []string{
		theme.Subtitle("Choose an engine-backed operation."),
		"",
	}

	if session.Authenticated {
		lines = append(lines, theme.Success(fmt.Sprintf("Session: authenticated as %s", session.LoginID)))
	} else {
		lines = append(lines, theme.Muted("Session: unauthenticated"))
	}

	lines = append(lines, "")
	for index, item := range menuItems {
		lines = append(lines, theme.MenuItemStyle(index == m.selected).Render(item.label))
		lines = append(lines, theme.Muted(item.detail))
		lines = append(lines, "")
	}

	lines = append(lines, theme.Muted("Use Up/Down or j/k to move. Press Enter to run the selected action."))
	return strings.Join(lines, "\n")
}
