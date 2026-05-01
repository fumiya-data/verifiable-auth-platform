import VerifiableAuth.Types

namespace VerifiableAuth

def User.passwordMatches (user : User) (password : Password) : Prop :=
  verifyPassword password user.credential.salt user.credential.passwordHash

instance (user : User) (password : Password) : Decidable (user.passwordMatches password) := by
  unfold User.passwordMatches verifyPassword
  infer_instance

def User.noteFailedLogin (user : User) : User :=
  let attempts := user.failedAttempts + 1
  { user with
    failedAttempts := attempts
    lockState := if lockoutThreshold <= attempts then .locked else .active }

def User.clearFailedAttempts (user : User) : User :=
  { user with failedAttempts := 0, lockState := .active }

def User.changePassword (user : User) (newPassword : Password) : User :=
  let newSalt := user.credential.salt.rotate
  { user with
    credential := { salt := newSalt, passwordHash := derivePasswordHash newPassword newSalt }
    failedAttempts := 0
    lockState := .active }

def mkRegisteredUser (loginId : LoginId) (password : Password) : User :=
  let salt := Salt.initial loginId
  { loginId := loginId
    credential := { salt := salt, passwordHash := derivePasswordHash password salt }
    failedAttempts := 0
    lockState := .active }

def lookupUserInList (users : List User) (loginId : LoginId) : Option User :=
  match users with
  | [] => none
  | user :: rest =>
      if user.loginId = loginId then some user else lookupUserInList rest loginId

def replaceUserInList (users : List User) (updated : User) : List User :=
  match users with
  | [] => []
  | user :: rest =>
      if user.loginId = updated.loginId then updated :: rest
      else user :: replaceUserInList rest updated

def AuthState.lookupUser? (state : AuthState) (loginId : LoginId) : Option User :=
  lookupUserInList state.users loginId

def AuthState.containsUser (state : AuthState) (loginId : LoginId) : Bool :=
  (state.lookupUser? loginId).isSome

def AuthState.insertUser (state : AuthState) (user : User) : AuthState :=
  { state with users := state.users ++ [user] }

def AuthState.replaceUser (state : AuthState) (user : User) : AuthState :=
  { state with users := replaceUserInList state.users user }

def AuthState.clearSession (state : AuthState) : AuthState :=
  { state with authenticated := none }

def AuthState.setAuthenticated (state : AuthState) (loginId : LoginId) : AuthState :=
  { state with authenticated := some loginId }

def User.CredentialSaltBound (user : User) : Prop :=
  user.credential.BoundTo user.loginId

def AuthState.CredentialSaltBound (state : AuthState) : Prop :=
  ∀ user, user ∈ state.users → user.CredentialSaltBound

abbrev User.CredentialsBound (user : User) : Prop :=
  user.CredentialSaltBound

abbrev AuthState.CredentialsBound (state : AuthState) : Prop :=
  state.CredentialSaltBound

private theorem lookupUserInList_mem
    {users : List User}
    {loginId : LoginId}
    {user : User} :
    lookupUserInList users loginId = some user → user ∈ users := by
  induction users with
  | nil =>
      simp [lookupUserInList]
  | cons current rest ih =>
      by_cases hEq : current.loginId = loginId
      · intro hLookup
        simp [lookupUserInList, hEq] at hLookup
        subst hLookup
        simp
      · intro hLookup
        simp [lookupUserInList, hEq] at hLookup
        have hRest : user ∈ rest := ih hLookup
        simp [hRest]

private theorem lookupUserInList_loginId
    {users : List User}
    {loginId : LoginId}
    {user : User} :
    lookupUserInList users loginId = some user → user.loginId = loginId := by
  induction users with
  | nil =>
      simp [lookupUserInList]
  | cons current rest ih =>
      by_cases hEq : current.loginId = loginId
      · intro hLookup
        simp [lookupUserInList, hEq] at hLookup
        subst hLookup
        exact hEq
      · intro hLookup
        simp [lookupUserInList, hEq] at hLookup
        exact ih hLookup

