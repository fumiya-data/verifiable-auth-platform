package app

import (
	"fmt"
	"strings"

	tea "github.com/charmbracelet/bubbletea"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/commands"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/messages"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/types"
)

/**
 * Update advances the routed application state.
 */
func (m Model) Update(msg tea.Msg) (tea.Model, tea.Cmd) {
	switch typed := msg.(type) {
	case tea.WindowSizeMsg:
		m.width = typed.Width
		m.height = typed.Height
		m.registerScreen.SetWidth(maxInt(24, typed.Width/2))
		m.loginScreen.SetWidth(maxInt(24, typed.Width/2))
		m.changeScreen.SetWidth(maxInt(24, typed.Width/2))
		return m, nil
	case messages.RegisterFinished:
		m.busy = false
		if typed.Err != nil {
			m.status = transportStatus("register", typed.Err)
			return m, nil
		}

		m.status = responseStatus("register", typed.Result.Response.Ok, typed.Result.Response.Result, typed.Result.Response.Error)
		if typed.Result.Response.Ok {
			m.registerScreen.Reset()
			m.navigate(types.RouteHome)
		}

		return m, nil
	case messages.LoginFinished:
		m.busy = false
		if typed.Err != nil {
			m.status = transportStatus("login", typed.Err)
			return m, nil
		}

		m.status = responseStatus("login", typed.Result.Response.Ok, typed.Result.Response.Result, typed.Result.Response.Error)
		if typed.Result.Response.Ok {
			m.sessionHint = types.SessionHint{
				Authenticated: true,
				LoginID:       typed.LoginID,
			}
			m.loginScreen.Reset()
			m.navigate(types.RouteHome)
		}

		return m, nil
	case messages.ChangePasswordFinished:
		m.busy = false
		if typed.Err != nil {
			m.status = transportStatus("change-password", typed.Err)
			return m, nil
		}

		m.status = responseStatus("change-password", typed.Result.Response.Ok, typed.Result.Response.Result, typed.Result.Response.Error)
		if typed.Result.Response.Ok {
			m.changeScreen.Reset()
			m.navigate(types.RouteHome)
		}

		return m, nil
	case messages.LogoutFinished:
		m.busy = false
		if typed.Err != nil {
			m.status = transportStatus("logout", typed.Err)
			return m, nil
		}

		m.status = responseStatus("logout", typed.Result.Response.Ok, typed.Result.Response.Result, typed.Result.Response.Error)
		if typed.Result.Response.Ok {
			m.sessionHint = types.SessionHint{}
		}

		return m, nil
	case messages.AuditLoaded:
		m.busy = false
		if typed.Err != nil {
			m.status = transportStatus("show-audit", typed.Err)
			return m, nil
		}

		m.status = responseStatus("show-audit", typed.Result.Response.Ok, typed.Result.Response.Result, typed.Result.Response.Error)
		if typed.Result.Response.Ok && typed.Result.Response.Data != nil {
			m.auditScreen.SetEvents(typed.Result.Response.Data.Events)
		}

		return m, nil
	case messages.MetricsLoaded:
		m.busy = false
		if typed.Err != nil {
			m.status = transportStatus("show-metrics", typed.Err)
			return m, nil
		}

		m.status = responseStatus("show-metrics", typed.Result.Response.Ok, typed.Result.Response.Result, typed.Result.Response.Error)
		if typed.Result.Response.Ok && typed.Result.Response.Data != nil {
			m.metricsScreen.SetMetrics(*typed.Result.Response.Data)
		}

		return m, nil
	case tea.KeyMsg:
		if typed.String() == "ctrl+c" {
			return m, tea.Quit
		}

		if typed.String() == "q" && (m.route == types.RouteHome || m.route == types.RouteAudit || m.route == types.RouteMetrics) {
			return m, tea.Quit
		}

		if m.busy {
			return m, nil
		}

		return m.handleKey(typed)
	}

	return m, nil
}

