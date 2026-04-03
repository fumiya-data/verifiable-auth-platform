package app

import (
	"fmt"
	"path/filepath"
	"strings"

	"github.com/charmbracelet/lipgloss"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/components"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/types"
)

/**
 * View renders the complete application shell.
 */
func (m Model) View() string {
	content := m.activeScreenView()
	header := strings.Join([]string{
		m.theme.Title("Verifiable Auth Platform"),
		m.theme.Subtitle(fmt.Sprintf("Route: %s | %s", routeTitle(m.route), routeHelp(m.route))),
		m.theme.Muted(fmt.Sprintf("Engine: %s | Data: %s", filepath.Base(m.config.EnginePath), m.config.DataDir)),
	}, "\n")

	body := m.theme.Panel(content)
	status := components.RenderStatusBar(m.theme, m.status, m.busy)
	rendered := lipgloss.JoinVertical(lipgloss.Left, header, "", body, "", status)
	return m.theme.Shell(rendered)
}

func (m Model) activeScreenView() string {
	switch m.route {
	case types.RouteRegister:
		return m.registerScreen.View(m.theme)
	case types.RouteLogin:
		return m.loginScreen.View(m.theme)
	case types.RouteChangePassword:
		return m.changeScreen.View(m.theme)
	case types.RouteAudit:
		return m.auditScreen.View(m.theme, m.width)
	case types.RouteMetrics:
		return m.metricsScreen.View(m.theme)
	default:
		return m.homeScreen.View(m.theme, m.sessionHint)
	}
}
