import VerifiableAuth.StateModel

namespace VerifiableAuth

def UniqueLoginIds (users : List User) : Prop :=
  users.Pairwise (fun left right => left.loginId ≠ right.loginId)

def User.WellFormed (user : User) : Prop :=
  user.lockState = .locked ↔ lockoutThreshold <= user.failedAttempts

def UsersWellFormed : List User → Prop
  | [] => True
  | user :: rest => user.WellFormed ∧ UsersWellFormed rest

def AuthState.SessionConsistent (state : AuthState) : Prop :=
  match state.authenticated with
  | none => True
  | some loginId => ∃ user, state.lookupUser? loginId = some user

def AuthState.WellFormed (state : AuthState) : Prop :=
  UniqueLoginIds state.users ∧ UsersWellFormed state.users ∧ state.SessionConsistent

theorem User.failedAttempts_lt_threshold_of_not_locked
    {user : User}
    (hWellFormed : user.WellFormed)
    (hNotLocked : user.lockState ≠ .locked) :
    user.failedAttempts < lockoutThreshold := by
  have hNotThreshold : ¬ lockoutThreshold ≤ user.failedAttempts := by
    intro hThreshold
    exact hNotLocked (hWellFormed.2 hThreshold)
  exact Nat.lt_of_not_ge hNotThreshold

theorem User.active_of_not_locked
    {user : User}
    (hNotLocked : user.lockState ≠ .locked) :
    user.lockState = .active := by
  cases hState : user.lockState with
  | active => rfl
  | locked =>
      exfalso
      exact hNotLocked hState

theorem mkRegisteredUser_wellFormed (loginId : LoginId) (password : Password) :
    (mkRegisteredUser loginId password).WellFormed := by
  simp [User.WellFormed, mkRegisteredUser, lockoutThreshold]

end VerifiableAuth
