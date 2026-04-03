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
  simpa [I11_SessionIsOptionalLoginId, register_preserves_session] using hSession

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
  simp [login]
  split
  · simpa using hConstruction
  · split
    · simpa using hConstruction
    · rename_i user
      by_cases hLocked : user.lockState = .locked
      · simp [hLocked]
        simpa using hConstruction
      · by_cases hPassword : user.passwordMatches password
        · simp [hLocked, hPassword, AuthState.setAuthenticated]
          exact AuthState.replaceUser_preservesCredentialsBound
            state
            (user.clearFailedAttempts)
            hConstruction
            (user.clearFailedAttempts_preservesCredentialsBound)
        · simp [hLocked, hPassword]
          exact AuthState.replaceUser_preservesCredentialsBound
            state
            (user.noteFailedLogin)
            hConstruction
            (user.noteFailedLogin_preservesCredentialsBound)

theorem changePassword_preserves_construction_invariants
    (state : AuthState) (oldPassword newPassword : Password)
    (hConstruction : ConstructionInvariants state) :
    ConstructionInvariants (changePassword state oldPassword newPassword).state := by
  unfold ConstructionInvariants at hConstruction ⊢
  simp [changePassword]
  split
  · simpa using hConstruction
  · split
    · simpa using hConstruction
    · rename_i user
      by_cases hPassword : user.passwordMatches oldPassword
      · simp [hPassword]
        exact AuthState.replaceUser_preservesCredentialsBound
          state
          (user.changePassword newPassword)
          hConstruction
          (user.changePassword_preservesCredentialsBound newPassword)
      · simp [hPassword]
        simpa using hConstruction

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
