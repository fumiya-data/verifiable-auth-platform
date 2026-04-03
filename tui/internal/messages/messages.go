package messages

import "github.com/fumiya-data/verifiable-auth-platform/tui/internal/engineclient"

/**
 * RegisterFinished reports the completion of one register command.
 */
type RegisterFinished struct {
	Result  engineclient.CommandResult[engineclient.EmptyData]
	Err     error
	LoginID string
}

/**
 * LoginFinished reports the completion of one login command.
 */
type LoginFinished struct {
	Result  engineclient.CommandResult[engineclient.EmptyData]
	Err     error
	LoginID string
}

/**
 * ChangePasswordFinished reports the completion of one change-password command.
 */
type ChangePasswordFinished struct {
	Result engineclient.CommandResult[engineclient.EmptyData]
	Err    error
}

/**
 * LogoutFinished reports the completion of one logout command.
 */
type LogoutFinished struct {
	Result engineclient.CommandResult[engineclient.EmptyData]
	Err    error
}

/**
 * AuditLoaded reports the completion of one show-audit command.
 */
type AuditLoaded struct {
	Result engineclient.CommandResult[engineclient.AuditData]
	Err    error
}

/**
 * MetricsLoaded reports the completion of one show-metrics command.
 */
type MetricsLoaded struct {
	Result engineclient.CommandResult[engineclient.MetricsData]
	Err    error
}
