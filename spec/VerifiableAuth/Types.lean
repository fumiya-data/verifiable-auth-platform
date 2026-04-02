namespace VerifiableAuth

abbrev LoginId := String
abbrev Password := String

def lockoutThreshold : Nat := 3

inductive LockState
  | active
  | locked
  deriving DecidableEq, Repr, BEq, Inhabited

structure Salt where
  owner : LoginId
  epoch : Nat
  deriving DecidableEq, Repr, BEq, Inhabited

namespace Salt

def initial (loginId : LoginId) : Salt :=
  { owner := loginId, epoch := 0 }

def rotate (salt : Salt) : Salt :=
  { salt with epoch := salt.epoch + 1 }

def material (salt : Salt) : String :=
  s!"{salt.owner}:{salt.epoch}"

end Salt

structure PasswordHash where
  digest : Nat
  deriving DecidableEq, Repr, BEq, Inhabited

private def digestChar (acc : Nat) (c : Char) : Nat :=
  acc * 16777619 + c.toNat

private def digestString (seed : Nat) (text : String) : Nat :=
  text.data.foldl digestChar seed

def derivePasswordHash (password : Password) (salt : Salt) : PasswordHash :=
  { digest := digestString (digestString 2166136261 password) salt.material }

def verifyPassword (password : Password) (salt : Salt) (passwordHash : PasswordHash) : Prop :=
  derivePasswordHash password salt = passwordHash

structure User where
  loginId : LoginId
  salt : Salt
  passwordHash : PasswordHash
  failedAttempts : Nat
  lockState : LockState
  deriving DecidableEq, Repr, BEq, Inhabited

structure AuthState where
  users : List User := []
  authenticated : Option LoginId := none
  deriving DecidableEq, Repr, BEq, Inhabited

inductive RegisterResult
  | success
  | duplicate
  deriving DecidableEq, Repr, BEq, Inhabited

inductive LoginResult
  | success
  | unknownUser
  | lockedOut
  | wrongPassword
  | alreadyAuthenticated
  deriving DecidableEq, Repr, BEq, Inhabited

inductive ChangePasswordResult
  | success
  | unauthorized
  | wrongPassword
  | systemError
  deriving DecidableEq, Repr, BEq, Inhabited

inductive LogoutResult
  | success
  deriving DecidableEq, Repr, BEq, Inhabited

structure Outcome (α : Type) where
  state : AuthState
  result : α
  deriving Repr

inductive AuditEventType
  | register
  | loginSuccess
  | loginFailure
  | lock
  | passwordChange
  | logout
  deriving DecidableEq, Repr, BEq, Inhabited

structure AuditEvent where
  eventType : AuditEventType
  loginId : LoginId
  resultCode : String
  deriving DecidableEq, Repr, BEq, Inhabited

structure Metrics where
  loginSuccessCount : Nat := 0
  loginFailureCount : Nat := 0
  lockoutCount : Nat := 0
  deriving DecidableEq, Repr, BEq, Inhabited

end VerifiableAuth