private theorem lookupUserInList_append_of_found
    {users : List User}
    {loginId : LoginId}
    {user extra : User}
    (hLookup : lookupUserInList users loginId = some user) :
    lookupUserInList (users ++ [extra]) loginId = some user := by
  induction users with
  | nil =>
      simp [lookupUserInList] at hLookup
  | cons current rest ih =>
      by_cases hEq : current.loginId = loginId
      · simp [lookupUserInList, hEq] at hLookup ⊢
        simp [hLookup]
      · simp [lookupUserInList, hEq] at hLookup ⊢
        exact ih hLookup

private theorem lookupUserInList_none_loginId_ne :
    ∀ {users : List User} {loginId : LoginId} {user : User},
      lookupUserInList users loginId = none →
      user ∈ users →
      user.loginId ≠ loginId
  | [], loginId, user, hLookup, hMem => by
      simp at hMem
  | current :: rest, loginId, user, hLookup, hMem => by
      by_cases hCurrent : current.loginId = loginId
      · simp [lookupUserInList, hCurrent] at hLookup
      · simp [lookupUserInList, hCurrent] at hLookup
        simp at hMem
        rcases hMem with hUser | hRest
        · subst hUser
          exact hCurrent
        · exact lookupUserInList_none_loginId_ne hLookup hRest

private theorem lookupUserInList_replace_same :
    ∀ {users : List User} {old updated : User},
      lookupUserInList users updated.loginId = some old →
      lookupUserInList (replaceUserInList users updated) updated.loginId = some updated
  | [], old, updated, hLookup => by
      simp [lookupUserInList] at hLookup
  | current :: rest, old, updated, hLookup => by
      by_cases hCurrent : current.loginId = updated.loginId
      · simp [lookupUserInList, replaceUserInList, hCurrent]
      · simp [lookupUserInList, replaceUserInList, hCurrent] at hLookup ⊢
        exact lookupUserInList_replace_same hLookup

theorem replaceUserInList_mem_old_or_updated :
    ∀ {users : List User} {updated member : User},
      member ∈ replaceUserInList users updated →
      member = updated ∨ member ∈ users
  | [], updated, member, hMem => by
      simp [replaceUserInList] at hMem
  | current :: rest, updated, member, hMem => by
      by_cases hCurrent : current.loginId = updated.loginId
      · simp [replaceUserInList, hCurrent] at hMem
        rcases hMem with hUpdated | hRest
        · exact Or.inl hUpdated
        · exact Or.inr (by simp [hRest])
      · simp [replaceUserInList, hCurrent] at hMem
        rcases hMem with hCurrentMem | hRest
        · exact Or.inr (by simp [hCurrentMem])
        · rcases replaceUserInList_mem_old_or_updated hRest with hUpdated | hOld
          · exact Or.inl hUpdated
          · exact Or.inr (by simp [hOld])

theorem AuthState.lookupUser?_mem_users
    {state : AuthState}
    {loginId : LoginId}
    {user : User} :
    state.lookupUser? loginId = some user → user ∈ state.users :=
  lookupUserInList_mem

theorem AuthState.lookupUser?_loginId
    {state : AuthState}
    {loginId : LoginId}
    {user : User} :
    state.lookupUser? loginId = some user → user.loginId = loginId :=
  lookupUserInList_loginId

theorem AuthState.lookupUser?_insertUser_of_found
    (state : AuthState)
    (loginId : LoginId)
    (user inserted : User)
    (hLookup : state.lookupUser? loginId = some user) :
    (state.insertUser inserted).lookupUser? loginId = some user := by
  exact lookupUserInList_append_of_found hLookup

theorem AuthState.loginId_ne_of_lookupUser?_none
    {state : AuthState}
    {loginId : LoginId}
    {user : User}
    (hLookup : state.lookupUser? loginId = none)
    (hMem : user ∈ state.users) :
    user.loginId ≠ loginId :=
  lookupUserInList_none_loginId_ne hLookup hMem