func (m Model) handleKey(msg tea.KeyMsg) (tea.Model, tea.Cmd) {
	switch m.route {
	case types.RouteHome:
		selection, confirmed := m.homeScreen.Update(msg)
		if !confirmed {
			return m, nil
		}

		switch selection {
		case types.HomeSelectionRegister:
			m.navigate(types.RouteRegister)
		case types.HomeSelectionLogin:
			m.navigate(types.RouteLogin)
		case types.HomeSelectionChangePassword:
			m.navigate(types.RouteChangePassword)
		case types.HomeSelectionLogout:
			m.busy = true
			m.status = types.Status{Level: types.StatusLevelInfo, Message: "Running logout"}
			return m, commands.Logout(m.client)
		case types.HomeSelectionAudit:
			m.navigate(types.RouteAudit)
			m.busy = true
			m.status = types.Status{Level: types.StatusLevelInfo, Message: "Loading audit log"}
			return m, commands.LoadAudit(m.client)
		case types.HomeSelectionMetrics:
			m.navigate(types.RouteMetrics)
			m.busy = true
			m.status = types.Status{Level: types.StatusLevelInfo, Message: "Loading metrics"}
			return m, commands.LoadMetrics(m.client)
		case types.HomeSelectionQuit:
			return m, tea.Quit
		}

		return m, nil
	case types.RouteRegister:
		if msg.String() == "esc" {
			m.navigate(types.RouteHome)
			return m, nil
		}

		if msg.String() == "enter" {
			loginID, password := m.registerScreen.Values()
			m.busy = true
			m.status = types.Status{Level: types.StatusLevelInfo, Message: "Running register"}
			return m, commands.Register(m.client, loginID, password)
		}

		return m, m.registerScreen.Update(msg)
	case types.RouteLogin:
		if msg.String() == "esc" {
			m.navigate(types.RouteHome)
			return m, nil
		}

		if msg.String() == "enter" {
			loginID, password := m.loginScreen.Values()
			m.busy = true
			m.status = types.Status{Level: types.StatusLevelInfo, Message: "Running login"}
			return m, commands.Login(m.client, loginID, password)
		}

		return m, m.loginScreen.Update(msg)
	case types.RouteChangePassword:
		if msg.String() == "esc" {
			m.navigate(types.RouteHome)
			return m, nil
		}

		if msg.String() == "enter" {
			oldPassword, newPassword := m.changeScreen.Values()
			m.busy = true
			m.status = types.Status{Level: types.StatusLevelInfo, Message: "Running change-password"}
			return m, commands.ChangePassword(m.client, oldPassword, newPassword)
		}

		return m, m.changeScreen.Update(msg)
	case types.RouteAudit:
		if msg.String() == "esc" {
			m.navigate(types.RouteHome)
			return m, nil
		}

		if msg.String() == "r" {
			m.busy = true
			m.status = types.Status{Level: types.StatusLevelInfo, Message: "Reloading audit log"}
			return m, commands.LoadAudit(m.client)
		}

		m.auditScreen.Update(msg)
		return m, nil
	case types.RouteMetrics:
		if msg.String() == "esc" {
			m.navigate(types.RouteHome)
			return m, nil
		}

		if msg.String() == "r" {
			m.busy = true
			m.status = types.Status{Level: types.StatusLevelInfo, Message: "Reloading metrics"}
			return m, commands.LoadMetrics(m.client)
		}
	}

	return m, nil
}

func transportStatus(command string, err error) types.Status {
	return types.Status{
		Level:   types.StatusLevelError,
		Message: fmt.Sprintf("%s transport error: %v", command, err),
	}
}

func responseStatus(command string, ok bool, result string, responseError interface{ GetMessage() string }) types.Status {
	level := types.StatusLevelSuccess
	if !ok {
		level = types.StatusLevelWarning
		if result == "system_error" || result == "invalid_request" {
			level = types.StatusLevelError
		}
	}

	message := fmt.Sprintf("%s -> %s", command, strings.ReplaceAll(humanizeResult(result), "_", " "))
	if responseError != nil && responseError.GetMessage() != "" {
		message = fmt.Sprintf("%s (%s)", message, responseError.GetMessage())
	}

	return types.Status{
		Level:   level,
		Message: message,
	}
}

func maxInt(left int, right int) int {
	if left > right {
		return left
	}

	return right
}
