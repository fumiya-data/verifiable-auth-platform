import VerifiableAuth.Types

namespace VerifiableAuth

def User.passwordMatches (user : User) (password : Password) : Prop :=
  verifyPassword password user.salt user.passwordHash

def User.noteFailedLogin (user : User) : User :=
  let attempts := user.failedAttempts + 1
  { user with
    failedAttempts := attempts
    lockState := if lockoutThreshold <= attempts then .locked else .active }

def User.clearFailedAttempts (user : User) : User :=
  { user with failedAttempts := 0 }

def User.changePassword (user : User) (newPassword : Password) : User :=
  let newSalt := user.salt.rotate
  { user with
    salt := newSalt
    passwordHash := derivePasswordHash newPassword newSalt
    failedAttempts := 0
    lockState := .active }

def mkRegisteredUser (loginId : LoginId) (password : Password) : User :=
  let salt := Salt.initial loginId
  { loginId := loginId
    salt := salt
    passwordHash := derivePasswordHash password salt
    failedAttempts := 0
    lockState := .active }

private def lookupUserInList (users : List User) (loginId : LoginId) : Option User :=
  match users with
  | [] => none
  | user :: rest =>
      if user.loginId = loginId then some user else lookupUserInList rest loginId

private def replaceUserInList (users : List User) (updated : User) : List User :=
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

def User.CredentialsBound (user : User) : Prop :=
  user.salt.owner = user.loginId

def AuthState.CredentialsBound (state : AuthState) : Prop :=
  ∀ user, user ∈ state.users → user.CredentialsBound

theorem User.noteFailedLogin_preservesCredentialsBound
    (user : User) :
    (user.noteFailedLogin).CredentialsBound := by
  simp [User.CredentialsBound, User.noteFailedLogin]

theorem User.clearFailedAttempts_preservesCredentialsBound
    (user : User) :
    (user.clearFailedAttempts).CredentialsBound := by
  simp [User.CredentialsBound, User.clearFailedAttempts]

theorem User.changePassword_preservesCredentialsBound
    (user : User) (newPassword : Password) :
    (user.changePassword newPassword).CredentialsBound := by
  simp [User.CredentialsBound, User.changePassword, Salt.rotate]

theorem mkRegisteredUser_preservesCredentialsBound
    (loginId : LoginId) (password : Password) :
    (mkRegisteredUser loginId password).CredentialsBound := by
  simp [User.CredentialsBound, mkRegisteredUser, Salt.initial]

private theorem replaceUserInList_preservesCredentialsBound :
    ∀ users updated,
      (∀ user, user ∈ users → user.CredentialsBound) →
      updated.CredentialsBound →
      ∀ user, user ∈ replaceUserInList users updated → user.CredentialsBound
  | [], updated, hUsers, hUpdated, user, hMem => by
      simp [replaceUserInList] at hMem
  | current :: rest, updated, hUsers, hUpdated, user, hMem => by
      by_cases hEq : current.loginId = updated.loginId
      · simp [replaceUserInList, hEq] at hMem ⊢
        rcases hMem with rfl | hRest
        · exact hUpdated
        · exact replaceUserInList_preservesCredentialsBound
            rest
            updated
            (by
              intro member hMember
              exact hUsers member (by simp [hMember]))
            hUpdated
            user
            hRest
      · simp [replaceUserInList, hEq] at hMem ⊢
        rcases hMem with rfl | hRest
        · exact hUsers current (by simp)
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
