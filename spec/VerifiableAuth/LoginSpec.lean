import VerifiableAuth.RegisterSpec

namespace VerifiableAuth

def login (state : AuthState) (loginId : LoginId) (password : Password) :
    Outcome LoginResult :=
  match state.authenticated with
  | some _ => { state := state, result := .alreadyAuthenticated }
  | none =>
      match state.lookupUser? loginId with
      | none => { state := state, result := .unknownUser }
      | some user =>
          if user.lockState = .locked then
            { state := state, result := .lockedOut }
          else if user.passwordMatches password then
            let updated := user.clearFailedAttempts
            let nextState := (state.replaceUser updated).setAuthenticated loginId
            { state := nextState, result := .success }
          else
            let updated := user.noteFailedLogin
            let result : LoginResult :=
              if updated.lockState = .locked then .lockedOut else .wrongPassword
            { state := state.replaceUser updated, result := result }

theorem login_already_authenticated_is_noop
    (state : AuthState) (current : LoginId) (loginId : LoginId) (password : Password)
    (hAuthenticated : state.authenticated = some current) :
    (login state loginId password).state = state := by
  simp [login, hAuthenticated]

theorem login_unknown_user_keeps_state
    (state : AuthState) (loginId : LoginId) (password : Password)
    (hUnauthenticated : state.authenticated = none)
    (hMissing : state.lookupUser? loginId = none) :
    (login state loginId password).state = state := by
  simp [login, hUnauthenticated, hMissing]

theorem login_success_sets_authenticated
    (state : AuthState) (loginId : LoginId) (password : Password) (user : User)
    (hUnauthenticated : state.authenticated = none)
    (hUser : state.lookupUser? loginId = some user)
    (hUnlocked : user.lockState = .active)
    (hPassword : user.passwordMatches password) :
    (login state loginId password).state.authenticated = some loginId := by
  simp [login, hUnauthenticated, hUser, hUnlocked, hPassword, AuthState.replaceUser,
    AuthState.setAuthenticated]

end VerifiableAuth
