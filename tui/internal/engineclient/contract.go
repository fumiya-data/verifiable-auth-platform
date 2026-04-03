package engineclient

/**
 * ResponseError matches the engine JSON `error` object.
 */
type ResponseError struct {
	Message string `json:"message"`
}

/**
 * GetMessage returns the human-readable error message.
 */
func (e *ResponseError) GetMessage() string {
	if e == nil {
		return ""
	}

	return e.Message
}

/**
 * Response wraps one engine JSON response payload.
 */
type Response[T any] struct {
	Ok     bool           `json:"ok"`
	Result string         `json:"result"`
	Data   *T             `json:"data"`
	Error  *ResponseError `json:"error"`
}

/**
 * EmptyData represents commands whose `data` field is `null`.
 */
type EmptyData struct{}

/**
 * AuditEvent matches one engine audit event payload.
 */
type AuditEvent struct {
	Timestamp string `json:"timestamp"`
	EventType string `json:"event_type"`
	LoginID   string `json:"login_id"`
	Result    string `json:"result"`
}

/**
 * AuditData matches the `show-audit` response payload.
 */
type AuditData struct {
	Events []AuditEvent `json:"events"`
}

/**
 * MetricsData matches the `show-metrics` response payload.
 */
type MetricsData struct {
	LoginSuccessCount int `json:"login_success_count"`
	LoginFailureCount int `json:"login_failure_count"`
	LockoutCount      int `json:"lockout_count"`
}

/**
 * CommandResult captures one decoded engine invocation.
 */
type CommandResult[T any] struct {
	Response Response[T]
	ExitCode int
	Stderr   string
}
