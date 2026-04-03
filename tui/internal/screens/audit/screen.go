package audit

import (
	"strings"

	tea "github.com/charmbracelet/bubbletea"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/components"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/engineclient"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/style"
)

/**
 * Model stores the audit-screen selection state and current events.
 */
type Model struct {
	events   []engineclient.AuditEvent
	selected int
	loaded   bool
}

/**
 * NewModel creates the audit screen.
 */
func NewModel() Model {
	return Model{}
}

/**
 * SetEvents replaces the rendered audit events.
 */
func (m *Model) SetEvents(events []engineclient.AuditEvent) {
	m.events = append(m.events[:0], events...)
	m.loaded = true
	if len(m.events) == 0 {
		m.selected = 0
		return
	}

	if m.selected >= len(m.events) {
		m.selected = len(m.events) - 1
	}
}

/**
 * Update advances the audit-row selection.
 */
func (m *Model) Update(msg tea.KeyMsg) {
	if len(m.events) == 0 {
		return
	}

	switch msg.String() {
	case "up", "k":
		m.selected = (m.selected - 1 + len(m.events)) % len(m.events)
	case "down", "j":
		m.selected = (m.selected + 1) % len(m.events)
	}
}

/**
 * View renders the audit screen.
 */
func (m Model) View(theme style.Theme, width int) string {
	if !m.loaded {
		return strings.Join([]string{
			theme.Subtitle("Load the audit log from the engine."),
			"",
			theme.Muted("Waiting for audit data. Press r to reload."),
		}, "\n")
	}

	rows := make([][]string, len(m.events))
	for index, event := range m.events {
		rows[index] = []string{
			event.Timestamp,
			event.EventType,
			event.LoginID,
			event.Result,
		}
	}

	return strings.Join([]string{
		theme.Subtitle("Audit events as recorded by the engine."),
		"",
		components.RenderTable(theme, []string{"timestamp", "event_type", "login_id", "result"}, rows, m.selected, width),
		"",
		theme.Muted("Use Up/Down or j/k to inspect rows. Press r to reload."),
	}, "\n")
}
