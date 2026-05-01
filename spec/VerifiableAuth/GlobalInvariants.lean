import VerifiableAuth.RegisterSpec
import VerifiableAuth.LoginSpec
import VerifiableAuth.ChangePasswordSpec
import VerifiableAuth.LogoutSpec

namespace VerifiableAuth

/--
Construction discipline currently proven by this model: every stored credential
salt is bound to the login ID of the user record that contains it.

Plaintext-password absence is represented structurally by `User` storing only
`Credential`, not `Password`; stronger credential provenance would require an
explicit provenance relation or sealed construction boundary.
-/
def ConstructionInvariants (state : AuthState) : Prop :=
  state.CredentialSaltBound

def I02_UniqueLoginIds (state : AuthState) : Prop :=
  UniqueLoginIds state.users

def I05_LockStateTracksThreshold (state : AuthState) : Prop :=
  UsersWellFormed state.users

def I11_SessionIsOptionalLoginId (state : AuthState) : Prop :=
  state.SessionConsistent

def I13_WellFormed (state : AuthState) : Prop :=
  state.WellFormed

def CoreInvariants (state : AuthState) : Prop :=
  ConstructionInvariants state ∧ I13_WellFormed state

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

theorem register_preserves_wellFormed
    (state : AuthState) (loginId : LoginId) (password : Password)
    (hWellFormed : state.WellFormed) :
    (register state loginId password).state.WellFormed := by
  rcases hWellFormed with ⟨hUnique, hUsers, hSession⟩
  cases hExisting : state.lookupUser? loginId with
  | some existing =>
      simp [register, hExisting, AuthState.WellFormed, hUnique, hUsers, hSession]
  | none =>
      simp [register, hExisting, AuthState.WellFormed]
      constructor
      · exact UniqueLoginIds_append_singleton
          hUnique
          (by
            intro existing hMember
            exact AuthState.loginId_ne_of_lookupUser?_none hExisting hMember)
      · constructor
        · exact UsersWellFormed_append_singleton
            hUsers
            (mkRegisteredUser_wellFormed loginId password)
        · simpa [I11_SessionIsOptionalLoginId, register, hExisting] using
            register_keeps_session_shape state loginId password hSession

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

theorem login_preserves_wellFormed
    (state : AuthState) (loginId : LoginId) (password : Password)
    (hWellFormed : state.WellFormed) :
    (login state loginId password).state.WellFormed := by
  rcases hWellFormed with ⟨hUnique, hUsers, hSession⟩
  cases hAuth : state.authenticated with
  | some current =>
      simp [login, hAuth, AuthState.WellFormed, hUnique, hUsers, hSession]
  | none =>
      cases hLookup : state.lookupUser? loginId with
      | none =>
          simp [login, hAuth, hLookup, AuthState.WellFormed, hUnique, hUsers, hSession]
      | some user =>
          by_cases hLocked : user.lockState = .locked
          · simp [login, hAuth, hLookup, hLocked, AuthState.WellFormed,
              hUnique, hUsers, hSession]
          · by_cases hPassword : user.passwordMatches password
            · let updated := user.clearFailedAttempts
              have hUserLoginId : user.loginId = loginId :=
                AuthState.lookupUser?_loginId hLookup
              have hLookupUpdated : state.lookupUser? updated.loginId = some user := by
                simpa [updated, User.clearFailedAttempts, hUserLoginId] using hLookup
              have hUnique' :
                  UniqueLoginIds (state.replaceUser updated).users :=
                AuthState.replaceUser_preservesUniqueLoginIds
                  state user updated hUnique hLookupUpdated
              have hUsers' :
                  UsersWellFormed (state.replaceUser updated).users :=
                AuthState.replaceUser_preservesUsersWellFormed
                  state updated hUsers (User.clearFailedAttempts_wellFormed user)
              have hFound :
                  (state.replaceUser updated).lookupUser? loginId = some updated := by
                have hSame :=
                  AuthState.lookupUser?_replaceUser_same
                    (state := state)
                    (old := user)
                    (updated := updated)
                    hLookupUpdated
                simpa [updated, User.clearFailedAttempts, hUserLoginId] using hSame
              have hSession' :
                  ((state.replaceUser updated).setAuthenticated loginId).SessionConsistent := by
                simp [AuthState.SessionConsistent, AuthState.setAuthenticated]
                exact ⟨updated, hFound⟩
              simpa [login, hAuth, hLookup, hLocked, hPassword, updated,
                AuthState.WellFormed] using
                And.intro hUnique' (And.intro hUsers' hSession')
            · let updated := user.noteFailedLogin
              have hUserLoginId : user.loginId = loginId :=
                AuthState.lookupUser?_loginId hLookup
              have hLookupUpdated : state.lookupUser? updated.loginId = some user := by
                simpa [updated, User.noteFailedLogin, hUserLoginId] using hLookup
              have hUnique' :
                  UniqueLoginIds (state.replaceUser updated).users :=
                AuthState.replaceUser_preservesUniqueLoginIds
                  state user updated hUnique hLookupUpdated
              have hUsers' :
                  UsersWellFormed (state.replaceUser updated).users :=
                AuthState.replaceUser_preservesUsersWellFormed
                  state updated hUsers (User.noteFailedLogin_wellFormed user)
              have hSession' :
                  (state.replaceUser updated).SessionConsistent := by
                simp [AuthState.SessionConsistent, AuthState.replaceUser, hAuth]
              simpa [login, hAuth, hLookup, hLocked, hPassword, updated,
                AuthState.WellFormed] using
                And.intro hUnique' (And.intro hUsers' hSession')

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

