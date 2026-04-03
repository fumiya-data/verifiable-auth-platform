package app

import (
	tea "github.com/charmbracelet/bubbletea"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/engineclient"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/screens/audit"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/screens/change_password"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/screens/home"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/screens/login"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/screens/metrics"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/screens/register"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/style"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/types"
)

/**
 * Model is the routed Bubble Tea application model.
 */
type Model struct {
	config             types.AppConfig
	client             engineclient.Service
	theme              style.Theme
	route              types.Route
	width              int
	height             int
	status             types.Status
	busy               bool
	sessionHint        types.SessionHint
	homeScreen         home.Model
	registerScreen     register.Model
	loginScreen        login.Model
	changeScreen       change_password.Model
	auditScreen        audit.Model
	metricsScreen      metrics.Model
}

/**
 * NewModel builds the root application model.
 */
func NewModel(config types.AppConfig, client engineclient.Service) Model {
	theme := style.DefaultTheme()
	return Model{
		config:         config,
		client:         client,
		theme:          theme,
		route:          types.RouteHome,
		status:         types.Status{Level: types.StatusLevelInfo, Message: "Ready"},
		homeScreen:     home.NewModel(),
		registerScreen: register.NewModel(theme),
		loginScreen:    login.NewModel(theme),
		changeScreen:   change_password.NewModel(theme),
		auditScreen:    audit.NewModel(),
		metricsScreen:  metrics.NewModel(),
	}
}

/**
 * Init satisfies the Bubble Tea model contract.
 */
func (m Model) Init() tea.Cmd {
	return nil
}
