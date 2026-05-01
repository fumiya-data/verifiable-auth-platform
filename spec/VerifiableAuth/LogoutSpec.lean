import VerifiableAuth.StateModel

namespace VerifiableAuth

def logout (state : AuthState) : Outcome LogoutResult :=
  { state := state.clearSession, result := .success }

theorem logout_preserves_users (state : AuthState) :
    (logout state).state.users = state.users := by
  simp [logout, AuthState.clearSession]

theorem logout_clears_session (state : AuthState) :
    (logout state).state.authenticated = none := by
  simp [logout, AuthState.clearSession]

end VerifiableAuth