theorem AuthState.lookupUser?_replaceUser_same
    {state : AuthState}
    {old updated : User}
    (hLookup : state.lookupUser? updated.loginId = some old) :
    (state.replaceUser updated).lookupUser? updated.loginId = some updated :=
  lookupUserInList_replace_same hLookup

theorem AuthState.replaceUser_mem_old_or_updated
    {state : AuthState}
    {updated member : User}
    (hMem : member ∈ (state.replaceUser updated).users) :
    member = updated ∨ member ∈ state.users :=
  replaceUserInList_mem_old_or_updated hMem

theorem User.noteFailedLogin_preservesCredentialsBound
    (user : User)
    (hBound : user.CredentialsBound) :
    (user.noteFailedLogin).CredentialsBound := by
  simpa [User.CredentialsBound, User.CredentialSaltBound, Credential.BoundTo,
    User.noteFailedLogin] using hBound

theorem User.clearFailedAttempts_preservesCredentialsBound
    (user : User)
    (hBound : user.CredentialsBound) :
    (user.clearFailedAttempts).CredentialsBound := by
  simpa [User.CredentialsBound, User.CredentialSaltBound, Credential.BoundTo,
    User.clearFailedAttempts] using hBound

theorem User.changePassword_preservesCredentialsBound
    (user : User) (newPassword : Password)
    (hBound : user.CredentialsBound) :
    (user.changePassword newPassword).CredentialsBound := by
  simpa [User.CredentialsBound, User.CredentialSaltBound, Credential.BoundTo,
    User.changePassword, Salt.rotate] using hBound

theorem mkRegisteredUser_preservesCredentialsBound
    (loginId : LoginId) (password : Password) :
    (mkRegisteredUser loginId password).CredentialsBound := by
  simp [User.CredentialsBound, User.CredentialSaltBound, Credential.BoundTo,
    mkRegisteredUser, Salt.initial]

private theorem replaceUserInList_preservesCredentialsBound :
    ∀ users updated,
      (∀ user, user ∈ users → user.CredentialsBound) →
      updated.CredentialsBound →
      ∀ user, user ∈ replaceUserInList users updated → user.CredentialsBound
  | [], updated, hUsers, hUpdated, user, hMem => by
      simp [replaceUserInList] at hMem
  | current :: rest, updated, hUsers, hUpdated, user, hMem => by
      by_cases hEq : current.loginId = updated.loginId
      · simp [replaceUserInList, hEq] at hMem
        rcases hMem with rfl | hRest
        · exact hUpdated
        · exact hUsers user (by simp [hRest])
      · simp [replaceUserInList, hEq] at hMem
        rcases hMem with rfl | hRest
        · exact hUsers user (by simp)
        · exact replaceUserInList_preservesCredentialsBound
            rest
            updated
            (by
              intro member hMember
              exact hUsers member (by simp [hMember]))
            hUpdated
            user
            hRest

theorem AuthState.insertUser_preservesCredentialsBound
    (state : AuthState)
    (user : User)
    (hState : state.CredentialsBound)
    (hUser : user.CredentialsBound) :
    (state.insertUser user).CredentialsBound := by
  intro member hMember
  rcases List.mem_append.mp hMember with hOld | hNew
  · exact hState member hOld
  · have hEq : member = user := by simpa using hNew
    simpa [hEq] using hUser

theorem AuthState.replaceUser_preservesCredentialsBound
    (state : AuthState)
    (updated : User)
    (hState : state.CredentialsBound)
    (hUpdated : updated.CredentialsBound) :
    (state.replaceUser updated).CredentialsBound := by
  intro user hMember
  exact replaceUserInList_preservesCredentialsBound
    state.users
    updated
    hState
    hUpdated
    user
    hMember

end VerifiableAuth
