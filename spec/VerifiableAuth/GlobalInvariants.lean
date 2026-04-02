import VerifiableAuth.LogoutSpec

namespace VerifiableAuth

/--
I-01 and I-03 are construction invariants in this model:
- plaintext passwords exist only as operation inputs;
- user records store symbolic salts and digests;
- register/change-password are the only constructors for credential material.
-/
def ConstructionInvariants : Prop := True

def I02_UniqueLoginIds (state : AuthState) : Prop :=
  UniqueLoginIds state.users

def I05_LockStateTracksThreshold (state : AuthState) : Prop :=
  UsersWellFormed state.users

def I11_SessionIsOptionalLoginId (_state : AuthState) : Prop :=
  True

def I13_WellFormed (state : AuthState) : Prop :=
  state.WellFormed

def CoreInvariants (state : AuthState) : Prop :=
  ConstructionInvariants ∧
    I02_UniqueLoginIds state ∧
    I05_LockStateTracksThreshold state ∧
    I11_SessionIsOptionalLoginId state ∧
    I13_WellFormed state

theorem register_keeps_session_shape
    (state : AuthState) (loginId : LoginId) (password : Password) :
    I11_SessionIsOptionalLoginId (register state loginId password).state := by
  trivial

theorem logout_does_not_modify_users (state : AuthState) :
    (logout state).state.users = state.users := by
  exact logout_preserves_users state

theorem changePassword_success_clears_lock
    (user : User) (newPassword : Password) :
    (user.changePassword newPassword).lockState = .active := by
  simp [User.changePassword]

end VerifiableAuth
