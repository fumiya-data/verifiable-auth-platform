Password Authentication State Machine (engine/ core)
====================================================

Scope
-----
- Focus on one target user account.
- State is the composition of:
  - session state: state.authenticated, state.authenticated_login_id
  - account state: user.lock_state, user.failed_attempts
  - AUTH_LOCKOUT_THRESHOLD = 3

State Definitions
-----------------
[N ] : user does not exist
[U0] : unauthenticated, user exists, lock=ACTIVE, failed_attempts=0
[U1] : unauthenticated, user exists, lock=ACTIVE, failed_attempts=1
[U2] : unauthenticated, user exists, lock=ACTIVE, failed_attempts=2
[UL] : unauthenticated, user exists, lock=LOCKED, failed_attempts>=3
[SA] : authenticated as this user, lock=ACTIVE, failed_attempts=0


Main State Transition Diagram
-----------------------------
```text
┌──────────────────────────┐
│ [N ]                     │
│ Unregistered             │
└─────────────┬────────────┘
  ├─ ↺ login(any) / UNKNOWN_USER
  │     state unchanged
  │
  └─ register / SUCCESS 
              ▼
┌──────────────────────────────────┐
│ [U0]                             │
│ Unauth, Active                   │
│ failed_attempts = 0              │
└─────────────┬────────────────────┘
              ├─ login(wrong)
              │  / WRONG_PASSWORD
              ▼
┌──────────────────────────────────┐
│ [U1]                             │
│ Unauth, Active                   │
│ failed_attempts = 1              │
└─────────────┬────────────────────┘
              ├─ login(wrong)
              │  / WRONG_PASSWORD
              ▼
┌──────────────────────────────────┐
│ [U2]                             │
│ Unauth, Active                   │
│ failed_attempts = 2              │
└─────────────┬────────────────────┘
              ├─ login(wrong)
              │  / LOCKED_OUT
              │  failed_attempts = 3
              │  lock = LOCKED
              ▼
┌──────────────────────────────────┐
│ [UL]                             │
│ Unauth, Locked                   │
│ failed_attempts >= 3             │
└──────────────────────────────────┘
  ↺ login(any) / LOCKED_OUT
    unchanged

[U0], [U1], and [U2]
  └─ login(correct) / SUCCESS
     failed_attempts reset to 0
     session installed
     ▼
┌──────────────────────────────────┐
│ [SA]                             │
│ Authenticated as this user       │
│ lock = ACTIVE                    │
│ failed_attempts = 0              │
└─────────────┬────────────────────┘
              ├─ ↺ login(any) / ALREADY_AUTHENTICATED
              │     unchanged
              ├─ ↺ change_password(wrong old) / WRONG_PASSWORD
              │     unchanged
              ├─ ↺ change_password(correct old, new) / SUCCESS
              │     salt regenerated
              │     password_hash replaced
              │     failed_attempts = 0
              │     lock = ACTIVE
              │     session kept
              └─ logout() / SUCCESS ─────────────────────────► [U0]
                  authenticated = false
```

Login Decision Order (strict)
-----------------------------
auth_login(state, login_id, password)

    1. if state.authenticated == true
         -> ALREADY_AUTHENTICATED
         -> return immediately

    2. user = find_user_mut(state, login_id)
       if user == NULL
         -> UNKNOWN_USER
         -> return

    3. if user.lock_state == LOCKED
         -> LOCKED_OUT
         -> return

    4. if password verification fails
         -> user.failed_attempts += 1
         -> if user.failed_attempts >= 3
              user.lock_state = LOCKED
              return LOCKED_OUT
            else
              return WRONG_PASSWORD

    5. password verification succeeds
         -> user.failed_attempts = 0
         -> state.authenticated = true
         -> state.authenticated_login_id = login_id
         -> return SUCCESS

Notes
-----
  - `ALREADY_AUTHENTICATED` is checked first. If any session is already active,
    `auth_login()` does not continue to `UNKNOWN_USER` or `LOCKED_OUT`.
  - `change_password()` requires an authenticated session, so a locked-out user
    cannot normally recover through password change in this core alone.
  - The `change_password() / SYSTEM_ERROR` branch exists only for a corrupted
    session state where `authenticated_login_id` points to a missing user.

Relevant implementation anchors:
- `engine/src/core/login.c:8`
- `engine/src/core/register.c:9`
- `engine/src/core/change_password.c:9`
- `engine/src/core/state.c:46`
- `engine/include/auth/types.h:25`
- `engine/include/auth/result.h:17`
