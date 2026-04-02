#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_AUTH_TYPES_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_AUTH_TYPES_H

#include <stddef.h>
#include <stdint.h>

#include "crypto/hash_adapter.h"
#include "crypto/salt_adapter.h"

/**
 * @brief Maximum length, excluding the terminating '\0', for a login
 *        identifier stored in core state.
 */
#define AUTH_LOGIN_ID_MAX_LENGTH 64u
/**
 * @brief Maximum length, excluding the terminating '\0', for a password
 *        accepted by the current core implementation.
 */
#define AUTH_PASSWORD_MAX_LENGTH 128u
/**
 * @brief Maximum number of in-memory users supported by the current core state.
 */
#define AUTH_MAX_USERS 128u
/**
 * @brief Number of failed login attempts that triggers a lockout.
 */
#define AUTH_LOCKOUT_THRESHOLD 3u

/**
 * @brief Account lock state as described by the system specification.
 */
typedef enum auth_lock_state {
    /** The user may attempt to authenticate normally. */
    AUTH_LOCK_STATE_ACTIVE = 0,
    /** The user is locked and cannot authenticate successfully. */
    AUTH_LOCK_STATE_LOCKED,
} auth_lock_state_t;

/**
 * @brief In-memory user record managed by the core state transition functions.
 */
typedef struct auth_user {
    /** Stable unique identifier used during login. */
    char login_id[AUTH_LOGIN_ID_MAX_LENGTH + 1u];
    /** Lowercase hexadecimal salt string. */
    char salt[AUTH_SALT_ENCODED_LENGTH];
    /** Lowercase hexadecimal PBKDF2-HMAC-SHA256 hash string. */
    char password_hash[AUTH_HASH_ENCODED_LENGTH];
    /** Consecutive failed login attempts for this account. */
    uint32_t failed_attempts;
    /** Current lock state derived from failed attempts. */
    auth_lock_state_t lock_state;
} auth_user_t;

#endif
