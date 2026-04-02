import VerifiableAuth.RefinementNotes

namespace VerifiableAuth

def emptyState : AuthState := {}

def registeredAlice : Outcome RegisterResult :=
  register emptyState "alice" "hunter2"

def wrongPasswordAttempt1 : Outcome LoginResult :=
  login registeredAlice.state "alice" "wrong-1"

def wrongPasswordAttempt2 : Outcome LoginResult :=
  login wrongPasswordAttempt1.state "alice" "wrong-2"

def wrongPasswordAttempt3 : Outcome LoginResult :=
  login wrongPasswordAttempt2.state "alice" "wrong-3"

def successfulLogin : Outcome LoginResult :=
  login registeredAlice.state "alice" "hunter2"

def changedPassword : Outcome ChangePasswordResult :=
  changePassword successfulLogin.state "hunter2" "new-secret"

def loggedOut : Outcome LogoutResult :=
  logout changedPassword.state

example : registeredAlice.result = .success := rfl

example : wrongPasswordAttempt1.result = .wrongPassword := rfl

example : wrongPasswordAttempt2.result = .wrongPassword := rfl

example : wrongPasswordAttempt3.result = .lockedOut := rfl

example : successfulLogin.result = .success := rfl

example : successfulLogin.state.authenticated = some "alice" := rfl

example :
    (wrongPasswordAttempt3.state.lookupUser? "alice").map User.failedAttempts = some 3 := rfl

example :
    (wrongPasswordAttempt3.state.lookupUser? "alice").map User.lockState = some .locked := rfl

example : changedPassword.result = .success := rfl

example : changedPassword.state.authenticated = some "alice" := rfl

example :
    (changedPassword.state.lookupUser? "alice").map User.failedAttempts = some 0 := rfl

example :
    (changedPassword.state.lookupUser? "alice").map User.lockState = some .active := rfl

example : loggedOut.result = .success := rfl

example : loggedOut.state.authenticated = none := rfl

end VerifiableAuth
