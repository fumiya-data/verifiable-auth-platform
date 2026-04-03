import VerifiableAuth.WellFormed

namespace VerifiableAuth

def register (state : AuthState) (loginId : LoginId) (password : Password) :
    Outcome RegisterResult :=
  match state.lookupUser? loginId with
  | some _ => { state := state, result := .duplicate }
  | none =>
      let created := mkRegisteredUser loginId password
      { state := state.insertUser created, result := .success }

theorem register_preserves_session
    (state : AuthState) (loginId : LoginId) (password : Password) :
    (register state loginId password).state.authenticated = state.authenticated := by
  unfold register
  split <;> rfl

theorem register_success_initializes_active_user
    (loginId : LoginId) (password : Password) :
    let created := mkRegisteredUser loginId password
    created.failedAttempts = 0 ∧ created.lockState = .active := by
  simp [mkRegisteredUser]

end VerifiableAuth
