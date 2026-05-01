import VerifiableAuth.GlobalInvariants

namespace VerifiableAuth

def RegisterResult.cliCode : RegisterResult → String
  | .success => "success"
  | .duplicate => "duplicate"

def RegisterResult.isOk : RegisterResult → Bool
  | .success => true
  | .duplicate => false

def LoginResult.cliCode : LoginResult → String
  | .success => "success"
  | .unknownUser => "unknown_user"
  | .lockedOut => "locked_out"
  | .wrongPassword => "wrong_password"
  | .alreadyAuthenticated => "already_authenticated"

def LoginResult.isOk : LoginResult → Bool
  | .success => true
  | .unknownUser => false
  | .lockedOut => false
  | .wrongPassword => false
  | .alreadyAuthenticated => false

def ChangePasswordResult.cliCode : ChangePasswordResult → String
  | .success => "success"
  | .unauthorized => "unauthorized"
  | .wrongPassword => "wrong_password"
  | .systemError => "system_error"

def ChangePasswordResult.isOk : ChangePasswordResult → Bool
  | .success => true
  | .unauthorized => false
  | .wrongPassword => false
  | .systemError => false

def LogoutResult.cliCode : LogoutResult → String
  | .success => "success"

def LogoutResult.isOk : LogoutResult → Bool
  | .success => true

def loginAuditEventType (wasLocked : Bool) (result : LoginResult) : AuditEventType :=
  match result with
  | .success => .loginSuccess
  | .lockedOut => if wasLocked then .loginFailure else .lock
  | .unknownUser => .loginFailure
  | .wrongPassword => .loginFailure
  | .alreadyAuthenticated => .loginFailure

def loginPersistsState (wasLocked : Bool) (result : LoginResult) : Bool :=
  result == .success ||
    result == .wrongPassword ||
    (!wasLocked && result == .lockedOut)

def AuthState.loginTargetWasLocked (state : AuthState) (loginId : LoginId) : Bool :=
  match state.lookupUser? loginId with
  | none => false
  | some user => user.lockState == .locked

def loginAuditEventTypeForState
    (state : AuthState) (loginId : LoginId) (result : LoginResult) : AuditEventType :=
  loginAuditEventType (state.loginTargetWasLocked loginId) result

def loginPersistsStateForState
    (state : AuthState) (loginId : LoginId) (result : LoginResult) : Bool :=
  loginPersistsState (state.loginTargetWasLocked loginId) result

def loginTransitionAuditEventType
    (state : AuthState) (loginId : LoginId) (password : Password) : AuditEventType :=
  loginAuditEventTypeForState state loginId (login state loginId password).result

def loginTransitionPersistsState
    (state : AuthState) (loginId : LoginId) (password : Password) : Bool :=
  loginPersistsStateForState state loginId (login state loginId password).result

theorem loginTransitionAuditEventType_uses_prestate_lock_flag
    (state : AuthState) (loginId : LoginId) (password : Password) :
    loginTransitionAuditEventType state loginId password =
      loginAuditEventType
        (state.loginTargetWasLocked loginId)
        (login state loginId password).result := by
  rfl

def countsAsLoginFailure (event : AuditEvent) : Bool :=
  match event.eventType with
  | .lock => true
  | .loginFailure => event.resultCode != "already_authenticated"
  | _ => false

def Metrics.record (metrics : Metrics) (event : AuditEvent) : Metrics :=
  { loginSuccessCount :=
      metrics.loginSuccessCount +
        (if event.eventType = .loginSuccess then 1 else 0)
    loginFailureCount :=
      metrics.loginFailureCount +
        (if countsAsLoginFailure event then 1 else 0)
    lockoutCount :=
      metrics.lockoutCount +
        (if event.eventType = .lock then 1 else 0) }

def computeMetrics (events : List AuditEvent) : Metrics :=
  events.foldl Metrics.record {}

theorem alreadyAuthenticated_does_not_count_as_login_failure
    (loginId : LoginId) :
    countsAsLoginFailure
      { eventType := .loginFailure, loginId := loginId, resultCode := "already_authenticated" } = false := by
  simp [countsAsLoginFailure]

end VerifiableAuth
