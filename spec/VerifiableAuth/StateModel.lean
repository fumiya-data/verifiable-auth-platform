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

end VerifiableAuth
