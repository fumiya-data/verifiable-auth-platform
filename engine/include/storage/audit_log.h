#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_STORAGE_AUDIT_LOG_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_STORAGE_AUDIT_LOG_H

#include <stddef.h>
#include <stdint.h>

#include "auth/types.h"

/** Maximum number of audit events loaded into memory at once. */
#define STORAGE_AUDIT_MAX_EVENTS 1024u
/** Width of one serialized UTC timestamp including the terminating '\0'. */
#define STORAGE_AUDIT_TIMESTAMP_LENGTH 21u
/** Width of one serialized result code including the terminating '\0'. */
#define STORAGE_AUDIT_RESULT_LENGTH 32u

/**
 * @brief Stable audit event kinds exposed by the observability model.
 */
typedef enum storage_audit_event_type {
    STORAGE_AUDIT_EVENT_TYPE_REGISTER = 0,
    STORAGE_AUDIT_EVENT_TYPE_LOGIN_SUCCESS,
    STORAGE_AUDIT_EVENT_TYPE_LOGIN_FAILURE,
    STORAGE_AUDIT_EVENT_TYPE_LOCK,
    STORAGE_AUDIT_EVENT_TYPE_PASSWORD_CHANGE,
    STORAGE_AUDIT_EVENT_TYPE_LOGOUT,
} storage_audit_event_type_t;

/**
 * @brief One persisted audit record.
 */
typedef struct storage_audit_event {
    /** UTC timestamp in ISO-8601 basic engine format. */
    char timestamp[STORAGE_AUDIT_TIMESTAMP_LENGTH];
    /** Stable event category used by observability and analysis layers. */
    storage_audit_event_type_t event_type;
    /** Login ID associated with the recorded operation. */
    char login_id[AUTH_LOGIN_ID_MAX_LENGTH + 1u];
    /** Stable machine-readable result code recorded for the event. */
    char result[STORAGE_AUDIT_RESULT_LENGTH];
} storage_audit_event_t;

/**
 * @brief In-memory collection of audit events.
 */
typedef struct storage_audit_log {
    /** Loaded audit events in file order. */
    storage_audit_event_t events[STORAGE_AUDIT_MAX_EVENTS];
    /** Number of populated entries in @p events. */
    size_t event_count;
} storage_audit_log_t;

/**
 * @brief Aggregate metrics derived from audit events.
 */
typedef struct storage_metrics {
    /** Number of recorded successful login events. */
    uint32_t login_success_count;
    /** Number of recorded login failures that count toward the metric. */
    uint32_t login_failure_count;
    /** Number of lockout-causing login events. */
    uint32_t lockout_count;
} storage_metrics_t;

/**
 * @brief Stable status codes returned by the audit log adapter.
 */
typedef enum storage_audit_log_status {
    /** The requested operation completed successfully. */
    STORAGE_AUDIT_LOG_STATUS_OK = 0,
    /** One or more required arguments were nullptr or otherwise invalid. */
    STORAGE_AUDIT_LOG_STATUS_INVALID_ARGUMENT,
    /** The persisted representation could not be parsed as valid audit data. */
    STORAGE_AUDIT_LOG_STATUS_PARSE_ERROR,
    /** The underlying file operation failed. */
    STORAGE_AUDIT_LOG_STATUS_IO_ERROR,
} storage_audit_log_status_t;

/**
 * @brief Append one audit event to the persisted audit log.
 *
 * @param path Destination audit log path.
 * @param event_type Stable audit event type to record.
 * @param login_id Login ID associated with the event.
 * @param result Stable result code associated with the event.
 * @return Status describing success or file I/O failure.
 */
storage_audit_log_status_t storage_audit_log_append(const char *path,
                                                    storage_audit_event_type_t event_type,
                                                    const char *login_id,
                                                    const char *result);

/**
 * @brief Load the persisted audit log into memory.
 *
 * @param path Path to the persisted audit log file.
 * @param log In-memory log structure to populate.
 * @return Status describing success, parse failure, or file I/O failure.
 */
storage_audit_log_status_t storage_audit_log_load(const char *path, storage_audit_log_t *log);

/**
 * @brief Derive aggregate metrics from an in-memory audit log.
 *
 * @param log In-memory audit log to aggregate, or nullptr for an empty input.
 * @param metrics Output structure receiving the derived counters.
 */
void storage_audit_log_compute_metrics(const storage_audit_log_t *log, storage_metrics_t *metrics);

/**
 * @brief Convert an audit event type to its stable serialized name.
 *
 * @param event_type Audit event type to serialize.
 * @return Stable string literal for file and JSON output.
 */
const char *storage_audit_event_type_string(storage_audit_event_type_t event_type);

/**
 * @brief Convert an audit log status code to a stable string.
 *
 * @param status Audit log status code.
 * @return Stable string literal for diagnostics and JSON serialization.
 */
const char *storage_audit_log_status_string(storage_audit_log_status_t status);

#endif
