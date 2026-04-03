package metrics

import (
	"fmt"
	"strings"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/engineclient"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/style"
)

/**
 * Model stores the latest metrics payload.
 */
type Model struct {
	metrics engineclient.MetricsData
	loaded  bool
}

/**
 * NewModel creates the metrics screen.
 */
func NewModel() Model {
	return Model{}
}

/**
 * SetMetrics replaces the rendered metrics payload.
 */
func (m *Model) SetMetrics(metrics engineclient.MetricsData) {
	m.metrics = metrics
	m.loaded = true
}

/**
 * View renders the metrics screen.
 */
func (m Model) View(theme style.Theme) string {
	if !m.loaded {
		return strings.Join([]string{
			theme.Subtitle("Load the derived metrics from the engine."),
			"",
			theme.Muted("Waiting for metrics data. Press r to reload."),
		}, "\n")
	}

	return strings.Join([]string{
		theme.Subtitle("Derived metrics computed from the engine audit log."),
		"",
		fmt.Sprintf("%s %d", theme.Accent("login_success_count:"), m.metrics.LoginSuccessCount),
		fmt.Sprintf("%s %d", theme.Accent("login_failure_count:"), m.metrics.LoginFailureCount),
		fmt.Sprintf("%s %d", theme.Accent("lockout_count:"), m.metrics.LockoutCount),
		"",
		theme.Muted("Press r to reload."),
	}, "\n")
}
