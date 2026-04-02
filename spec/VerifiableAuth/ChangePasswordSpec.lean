import VerifiableAuth.LoginSpec

namespace VerifiableAuth

def changePassword (state : AuthState) (oldPassword : Password) (newPassword : Password) :
    Outcome ChangePasswordResult :=
  match state.authenticated with
  | none => { state := state, result := .unauthorized }
  | some loginId =>
      match state.lookupUser? loginId with
      | none => { state := state, result := .systemError }
      | some user =>
          if user.passwordMatches oldPassword then
            let updated := user.changePassword newPassword
            { state := state.replaceUser updated, result := .success }
          else
            { state := state, result := .wrongPassword }

theorem changePassword_preserves_session
    (state : AuthState) (oldPassword newPassword : Password) :
    (changePassword state oldPassword newPassword).state.authenticated = state.authenticated := by
  simp [changePassword, AuthState.replaceUser]

theorem changePassword_unauthorized_is_noop
    (state : AuthState) (oldPassword newPassword : Password)
    (hUnauthenticated : state.authenticated = none) :
    (changePassword state oldPassword newPassword).state = state := by
  simp [changePassword, hUnauthenticated]

theorem user_changePassword_rotates_salt
    (user : User) (newPassword : Password) :
    (user.changePassword newPassword).salt = user.salt.rotate := by
  simp [User.changePassword]

theorem user_changePassword_clears_failures
    (user : User) (newPassword : Password) :
    (user.changePassword newPassword).failedAttempts = 0 ∧
      (user.changePassword newPassword).lockState = .active := by
  simp [User.changePassword]

end VerifiableAuth
