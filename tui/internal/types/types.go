package types

/**
 * Route identifies one top-level TUI screen.
 */
type Route string

const (
	// RouteHome shows the main action menu.
	RouteHome Route = "home"
	// RouteRegister shows the registration form.
	RouteRegister Route = "register"
	// RouteLogin shows the login form.
	RouteLogin Route = "login"
	// RouteChangePassword shows the password change form.
	RouteChangePassword Route = "change-password"
	// RouteAudit shows the audit event list.
	RouteAudit Route = "audit"
	// RouteMetrics shows derived metrics.
	RouteMetrics Route = "metrics"
)

/**
 * AppConfig stores runtime configuration for the TUI process.
 */
type AppConfig struct {
	EnginePath string
	DataDir    string
}

/**
 * StatusLevel classifies one user-visible status message.
 */
type StatusLevel string

const (
	// StatusLevelInfo marks neutral status messages.
	StatusLevelInfo StatusLevel = "info"
	// StatusLevelSuccess marks successful outcomes.
	StatusLevelSuccess StatusLevel = "success"
	// StatusLevelWarning marks expected domain-level failures.
	StatusLevelWarning StatusLevel = "warning"
	// StatusLevelError marks transport or runtime failures.
	StatusLevelError StatusLevel = "error"
)

/**
 * Status stores the latest user-visible application status.
 */
type Status struct {
	Level   StatusLevel
	Message string
}

/**
 * SessionHint stores the latest session state known by the TUI.
 *
 * The engine remains the authority; this is only presentation state.
 */
type SessionHint struct {
	Authenticated bool
	LoginID       string
}

/**
 * HomeSelection identifies one home-screen action.
 */
type HomeSelection string

const (
	// HomeSelectionRegister routes to the register screen.
	HomeSelectionRegister HomeSelection = "register"
	// HomeSelectionLogin routes to the login screen.
	HomeSelectionLogin HomeSelection = "login"
	// HomeSelectionChangePassword routes to the password change screen.
	HomeSelectionChangePassword HomeSelection = "change-password"
	// HomeSelectionLogout executes logout immediately.
	HomeSelectionLogout HomeSelection = "logout"
	// HomeSelectionAudit routes to the audit screen.
	HomeSelectionAudit HomeSelection = "audit"
	// HomeSelectionMetrics routes to the metrics screen.
	HomeSelectionMetrics HomeSelection = "metrics"
	// HomeSelectionQuit exits the TUI.
	HomeSelectionQuit HomeSelection = "quit"
)
