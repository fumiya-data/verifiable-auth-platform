import VerifiableAuth.LogoutSpec

namespace VerifiableAuth

/--
I-01 and I-03 are construction invariants in this model:
- plaintext passwords exist only as operation inputs;
- user records store symbolic salts and digests;
- register/change-password are the only constructors for credential material.
-/
def ConstructionInvariants (state : AuthState) : Prop :=
  state.CredentialsBound

def I02_UniqueLoginIds (state : AuthState) : Prop :=
  UniqueLoginIds state.users

def I05_LockStateTracksThreshold (state : AuthState) : Prop :=
  UsersWellFormed state.users

def I11_SessionIsOptionalLoginId (state : AuthState) : Prop :=
  state.SessionConsistent

def I13_WellFormed (state : AuthState) : Prop :=
  state.WellFormed

def CoreInvariants (state : AuthState) : Prop :=
  ConstructionInvariants state ∧
    I02_UniqueLoginIds state ∧
    I05_LockStateTracksThreshold state ∧
    I11_SessionIsOptionalLoginId state ∧
    I13_WellFormed state

theorem register_keeps_session_shape
    (state : AuthState) (loginId : LoginId) (password : Password)
    (hSession : I11_SessionIsOptionalLoginId state) :
    I11_SessionIsOptionalLoginId (register state loginId password).state := by
  unfold I11_SessionIsOptionalLoginId at hSession ⊢
  have hPreserve := register_preserves_session state loginId password
  cases hAuth : state.authenticated with
  | none =>
      rw [hAuth] at hPreserve
      simp [AuthState.SessionConsistent, hPreserve]
  | some authLoginId =>
      simp [AuthState.SessionConsistent, hAuth] at hSession
      rcases hSession with ⟨user, hFound⟩
      rw [AuthState.SessionConsistent, hPreserve]
      simp [hAuth]
      cases hExisting : state.lookupUser? loginId with
      | some existing =>
          simp [register, hExisting]
          exact ⟨user, hFound⟩
      | none =>
          simp [register, hExisting]
          exact ⟨user,
            AuthState.lookupUser?_insertUser_of_found
              state
              authLoginId
              user
              (mkRegisteredUser loginId password)
              hFound⟩

theorem register_preserves_construction_invariants
    (state : AuthState) (loginId : LoginId) (password : Password)
    (hConstruction : ConstructionInvariants state) :
    ConstructionInvariants (register state loginId password).state := by
  unfold ConstructionInvariants at hConstruction ⊢
  simp [register]
  split
  · simpa using hConstruction
  · exact AuthState.insertUser_preservesCredentialsBound
      state
      (mkRegisteredUser loginId password)
      hConstruction
      (mkRegisteredUser_preservesCredentialsBound loginId password)

theorem login_preserves_construction_invariants
    (state : AuthState) (loginId : LoginId) (password : Password)
    (hConstruction : ConstructionInvariants state) :
    ConstructionInvariants (login state loginId password).state := by
  unfold ConstructionInvariants at hConstruction ⊢
  cases hAuth : state.authenticated with
  | some current =>
      simp [login, hAuth]
      exact hConstruction
  | none =>
      cases hLookup : state.lookupUser? loginId with
      | none =>
          simp [login, hAuth, hLookup]
          exact hConstruction
      | some user =>
          by_cases hLocked : user.lockState = .locked
          · simp [login, hAuth, hLookup, hLocked]
            exact hConstruction
          · by_cases hPassword : user.passwordMatches password
            · simp [login, hAuth, hLookup, hLocked, hPassword]
              exact AuthState.replaceUser_preservesCredentialsBound
                state
                (user.clearFailedAttempts)
                hConstruction
                (user.clearFailedAttempts_preservesCredentialsBound
                  (hConstruction user (state.lookupUser?_mem_users hLookup)))
            · simp [login, hAuth, hLookup, hLocked, hPassword]
              exact AuthState.replaceUser_preservesCredentialsBound
                state
                (user.noteFailedLogin)
                hConstruction
                (user.noteFailedLogin_preservesCredentialsBound
                  (hConstruction user (state.lookupUser?_mem_users hLookup)))

theorem changePassword_preserves_construction_invariants
    (state : AuthState) (oldPassword newPassword : Password)
    (hConstruction : ConstructionInvariants state) :
    ConstructionInvariants (changePassword state oldPassword newPassword).state := by
  unfold ConstructionInvariants at hConstruction ⊢
  cases hAuth : state.authenticated with
  | none =>
      simp [changePassword, hAuth]
      exact hConstruction
  | some loginId =>
      cases hLookup : state.lookupUser? loginId with
      | none =>
          simp [changePassword, hAuth, hLookup]
          exact hConstruction
      | some user =>
          by_cases hPassword : user.passwordMatches oldPassword
          · simp [changePassword, hAuth, hLookup, hPassword]
            exact AuthState.replaceUser_preservesCredentialsBound
              state
              (user.changePassword newPassword)
              hConstruction
              (user.changePassword_preservesCredentialsBound
                newPassword
                (hConstruction user (state.lookupUser?_mem_users hLookup)))
          · simp [changePassword, hAuth, hLookup, hPassword]
            exact hConstruction

theorem logout_preserves_construction_invariants
    (state : AuthState)
    (hConstruction : ConstructionInvariants state) :
    ConstructionInvariants (logout state).state := by
  simpa [ConstructionInvariants, logout, AuthState.clearSession] using hConstruction

theorem logout_does_not_modify_users (state : AuthState) :
    (logout state).state.users = state.users := by
  exact logout_preserves_users state

theorem changePassword_success_clears_lock
    (user : User) (newPassword : Password) :
    (user.changePassword newPassword).lockState = .active := by
  simp [User.changePassword]

end VerifiableAuth
