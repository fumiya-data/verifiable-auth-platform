import VerifiableAuth.StateModel

namespace VerifiableAuth

def UniqueLoginIds (users : List User) : Prop :=
  users.Pairwise (fun left right => left.loginId ≠ right.loginId)

def User.WellFormed (user : User) : Prop :=
  user.lockState = .locked ↔ lockoutThreshold <= user.failedAttempts

def UsersWellFormed (users : List User) : Prop :=
  ∀ user, user ∈ users → user.WellFormed

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

theorem User.noteFailedLogin_wellFormed (user : User) :
    user.noteFailedLogin.WellFormed := by
  by_cases hThreshold : lockoutThreshold ≤ user.failedAttempts + 1
  · simp [User.WellFormed, User.noteFailedLogin, hThreshold]
  · simp [User.WellFormed, User.noteFailedLogin, hThreshold]

theorem User.clearFailedAttempts_wellFormed (user : User) :
    user.clearFailedAttempts.WellFormed := by
  simp [User.WellFormed, User.clearFailedAttempts, lockoutThreshold]

theorem User.changePassword_wellFormed (user : User) (newPassword : Password) :
    (user.changePassword newPassword).WellFormed := by
  simp [User.WellFormed, User.changePassword, lockoutThreshold]

theorem mkRegisteredUser_wellFormed (loginId : LoginId) (password : Password) :
    (mkRegisteredUser loginId password).WellFormed := by
  simp [User.WellFormed, mkRegisteredUser, lockoutThreshold]

theorem UniqueLoginIds_append_singleton
    {users : List User}
    {user : User}
    (hUnique : UniqueLoginIds users)
    (hFresh : ∀ existing, existing ∈ users → existing.loginId ≠ user.loginId) :
    UniqueLoginIds (users ++ [user]) := by
  unfold UniqueLoginIds at hUnique ⊢
  induction users with
  | nil =>
      simp
  | cons current rest ih =>
      simp at hUnique ⊢
      constructor
      · intro member hMember
        rcases hMember with hOld | hNew
        · exact hUnique.1 member hOld
        · subst hNew
          exact hFresh current (by simp)
      · exact ih hUnique.2 (by
          intro existing hExisting
          exact hFresh existing (by simp [hExisting]))

private theorem replaceUserInList_preserves_unique :
    ∀ (users : List User) (old updated : User),
      UniqueLoginIds users →
      lookupUserInList users updated.loginId = some old →
      UniqueLoginIds (replaceUserInList users updated)
  | [], old, updated, hUnique, hLookup => by
      simp [lookupUserInList] at hLookup
  | current :: rest, old, updated, hUnique, hLookup => by
      by_cases hCurrent : current.loginId = updated.loginId
      · unfold UniqueLoginIds at hUnique ⊢
        simp [lookupUserInList, replaceUserInList, hCurrent] at hLookup hUnique ⊢
        constructor
        · intro member hMember
          intro hEq
          exact hUnique.1 member hMember (by simpa [hCurrent] using hEq)
        · exact hUnique.2
      · unfold UniqueLoginIds at hUnique ⊢
        simp [lookupUserInList, replaceUserInList, hCurrent] at hLookup hUnique ⊢
        constructor
        · intro member hMember
          rcases replaceUserInList_mem_old_or_updated hMember with hUpdated | hOld
          · subst hUpdated
            exact hCurrent
          · exact hUnique.1 member hOld
        · exact replaceUserInList_preserves_unique rest old updated hUnique.2 hLookup

theorem AuthState.replaceUser_preservesUniqueLoginIds
    (state : AuthState)
    (old updated : User)
    (hUnique : UniqueLoginIds state.users)
    (hLookup : state.lookupUser? updated.loginId = some old) :
    UniqueLoginIds (state.replaceUser updated).users := by
  exact replaceUserInList_preserves_unique state.users old updated hUnique hLookup

theorem UsersWellFormed_append_singleton
    {users : List User}
    {user : User}
    (hUsers : UsersWellFormed users)
    (hUser : user.WellFormed) :
    UsersWellFormed (users ++ [user]) := by
  intro member hMember
  rcases List.mem_append.mp hMember with hOld | hNew
  · exact hUsers member hOld
  · have hEq : member = user := by simpa using hNew
    simpa [hEq] using hUser

theorem AuthState.replaceUser_preservesUsersWellFormed
    (state : AuthState)
    (updated : User)
    (hUsers : UsersWellFormed state.users)
    (hUpdated : updated.WellFormed) :
    UsersWellFormed (state.replaceUser updated).users := by
  intro member hMember
  rcases AuthState.replaceUser_mem_old_or_updated hMember with hUpdatedMember | hOld
  · simpa [hUpdatedMember] using hUpdated
  · exact hUsers member hOld

end VerifiableAuth
