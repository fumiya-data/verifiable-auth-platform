import VerifiableAuth.WellFormed

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
  unfold changePassword
  split <;> try rfl
  split <;> try rfl
  split <;> rfl

theorem changePassword_unauthorized_is_noop
    (state : AuthState) (oldPassword newPassword : Password)
    (hUnauthenticated : state.authenticated = none) :
    (changePassword state oldPassword newPassword).state = state := by
  simp [changePassword, hUnauthenticated]

theorem user_changePassword_rotates_salt
    (user : User) (newPassword : Password) :
    (user.changePassword newPassword).salt = user.salt.rotate := by
  simp [User.changePassword, User.salt]

theorem user_changePassword_clears_failures
    (user : User) (newPassword : Password) :
    (user.changePassword newPassword).failedAttempts = 0 ∧
      (user.changePassword newPassword).lockState = .active := by
  simp [User.changePassword]

theorem changePassword_success_requires_authenticated_matching_password
    (state : AuthState) (oldPassword newPassword : Password)
    (hSuccess : (changePassword state oldPassword newPassword).result = .success) :
    ∃ loginId user,
      state.authenticated = some loginId ∧
      state.lookupUser? loginId = some user ∧
      user.passwordMatches oldPassword := by
  cases hAuth : state.authenticated with
  | none =>
      simp [changePassword, hAuth] at hSuccess
  | some loginId =>
      cases hLookup : state.lookupUser? loginId with
      | none =>
          simp [changePassword, hAuth, hLookup] at hSuccess
      | some user =>
          by_cases hPassword : user.passwordMatches oldPassword
          · exact ⟨loginId, user, rfl, hLookup, hPassword⟩
          · simp [changePassword, hAuth, hLookup, hPassword] at hSuccess

end VerifiableAuth
