package app

import (
	"fmt"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/types"
)

func (m *Model) navigate(route types.Route) {
	m.route = route
	switch route {
	case types.RouteRegister:
		m.registerScreen.Reset()
	case types.RouteLogin:
		m.loginScreen.Reset()
	case types.RouteChangePassword:
		m.changeScreen.Reset()
	}
}

func routeTitle(route types.Route) string {
	switch route {
	case types.RouteRegister:
		return "Register"
	case types.RouteLogin:
		return "Login"
	case types.RouteChangePassword:
		return "Change Password"
	case types.RouteAudit:
		return "Audit"
	case types.RouteMetrics:
		return "Metrics"
	default:
		return "Home"
	}
}

func routeHelp(route types.Route) string {
	switch route {
	case types.RouteAudit, types.RouteMetrics:
		return "Esc back | r reload | q quit"
	case types.RouteHome:
		return "Enter select | q quit"
	default:
		return "Enter submit | Esc back | Ctrl+C quit"
	}
}

func humanizeResult(result string) string {
	switch result {
	case "":
		return "unknown result"
	default:
		return fmt.Sprintf("%s", result)
	}
}