theorem changePassword_preserves_wellFormed
    (state : AuthState) (oldPassword newPassword : Password)
    (hWellFormed : state.WellFormed) :
    (changePassword state oldPassword newPassword).state.WellFormed := by
  rcases hWellFormed with ⟨hUnique, hUsers, hSession⟩
  cases hAuth : state.authenticated with
  | none =>
      simp [changePassword, hAuth, AuthState.WellFormed, hUnique, hUsers, hSession]
  | some loginId =>
      cases hLookup : state.lookupUser? loginId with
      | none =>
          simp [changePassword, hAuth, hLookup, AuthState.WellFormed,
            hUnique, hUsers, hSession]
      | some user =>
          by_cases hPassword : user.passwordMatches oldPassword
          · let updated := user.changePassword newPassword
            have hUserLoginId : user.loginId = loginId :=
              AuthState.lookupUser?_loginId hLookup
            have hLookupUpdated : state.lookupUser? updated.loginId = some user := by
              simpa [updated, User.changePassword, hUserLoginId] using hLookup
            have hUnique' :
                UniqueLoginIds (state.replaceUser updated).users :=
              AuthState.replaceUser_preservesUniqueLoginIds
                state user updated hUnique hLookupUpdated
            have hUsers' :
                UsersWellFormed (state.replaceUser updated).users :=
              AuthState.replaceUser_preservesUsersWellFormed
                state updated hUsers (User.changePassword_wellFormed user newPassword)
            have hFound :
                (state.replaceUser updated).lookupUser? loginId = some updated := by
              have hSame :=
                AuthState.lookupUser?_replaceUser_same
                  (state := state)
                  (old := user)
                  (updated := updated)
                  hLookupUpdated
              simpa [updated, User.changePassword, hUserLoginId] using hSame
            have hSession' :
                (state.replaceUser updated).SessionConsistent := by
              simp [AuthState.SessionConsistent, AuthState.replaceUser, hAuth]
              exact ⟨updated, hFound⟩
            simpa [changePassword, hAuth, hLookup, hPassword, updated,
              AuthState.WellFormed] using
              And.intro hUnique' (And.intro hUsers' hSession')
          · simp [changePassword, hAuth, hLookup, hPassword, AuthState.WellFormed,
              hUnique, hUsers, hSession]

theorem logout_preserves_construction_invariants
    (state : AuthState)
    (hConstruction : ConstructionInvariants state) :
    ConstructionInvariants (logout state).state := by
  simpa [ConstructionInvariants, logout, AuthState.clearSession] using hConstruction

theorem logout_preserves_wellFormed
    (state : AuthState)
    (hWellFormed : state.WellFormed) :
    (logout state).state.WellFormed := by
  rcases hWellFormed with ⟨hUnique, hUsers, hSession⟩
  simp [logout, AuthState.clearSession, AuthState.WellFormed,
    AuthState.SessionConsistent, hUnique, hUsers]

theorem register_preserves_core_invariants
    (state : AuthState) (loginId : LoginId) (password : Password)
    (hCore : CoreInvariants state) :
    CoreInvariants (register state loginId password).state := by
  exact ⟨
    register_preserves_construction_invariants state loginId password hCore.1,
    register_preserves_wellFormed state loginId password hCore.2
  ⟩

theorem login_preserves_core_invariants
    (state : AuthState) (loginId : LoginId) (password : Password)
    (hCore : CoreInvariants state) :
    CoreInvariants (login state loginId password).state := by
  exact ⟨
    login_preserves_construction_invariants state loginId password hCore.1,
    login_preserves_wellFormed state loginId password hCore.2
  ⟩

theorem changePassword_preserves_core_invariants
    (state : AuthState) (oldPassword newPassword : Password)
    (hCore : CoreInvariants state) :
    CoreInvariants (changePassword state oldPassword newPassword).state := by
  exact ⟨
    changePassword_preserves_construction_invariants state oldPassword newPassword hCore.1,
    changePassword_preserves_wellFormed state oldPassword newPassword hCore.2
  ⟩

theorem logout_preserves_core_invariants
    (state : AuthState)
    (hCore : CoreInvariants state) :
    CoreInvariants (logout state).state := by
  exact ⟨
    logout_preserves_construction_invariants state hCore.1,
    logout_preserves_wellFormed state hCore.2
  ⟩

theorem logout_does_not_modify_users (state : AuthState) :
    (logout state).state.users = state.users := by
  exact logout_preserves_users state

theorem changePassword_success_clears_lock
    (user : User) (newPassword : Password) :
    (user.changePassword newPassword).lockState = .active := by
  simp [User.changePassword]

theorem changePassword_no_systemError_of_sessionConsistent
    (state : AuthState) (oldPassword newPassword : Password)
    (hSession : state.SessionConsistent) :
    (changePassword state oldPassword newPassword).result ≠ .systemError := by
  cases hAuth : state.authenticated with
  | none =>
      simp [changePassword, hAuth]
  | some loginId =>
      simp [AuthState.SessionConsistent, hAuth] at hSession
      rcases hSession with ⟨user, hLookup⟩
      by_cases hPassword : user.passwordMatches oldPassword
      · simp [changePassword, hAuth, hLookup, hPassword]
      · simp [changePassword, hAuth, hLookup, hPassword]

theorem changePassword_no_systemError_of_core
    (state : AuthState) (oldPassword newPassword : Password)
    (hCore : CoreInvariants state) :
    (changePassword state oldPassword newPassword).result ≠ .systemError := by
  exact changePassword_no_systemError_of_sessionConsistent
    state
    oldPassword
    newPassword
    hCore.2.2.2

end VerifiableAuth
