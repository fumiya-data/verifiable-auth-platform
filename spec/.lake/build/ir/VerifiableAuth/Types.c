// Lean compiler output
// Module: VerifiableAuth.Types
// Imports: public import Init
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_lockoutThreshold;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_toCtorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_toCtorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorElim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorElim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorElim(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_active_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_active_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_active_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_active_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_locked_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_locked_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_locked_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_locked_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_LockState_ofNat(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_ofNat___boxed(lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqLockState(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqLockState___boxed(lean_object*, lean_object*);
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 32, .m_capacity = 32, .m_length = 31, .m_data = "VerifiableAuth.LockState.active"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__0_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__0_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__1 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__1_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 32, .m_capacity = 32, .m_length = 31, .m_data = "VerifiableAuth.LockState.locked"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__2 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__2_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__2_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__3 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__3_value;
lean_object* lean_nat_to_int(lean_object*);
static lean_once_cell_t lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4;
static lean_once_cell_t lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5;
lean_object* l_Repr_addAppParen(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState___closed__0_value;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqLockState_beq(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqLockState_beq___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instBEqLockState___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instBEqLockState_beq___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqLockState___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqLockState___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqLockState = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqLockState___closed__0_value;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLockState_default;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLockState;
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqSalt_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqSalt_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqSalt(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqSalt___boxed(lean_object*, lean_object*);
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "{ "};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__0_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "owner"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__1 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__1_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__1_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__2 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__2_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__2_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__3 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__3_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = " := "};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__4 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__4_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__4_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__3_value),((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__6 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__6_value;
static lean_once_cell_t lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = ","};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__8 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__8_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__8_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__9 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__9_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "epoch"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__10 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__10_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__10_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__11 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__11_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = " }"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__12 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__12_value;
lean_object* lean_string_length(lean_object*);
static lean_once_cell_t lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__13;
static lean_once_cell_t lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__0_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__15 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__15_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__12_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__16 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__16_value;
lean_object* l_String_quote(lean_object*);
lean_object* l_Nat_reprFast(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt___closed__0_value;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqSalt_beq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqSalt_beq___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instBEqSalt___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instBEqSalt_beq___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqSalt___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqSalt___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqSalt = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqSalt___closed__0_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedSalt_default___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 1, .m_capacity = 1, .m_length = 0, .m_data = ""};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedSalt_default___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedSalt_default___closed__0_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedSalt_default___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedSalt_default___closed__0_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedSalt_default___closed__1 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedSalt_default___closed__1_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedSalt_default = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedSalt_default___closed__1_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedSalt = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedSalt_default___closed__1_value;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_Salt_initial(lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_Salt_rotate(lean_object*);
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_Salt_material___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = ":"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_Salt_material___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_Salt_material___closed__0_value;
lean_object* lean_string_append(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_Salt_material(lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqPasswordHash_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqPasswordHash_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqPasswordHash(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqPasswordHash___boxed(lean_object*, lean_object*);
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "digest"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__0_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__0_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__1 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__1_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__1_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__2 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__2_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__2_value),((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__3 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__3_value;
static lean_once_cell_t lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__4;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash___closed__0_value;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqPasswordHash_beq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqPasswordHash_beq___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instBEqPasswordHash___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instBEqPasswordHash_beq___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqPasswordHash___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqPasswordHash___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqPasswordHash = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqPasswordHash___closed__0_value;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedPasswordHash_default;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedPasswordHash;
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_uint32_to_nat(uint32_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec___private_VerifiableAuth_Types_0__VerifiableAuth_digestChar(lean_object*, uint32_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec___private_VerifiableAuth_Types_0__VerifiableAuth_digestChar___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_List_foldl___at___00__private_VerifiableAuth_Types_0__VerifiableAuth_digestString_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_List_foldl___at___00__private_VerifiableAuth_Types_0__VerifiableAuth_digestString_spec__0___boxed(lean_object*, lean_object*);
lean_object* lean_string_data(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec___private_VerifiableAuth_Types_0__VerifiableAuth_digestString(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_derivePasswordHash(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqUser_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqUser_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqUser(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqUser___boxed(lean_object*, lean_object*);
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "loginId"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__0_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__0_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__1 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__1_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__1_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__2 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__2_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__2_value),((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__3 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__3_value;
static lean_once_cell_t lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__4;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "salt"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__5 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__5_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__5_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__6 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__6_value;
static lean_once_cell_t lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__7;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "passwordHash"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__8 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__8_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__8_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__9 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__9_value;
static lean_once_cell_t lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__10_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__10;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "failedAttempts"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__11 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__11_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__11_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__12 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__12_value;
static lean_once_cell_t lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__13;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "lockState"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__14 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__14_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__14_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__15 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__15_value;
static lean_once_cell_t lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__16_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__16;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instReprUser___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser___closed__0_value;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqUser_beq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqUser_beq___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instBEqUser___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instBEqUser_beq___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqUser___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqUser___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqUser = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqUser___closed__0_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedUser_default___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*4 + 8, .m_other = 4, .m_tag = 0}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedSalt_default___closed__0_value),((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedSalt_default___closed__1_value),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),LEAN_SCALAR_PTR_LITERAL(0, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedUser_default___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedUser_default___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedUser_default = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedUser_default___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedUser = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedUser_default___closed__0_value;
uint8_t l_instDecidableEqList___redArg(lean_object*, lean_object*, lean_object*);
lean_object* l_instDecidableEqString___boxed(lean_object*, lean_object*);
uint8_t l_Option_instDecidableEq___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuthState_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuthState_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuthState(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuthState___boxed(lean_object*, lean_object*);
static const lean_string_object lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "none"};
static const lean_object* lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___closed__0_value;
static const lean_ctor_object lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___closed__0_value)}};
static const lean_object* lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___closed__1 = (const lean_object*)&lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___closed__1_value;
static const lean_string_object lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "some "};
static const lean_object* lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___closed__2 = (const lean_object*)&lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___closed__2_value;
static const lean_ctor_object lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___closed__2_value)}};
static const lean_object* lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___closed__3 = (const lean_object*)&lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___closed__3_value;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_List_foldl___at___00List_foldl___at___00Std_Format_joinSep___at___00List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0_spec__0_spec__2_spec__3(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_List_foldl___at___00Std_Format_joinSep___at___00List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0_spec__0_spec__2(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_Std_Format_joinSep___at___00List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0_spec__0(lean_object*, lean_object*);
static const lean_string_object lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "[]"};
static const lean_object* lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__0_value;
static const lean_ctor_object lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__0_value)}};
static const lean_object* lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__1 = (const lean_object*)&lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__1_value;
static const lean_string_object lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "["};
static const lean_object* lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__2 = (const lean_object*)&lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__2_value;
static const lean_ctor_object lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__9_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__3 = (const lean_object*)&lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__3_value;
static const lean_string_object lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "]"};
static const lean_object* lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__4 = (const lean_object*)&lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__4_value;
static lean_once_cell_t lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__5;
static lean_once_cell_t lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__6;
static const lean_ctor_object lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__2_value)}};
static const lean_object* lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__7 = (const lean_object*)&lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__7_value;
static const lean_ctor_object lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__4_value)}};
static const lean_object* lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__8 = (const lean_object*)&lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__8_value;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg(lean_object*);
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "users"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__0_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__0_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__1 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__1_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__1_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__2 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__2_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__2_value),((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__3 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__3_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "authenticated"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__4 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__4_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__4_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__5 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__5_value;
static lean_once_cell_t lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__6;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState___closed__0_value;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_Option_instBEq_beq___at___00VerifiableAuth_instBEqAuthState_beq_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_Option_instBEq_beq___at___00VerifiableAuth_instBEqAuthState_beq_spec__1___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_List_beq___at___00VerifiableAuth_instBEqAuthState_beq_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_List_beq___at___00VerifiableAuth_instBEqAuthState_beq_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuthState_beq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuthState_beq___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuthState___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuthState_beq___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuthState___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuthState___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuthState = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuthState___closed__0_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuthState_default___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuthState_default___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuthState_default___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuthState_default = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuthState_default___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuthState = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuthState_default___closed__0_value;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_toCtorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_toCtorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorElim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorElim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorElim(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_success_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_success_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_success_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_success_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_duplicate_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_duplicate_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_duplicate_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_duplicate_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ofNat(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ofNat___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqRegisterResult(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqRegisterResult___boxed(lean_object*, lean_object*);
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 38, .m_capacity = 38, .m_length = 37, .m_data = "VerifiableAuth.RegisterResult.success"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___closed__0_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___closed__0_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___closed__1 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___closed__1_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 40, .m_capacity = 40, .m_length = 39, .m_data = "VerifiableAuth.RegisterResult.duplicate"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___closed__2 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___closed__2_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___closed__2_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___closed__3 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___closed__3_value;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult___closed__0_value;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqRegisterResult_beq(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqRegisterResult_beq___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instBEqRegisterResult___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instBEqRegisterResult_beq___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqRegisterResult___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqRegisterResult___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqRegisterResult = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqRegisterResult___closed__0_value;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedRegisterResult_default;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedRegisterResult;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_toCtorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_toCtorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorElim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorElim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorElim(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_success_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_success_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_success_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_success_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_unknownUser_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_unknownUser_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_unknownUser_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_unknownUser_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_lockedOut_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_lockedOut_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_lockedOut_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_lockedOut_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_wrongPassword_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_wrongPassword_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_wrongPassword_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_wrongPassword_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_alreadyAuthenticated_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_alreadyAuthenticated_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_alreadyAuthenticated_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_alreadyAuthenticated_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ofNat(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ofNat___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqLoginResult(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqLoginResult___boxed(lean_object*, lean_object*);
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 35, .m_capacity = 35, .m_length = 34, .m_data = "VerifiableAuth.LoginResult.success"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__0_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__0_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__1 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__1_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 39, .m_capacity = 39, .m_length = 38, .m_data = "VerifiableAuth.LoginResult.unknownUser"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__2 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__2_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__2_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__3 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__3_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 37, .m_capacity = 37, .m_length = 36, .m_data = "VerifiableAuth.LoginResult.lockedOut"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__4 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__4_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__4_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__5 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__5_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 41, .m_capacity = 41, .m_length = 40, .m_data = "VerifiableAuth.LoginResult.wrongPassword"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__6 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__6_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__6_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__7 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__7_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 48, .m_capacity = 48, .m_length = 47, .m_data = "VerifiableAuth.LoginResult.alreadyAuthenticated"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__8 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__8_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__8_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__9 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__9_value;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult___closed__0_value;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqLoginResult_beq(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqLoginResult_beq___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instBEqLoginResult___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instBEqLoginResult_beq___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqLoginResult___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqLoginResult___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqLoginResult = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqLoginResult___closed__0_value;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLoginResult_default;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLoginResult;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_toCtorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_toCtorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorElim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorElim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorElim(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_success_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_success_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_success_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_success_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_unauthorized_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_unauthorized_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_unauthorized_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_unauthorized_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_wrongPassword_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_wrongPassword_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_wrongPassword_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_wrongPassword_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_systemError_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_systemError_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_systemError_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_systemError_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ofNat(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ofNat___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqChangePasswordResult(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqChangePasswordResult___boxed(lean_object*, lean_object*);
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 44, .m_capacity = 44, .m_length = 43, .m_data = "VerifiableAuth.ChangePasswordResult.success"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__0_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__0_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__1 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__1_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 49, .m_capacity = 49, .m_length = 48, .m_data = "VerifiableAuth.ChangePasswordResult.unauthorized"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__2 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__2_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__2_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__3 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__3_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 50, .m_capacity = 50, .m_length = 49, .m_data = "VerifiableAuth.ChangePasswordResult.wrongPassword"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__4 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__4_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__4_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__5 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__5_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 48, .m_capacity = 48, .m_length = 47, .m_data = "VerifiableAuth.ChangePasswordResult.systemError"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__6 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__6_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__6_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__7 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__7_value;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult___closed__0_value;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqChangePasswordResult_beq(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqChangePasswordResult_beq___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instBEqChangePasswordResult___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instBEqChangePasswordResult_beq___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqChangePasswordResult___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqChangePasswordResult___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqChangePasswordResult = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqChangePasswordResult___closed__0_value;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedChangePasswordResult_default;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedChangePasswordResult;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LogoutResult_toCtorIdx(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LogoutResult_ofNat(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LogoutResult_ofNat___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqLogoutResult(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqLogoutResult___boxed(lean_object*, lean_object*);
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 36, .m_capacity = 36, .m_length = 35, .m_data = "VerifiableAuth.LogoutResult.success"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr___redArg___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr___redArg___closed__0_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr___redArg___closed__0_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr___redArg___closed__1 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr___redArg___closed__1_value;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult___closed__0_value;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqLogoutResult_beq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqLogoutResult_beq___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instBEqLogoutResult___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instBEqLogoutResult_beq___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqLogoutResult___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqLogoutResult___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqLogoutResult = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqLogoutResult___closed__0_value;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLogoutResult_default;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLogoutResult;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "state"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__0_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__0_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__1 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__1_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__1_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__2 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__2_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__2_value),((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__3 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__3_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "result"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__4 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__4_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__4_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__5 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__5_value;
static lean_once_cell_t lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__6;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_toCtorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_toCtorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorElim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorElim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorElim(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_register_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_register_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_register_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_register_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginSuccess_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginSuccess_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginSuccess_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginSuccess_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginFailure_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginFailure_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginFailure_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginFailure_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_lock_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_lock_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_lock_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_lock_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_passwordChange_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_passwordChange_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_passwordChange_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_passwordChange_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_logout_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_logout_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_logout_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_logout_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ofNat(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ofNat___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuditEventType(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuditEventType___boxed(lean_object*, lean_object*);
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 39, .m_capacity = 39, .m_length = 38, .m_data = "VerifiableAuth.AuditEventType.register"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__0_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__0_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__1 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__1_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 43, .m_capacity = 43, .m_length = 42, .m_data = "VerifiableAuth.AuditEventType.loginSuccess"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__2 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__2_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__2_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__3 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__3_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 43, .m_capacity = 43, .m_length = 42, .m_data = "VerifiableAuth.AuditEventType.loginFailure"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__4 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__4_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__4_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__5 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__5_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 35, .m_capacity = 35, .m_length = 34, .m_data = "VerifiableAuth.AuditEventType.lock"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__6 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__6_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__6_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__7 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__7_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 45, .m_capacity = 45, .m_length = 44, .m_data = "VerifiableAuth.AuditEventType.passwordChange"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__8 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__8_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__8_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__9 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__9_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 37, .m_capacity = 37, .m_length = 36, .m_data = "VerifiableAuth.AuditEventType.logout"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__10 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__10_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__10_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__11 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__11_value;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType___closed__0_value;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEventType_beq(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEventType_beq___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEventType___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEventType_beq___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEventType___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEventType___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEventType = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEventType___closed__0_value;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEventType_default;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEventType;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuditEvent_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuditEvent_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuditEvent(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuditEvent___boxed(lean_object*, lean_object*);
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "eventType"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__0_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__0_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__1 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__1_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__1_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__2 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__2_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__2_value),((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__3 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__3_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "resultCode"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__4 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__4_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__4_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__5 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__5_value;
static lean_once_cell_t lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__6;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent___closed__0_value;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEvent_beq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEvent_beq___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEvent___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEvent_beq___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEvent___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEvent___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEvent = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEvent___closed__0_value;
static lean_once_cell_t lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEvent_default___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEvent_default___closed__0;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEvent_default;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEvent;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqMetrics_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqMetrics_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqMetrics(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqMetrics___boxed(lean_object*, lean_object*);
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "loginSuccessCount"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__0_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__0_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__1 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__1_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__1_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__2 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__2_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__2_value),((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__3 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__3_value;
static lean_once_cell_t lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__4;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "loginFailureCount"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__5 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__5_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__5_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__6 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__6_value;
static const lean_string_object lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "lockoutCount"};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__7 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__7_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__7_value)}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__8 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__8_value;
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics___closed__0_value;
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqMetrics_beq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqMetrics_beq___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_VerifiableAuthSpec_VerifiableAuth_instBEqMetrics___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_VerifiableAuthSpec_VerifiableAuth_instBEqMetrics_beq___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqMetrics___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqMetrics___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqMetrics = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instBEqMetrics___closed__0_value;
static const lean_ctor_object lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedMetrics_default___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedMetrics_default___closed__0 = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedMetrics_default___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedMetrics_default = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedMetrics_default___closed__0_value;
LEAN_EXPORT const lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedMetrics = (const lean_object*)&lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedMetrics_default___closed__0_value;
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_lockoutThreshold(void) {
_start:
{
lean_object* x_1; 
x_1 = lean_unsigned_to_nat(3u);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorIdx(uint8_t x_1) {
_start:
{
if (x_1 == 0)
{
lean_object* x_2; 
x_2 = lean_unsigned_to_nat(0u);
return x_2;
}
else
{
lean_object* x_3; 
x_3 = lean_unsigned_to_nat(1u);
return x_3;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorIdx___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = lean_unbox(x_1);
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorIdx(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_toCtorIdx(uint8_t x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorIdx(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_toCtorIdx___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = lean_unbox(x_1);
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_LockState_toCtorIdx(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorElim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorElim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorElim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorElim(lean_object* x_1, lean_object* x_2, uint8_t x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
lean_inc(x_5);
return x_5;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorElim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
uint8_t x_6; lean_object* x_7; 
x_6 = lean_unbox(x_3);
x_7 = lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorElim(x_1, x_2, x_6, x_4, x_5);
lean_dec(x_5);
lean_dec(x_2);
return x_7;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_active_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_active_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_LockState_active_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_active_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_active_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_LockState_active_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_locked_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_locked_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_LockState_locked_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_locked_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_locked_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_LockState_locked_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_LockState_ofNat(lean_object* x_1) {
_start:
{
lean_object* x_2; uint8_t x_3; 
x_2 = lean_unsigned_to_nat(0u);
x_3 = lean_nat_dec_le(x_1, x_2);
if (x_3 == 0)
{
uint8_t x_4; 
x_4 = 1;
return x_4;
}
else
{
uint8_t x_5; 
x_5 = 0;
return x_5;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LockState_ofNat___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_LockState_ofNat(x_1);
lean_dec(x_1);
x_3 = lean_box(x_2);
return x_3;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqLockState(uint8_t x_1, uint8_t x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; uint8_t x_5; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorIdx(x_1);
x_4 = lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorIdx(x_2);
x_5 = lean_nat_dec_eq(x_3, x_4);
lean_dec(x_4);
lean_dec(x_3);
return x_5;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqLockState___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; uint8_t x_4; uint8_t x_5; lean_object* x_6; 
x_3 = lean_unbox(x_1);
x_4 = lean_unbox(x_2);
x_5 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqLockState(x_3, x_4);
x_6 = lean_box(x_5);
return x_6;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4(void) {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(2u);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5(void) {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(1u);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr(uint8_t x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_10; 
if (x_1 == 0)
{
lean_object* x_17; uint8_t x_18; 
x_17 = lean_unsigned_to_nat(1024u);
x_18 = lean_nat_dec_le(x_17, x_2);
if (x_18 == 0)
{
lean_object* x_19; 
x_19 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_3 = x_19;
goto block_9;
}
else
{
lean_object* x_20; 
x_20 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_3 = x_20;
goto block_9;
}
}
else
{
lean_object* x_21; uint8_t x_22; 
x_21 = lean_unsigned_to_nat(1024u);
x_22 = lean_nat_dec_le(x_21, x_2);
if (x_22 == 0)
{
lean_object* x_23; 
x_23 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_10 = x_23;
goto block_16;
}
else
{
lean_object* x_24; 
x_24 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_10 = x_24;
goto block_16;
}
}
block_9:
{
lean_object* x_4; lean_object* x_5; uint8_t x_6; lean_object* x_7; lean_object* x_8; 
x_4 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__1));
x_5 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_5, 0, x_3);
lean_ctor_set(x_5, 1, x_4);
x_6 = 0;
x_7 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_7, 0, x_5);
lean_ctor_set_uint8(x_7, sizeof(void*)*1, x_6);
x_8 = l_Repr_addAppParen(x_7, x_2);
return x_8;
}
block_16:
{
lean_object* x_11; lean_object* x_12; uint8_t x_13; lean_object* x_14; lean_object* x_15; 
x_11 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__3));
x_12 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_12, 0, x_10);
lean_ctor_set(x_12, 1, x_11);
x_13 = 0;
x_14 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_14, 0, x_12);
lean_ctor_set_uint8(x_14, sizeof(void*)*1, x_13);
x_15 = l_Repr_addAppParen(x_14, x_2);
return x_15;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lean_unbox(x_1);
x_4 = lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr(x_3, x_2);
lean_dec(x_2);
return x_4;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqLockState_beq(uint8_t x_1, uint8_t x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; uint8_t x_5; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorIdx(x_1);
x_4 = lp_VerifiableAuthSpec_VerifiableAuth_LockState_ctorIdx(x_2);
x_5 = lean_nat_dec_eq(x_3, x_4);
lean_dec(x_4);
lean_dec(x_3);
return x_5;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqLockState_beq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; uint8_t x_4; uint8_t x_5; lean_object* x_6; 
x_3 = lean_unbox(x_1);
x_4 = lean_unbox(x_2);
x_5 = lp_VerifiableAuthSpec_VerifiableAuth_instBEqLockState_beq(x_3, x_4);
x_6 = lean_box(x_5);
return x_6;
}
}
static uint8_t _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLockState_default(void) {
_start:
{
uint8_t x_1; 
x_1 = 0;
return x_1;
}
}
static uint8_t _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLockState(void) {
_start:
{
uint8_t x_1; 
x_1 = 0;
return x_1;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqSalt_decEq(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; uint8_t x_7; 
x_3 = lean_ctor_get(x_1, 0);
x_4 = lean_ctor_get(x_1, 1);
x_5 = lean_ctor_get(x_2, 0);
x_6 = lean_ctor_get(x_2, 1);
x_7 = lean_string_dec_eq(x_3, x_5);
if (x_7 == 0)
{
return x_7;
}
else
{
uint8_t x_8; 
x_8 = lean_nat_dec_eq(x_4, x_6);
return x_8;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqSalt_decEq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqSalt_decEq(x_1, x_2);
lean_dec_ref(x_2);
lean_dec_ref(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqSalt(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqSalt_decEq(x_1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqSalt___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqSalt(x_1, x_2);
lean_dec_ref(x_2);
lean_dec_ref(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7(void) {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(9u);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__13(void) {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__0));
x_2 = lean_string_length(x_1);
return x_2;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14(void) {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__13, &lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__13_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__13);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg(lean_object* x_1) {
_start:
{
uint8_t x_2; 
x_2 = !lean_is_exclusive(x_1);
if (x_2 == 0)
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; uint8_t x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; lean_object* x_22; lean_object* x_23; lean_object* x_24; lean_object* x_25; lean_object* x_26; lean_object* x_27; lean_object* x_28; lean_object* x_29; lean_object* x_30; lean_object* x_31; 
x_3 = lean_ctor_get(x_1, 0);
x_4 = lean_ctor_get(x_1, 1);
x_5 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5));
x_6 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__6));
x_7 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7, &lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7);
x_8 = l_String_quote(x_3);
x_9 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_9, 0, x_8);
lean_ctor_set_tag(x_1, 4);
lean_ctor_set(x_1, 1, x_9);
lean_ctor_set(x_1, 0, x_7);
x_10 = 0;
x_11 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_11, 0, x_1);
lean_ctor_set_uint8(x_11, sizeof(void*)*1, x_10);
x_12 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_12, 0, x_6);
lean_ctor_set(x_12, 1, x_11);
x_13 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__9));
x_14 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_14, 0, x_12);
lean_ctor_set(x_14, 1, x_13);
x_15 = lean_box(1);
x_16 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_16, 0, x_14);
lean_ctor_set(x_16, 1, x_15);
x_17 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__11));
x_18 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_18, 0, x_16);
lean_ctor_set(x_18, 1, x_17);
x_19 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_19, 0, x_18);
lean_ctor_set(x_19, 1, x_5);
x_20 = l_Nat_reprFast(x_4);
x_21 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_21, 0, x_20);
x_22 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_22, 0, x_7);
lean_ctor_set(x_22, 1, x_21);
x_23 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_23, 0, x_22);
lean_ctor_set_uint8(x_23, sizeof(void*)*1, x_10);
x_24 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_24, 0, x_19);
lean_ctor_set(x_24, 1, x_23);
x_25 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14, &lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14);
x_26 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__15));
x_27 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_27, 0, x_26);
lean_ctor_set(x_27, 1, x_24);
x_28 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__16));
x_29 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_29, 0, x_27);
lean_ctor_set(x_29, 1, x_28);
x_30 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_30, 0, x_25);
lean_ctor_set(x_30, 1, x_29);
x_31 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_31, 0, x_30);
lean_ctor_set_uint8(x_31, sizeof(void*)*1, x_10);
return x_31;
}
else
{
lean_object* x_32; lean_object* x_33; lean_object* x_34; lean_object* x_35; lean_object* x_36; lean_object* x_37; lean_object* x_38; lean_object* x_39; uint8_t x_40; lean_object* x_41; lean_object* x_42; lean_object* x_43; lean_object* x_44; lean_object* x_45; lean_object* x_46; lean_object* x_47; lean_object* x_48; lean_object* x_49; lean_object* x_50; lean_object* x_51; lean_object* x_52; lean_object* x_53; lean_object* x_54; lean_object* x_55; lean_object* x_56; lean_object* x_57; lean_object* x_58; lean_object* x_59; lean_object* x_60; lean_object* x_61; 
x_32 = lean_ctor_get(x_1, 0);
x_33 = lean_ctor_get(x_1, 1);
lean_inc(x_33);
lean_inc(x_32);
lean_dec(x_1);
x_34 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5));
x_35 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__6));
x_36 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7, &lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7);
x_37 = l_String_quote(x_32);
x_38 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_38, 0, x_37);
x_39 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_39, 0, x_36);
lean_ctor_set(x_39, 1, x_38);
x_40 = 0;
x_41 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_41, 0, x_39);
lean_ctor_set_uint8(x_41, sizeof(void*)*1, x_40);
x_42 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_42, 0, x_35);
lean_ctor_set(x_42, 1, x_41);
x_43 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__9));
x_44 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_44, 0, x_42);
lean_ctor_set(x_44, 1, x_43);
x_45 = lean_box(1);
x_46 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_46, 0, x_44);
lean_ctor_set(x_46, 1, x_45);
x_47 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__11));
x_48 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_48, 0, x_46);
lean_ctor_set(x_48, 1, x_47);
x_49 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_49, 0, x_48);
lean_ctor_set(x_49, 1, x_34);
x_50 = l_Nat_reprFast(x_33);
x_51 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_51, 0, x_50);
x_52 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_52, 0, x_36);
lean_ctor_set(x_52, 1, x_51);
x_53 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_53, 0, x_52);
lean_ctor_set_uint8(x_53, sizeof(void*)*1, x_40);
x_54 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_54, 0, x_49);
lean_ctor_set(x_54, 1, x_53);
x_55 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14, &lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14);
x_56 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__15));
x_57 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_57, 0, x_56);
lean_ctor_set(x_57, 1, x_54);
x_58 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__16));
x_59 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_59, 0, x_57);
lean_ctor_set(x_59, 1, x_58);
x_60 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_60, 0, x_55);
lean_ctor_set(x_60, 1, x_59);
x_61 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_61, 0, x_60);
lean_ctor_set_uint8(x_61, sizeof(void*)*1, x_40);
return x_61;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr(x_1, x_2);
lean_dec(x_2);
return x_3;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqSalt_beq(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; uint8_t x_7; 
x_3 = lean_ctor_get(x_1, 0);
x_4 = lean_ctor_get(x_1, 1);
x_5 = lean_ctor_get(x_2, 0);
x_6 = lean_ctor_get(x_2, 1);
x_7 = lean_string_dec_eq(x_3, x_5);
if (x_7 == 0)
{
return x_7;
}
else
{
uint8_t x_8; 
x_8 = lean_nat_dec_eq(x_4, x_6);
return x_8;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqSalt_beq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instBEqSalt_beq(x_1, x_2);
lean_dec_ref(x_2);
lean_dec_ref(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_Salt_initial(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; 
x_2 = lean_unsigned_to_nat(0u);
x_3 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_Salt_rotate(lean_object* x_1) {
_start:
{
uint8_t x_2; 
x_2 = !lean_is_exclusive(x_1);
if (x_2 == 0)
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; 
x_3 = lean_ctor_get(x_1, 1);
x_4 = lean_unsigned_to_nat(1u);
x_5 = lean_nat_add(x_3, x_4);
lean_dec(x_3);
lean_ctor_set(x_1, 1, x_5);
return x_1;
}
else
{
lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; 
x_6 = lean_ctor_get(x_1, 0);
x_7 = lean_ctor_get(x_1, 1);
lean_inc(x_7);
lean_inc(x_6);
lean_dec(x_1);
x_8 = lean_unsigned_to_nat(1u);
x_9 = lean_nat_add(x_7, x_8);
lean_dec(x_7);
x_10 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_10, 0, x_6);
lean_ctor_set(x_10, 1, x_9);
return x_10;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_Salt_material(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; 
x_2 = lean_ctor_get(x_1, 0);
lean_inc_ref(x_2);
x_3 = lean_ctor_get(x_1, 1);
lean_inc(x_3);
lean_dec_ref(x_1);
x_4 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_Salt_material___closed__0));
x_5 = lean_string_append(x_2, x_4);
x_6 = l_Nat_reprFast(x_3);
x_7 = lean_string_append(x_5, x_6);
lean_dec_ref(x_6);
return x_7;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqPasswordHash_decEq(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; 
x_3 = lean_nat_dec_eq(x_1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqPasswordHash_decEq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqPasswordHash_decEq(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqPasswordHash(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; 
x_3 = lean_nat_dec_eq(x_1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqPasswordHash___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqPasswordHash(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__4(void) {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(10u);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; uint8_t x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; 
x_2 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__3));
x_3 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__4);
x_4 = l_Nat_reprFast(x_1);
x_5 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_5, 0, x_4);
x_6 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_6, 0, x_3);
lean_ctor_set(x_6, 1, x_5);
x_7 = 0;
x_8 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_8, 0, x_6);
lean_ctor_set_uint8(x_8, sizeof(void*)*1, x_7);
x_9 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_9, 0, x_2);
lean_ctor_set(x_9, 1, x_8);
x_10 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14, &lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14);
x_11 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__15));
x_12 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_12, 0, x_11);
lean_ctor_set(x_12, 1, x_9);
x_13 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__16));
x_14 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_14, 0, x_12);
lean_ctor_set(x_14, 1, x_13);
x_15 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_15, 0, x_10);
lean_ctor_set(x_15, 1, x_14);
x_16 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_16, 0, x_15);
lean_ctor_set_uint8(x_16, sizeof(void*)*1, x_7);
return x_16;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr(x_1, x_2);
lean_dec(x_2);
return x_3;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqPasswordHash_beq(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; 
x_3 = lean_nat_dec_eq(x_1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqPasswordHash_beq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instBEqPasswordHash_beq(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedPasswordHash_default(void) {
_start:
{
lean_object* x_1; 
x_1 = lean_unsigned_to_nat(0u);
return x_1;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedPasswordHash(void) {
_start:
{
lean_object* x_1; 
x_1 = lean_unsigned_to_nat(0u);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec___private_VerifiableAuth_Types_0__VerifiableAuth_digestChar(lean_object* x_1, uint32_t x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; 
x_3 = lean_unsigned_to_nat(16777619u);
x_4 = lean_nat_mul(x_1, x_3);
x_5 = lean_uint32_to_nat(x_2);
x_6 = lean_nat_add(x_4, x_5);
lean_dec(x_5);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec___private_VerifiableAuth_Types_0__VerifiableAuth_digestChar___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint32_t x_3; lean_object* x_4; 
x_3 = lean_unbox_uint32(x_2);
lean_dec(x_2);
x_4 = lp_VerifiableAuthSpec___private_VerifiableAuth_Types_0__VerifiableAuth_digestChar(x_1, x_3);
lean_dec(x_1);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_List_foldl___at___00__private_VerifiableAuth_Types_0__VerifiableAuth_digestString_spec__0(lean_object* x_1, lean_object* x_2) {
_start:
{
if (lean_obj_tag(x_2) == 0)
{
return x_1;
}
else
{
lean_object* x_3; lean_object* x_4; uint32_t x_5; lean_object* x_6; 
x_3 = lean_ctor_get(x_2, 0);
x_4 = lean_ctor_get(x_2, 1);
x_5 = lean_unbox_uint32(x_3);
x_6 = lp_VerifiableAuthSpec___private_VerifiableAuth_Types_0__VerifiableAuth_digestChar(x_1, x_5);
lean_dec(x_1);
x_1 = x_6;
x_2 = x_4;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_List_foldl___at___00__private_VerifiableAuth_Types_0__VerifiableAuth_digestString_spec__0___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_List_foldl___at___00__private_VerifiableAuth_Types_0__VerifiableAuth_digestString_spec__0(x_1, x_2);
lean_dec(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec___private_VerifiableAuth_Types_0__VerifiableAuth_digestString(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; 
x_3 = lean_string_data(x_2);
x_4 = lp_VerifiableAuthSpec_List_foldl___at___00__private_VerifiableAuth_Types_0__VerifiableAuth_digestString_spec__0(x_1, x_3);
lean_dec(x_3);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_derivePasswordHash(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; 
x_3 = lean_unsigned_to_nat(2166136261u);
x_4 = lp_VerifiableAuthSpec___private_VerifiableAuth_Types_0__VerifiableAuth_digestString(x_3, x_1);
x_5 = lp_VerifiableAuthSpec_VerifiableAuth_Salt_material(x_2);
x_6 = lp_VerifiableAuthSpec___private_VerifiableAuth_Types_0__VerifiableAuth_digestString(x_4, x_5);
return x_6;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqUser_decEq(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; uint8_t x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; uint8_t x_12; uint8_t x_13; 
x_3 = lean_ctor_get(x_1, 0);
x_4 = lean_ctor_get(x_1, 1);
x_5 = lean_ctor_get(x_1, 2);
x_6 = lean_ctor_get(x_1, 3);
x_7 = lean_ctor_get_uint8(x_1, sizeof(void*)*4);
x_8 = lean_ctor_get(x_2, 0);
x_9 = lean_ctor_get(x_2, 1);
x_10 = lean_ctor_get(x_2, 2);
x_11 = lean_ctor_get(x_2, 3);
x_12 = lean_ctor_get_uint8(x_2, sizeof(void*)*4);
x_13 = lean_string_dec_eq(x_3, x_8);
if (x_13 == 0)
{
return x_13;
}
else
{
uint8_t x_14; 
x_14 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqSalt_decEq(x_4, x_9);
if (x_14 == 0)
{
return x_14;
}
else
{
uint8_t x_15; 
x_15 = lean_nat_dec_eq(x_5, x_10);
if (x_15 == 0)
{
return x_15;
}
else
{
uint8_t x_16; 
x_16 = lean_nat_dec_eq(x_6, x_11);
if (x_16 == 0)
{
return x_16;
}
else
{
uint8_t x_17; 
x_17 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqLockState(x_7, x_12);
return x_17;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqUser_decEq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqUser_decEq(x_1, x_2);
lean_dec_ref(x_2);
lean_dec_ref(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqUser(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqUser_decEq(x_1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqUser___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqUser(x_1, x_2);
lean_dec_ref(x_2);
lean_dec_ref(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__4(void) {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(11u);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__7(void) {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(8u);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__10(void) {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(16u);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__13(void) {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(18u);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__16(void) {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(13u);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; lean_object* x_4; lean_object* x_5; uint8_t x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; uint8_t x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; lean_object* x_22; lean_object* x_23; lean_object* x_24; lean_object* x_25; lean_object* x_26; lean_object* x_27; lean_object* x_28; lean_object* x_29; lean_object* x_30; lean_object* x_31; lean_object* x_32; lean_object* x_33; lean_object* x_34; lean_object* x_35; lean_object* x_36; lean_object* x_37; lean_object* x_38; lean_object* x_39; lean_object* x_40; lean_object* x_41; lean_object* x_42; lean_object* x_43; lean_object* x_44; lean_object* x_45; lean_object* x_46; lean_object* x_47; lean_object* x_48; lean_object* x_49; lean_object* x_50; lean_object* x_51; lean_object* x_52; lean_object* x_53; lean_object* x_54; lean_object* x_55; lean_object* x_56; lean_object* x_57; lean_object* x_58; lean_object* x_59; lean_object* x_60; lean_object* x_61; lean_object* x_62; lean_object* x_63; lean_object* x_64; lean_object* x_65; lean_object* x_66; 
x_2 = lean_ctor_get(x_1, 0);
lean_inc_ref(x_2);
x_3 = lean_ctor_get(x_1, 1);
lean_inc_ref(x_3);
x_4 = lean_ctor_get(x_1, 2);
lean_inc(x_4);
x_5 = lean_ctor_get(x_1, 3);
lean_inc(x_5);
x_6 = lean_ctor_get_uint8(x_1, sizeof(void*)*4);
lean_dec_ref(x_1);
x_7 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5));
x_8 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__3));
x_9 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__4);
x_10 = l_String_quote(x_2);
x_11 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_11, 0, x_10);
x_12 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_12, 0, x_9);
lean_ctor_set(x_12, 1, x_11);
x_13 = 0;
x_14 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_14, 0, x_12);
lean_ctor_set_uint8(x_14, sizeof(void*)*1, x_13);
x_15 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_15, 0, x_8);
lean_ctor_set(x_15, 1, x_14);
x_16 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__9));
x_17 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_17, 0, x_15);
lean_ctor_set(x_17, 1, x_16);
x_18 = lean_box(1);
x_19 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_19, 0, x_17);
lean_ctor_set(x_19, 1, x_18);
x_20 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__6));
x_21 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_21, 0, x_19);
lean_ctor_set(x_21, 1, x_20);
x_22 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_22, 0, x_21);
lean_ctor_set(x_22, 1, x_7);
x_23 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__7, &lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__7_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__7);
x_24 = lean_unsigned_to_nat(0u);
x_25 = lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg(x_3);
x_26 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_26, 0, x_23);
lean_ctor_set(x_26, 1, x_25);
x_27 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_27, 0, x_26);
lean_ctor_set_uint8(x_27, sizeof(void*)*1, x_13);
x_28 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_28, 0, x_22);
lean_ctor_set(x_28, 1, x_27);
x_29 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_29, 0, x_28);
lean_ctor_set(x_29, 1, x_16);
x_30 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_30, 0, x_29);
lean_ctor_set(x_30, 1, x_18);
x_31 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__9));
x_32 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_32, 0, x_30);
lean_ctor_set(x_32, 1, x_31);
x_33 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_33, 0, x_32);
lean_ctor_set(x_33, 1, x_7);
x_34 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__10, &lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__10_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__10);
x_35 = lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg(x_4);
x_36 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_36, 0, x_34);
lean_ctor_set(x_36, 1, x_35);
x_37 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_37, 0, x_36);
lean_ctor_set_uint8(x_37, sizeof(void*)*1, x_13);
x_38 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_38, 0, x_33);
lean_ctor_set(x_38, 1, x_37);
x_39 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_39, 0, x_38);
lean_ctor_set(x_39, 1, x_16);
x_40 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_40, 0, x_39);
lean_ctor_set(x_40, 1, x_18);
x_41 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__12));
x_42 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_42, 0, x_40);
lean_ctor_set(x_42, 1, x_41);
x_43 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_43, 0, x_42);
lean_ctor_set(x_43, 1, x_7);
x_44 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__13, &lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__13_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__13);
x_45 = l_Nat_reprFast(x_5);
x_46 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_46, 0, x_45);
x_47 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_47, 0, x_44);
lean_ctor_set(x_47, 1, x_46);
x_48 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_48, 0, x_47);
lean_ctor_set_uint8(x_48, sizeof(void*)*1, x_13);
x_49 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_49, 0, x_43);
lean_ctor_set(x_49, 1, x_48);
x_50 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_50, 0, x_49);
lean_ctor_set(x_50, 1, x_16);
x_51 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_51, 0, x_50);
lean_ctor_set(x_51, 1, x_18);
x_52 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__15));
x_53 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_53, 0, x_51);
lean_ctor_set(x_53, 1, x_52);
x_54 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_54, 0, x_53);
lean_ctor_set(x_54, 1, x_7);
x_55 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__16, &lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__16_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__16);
x_56 = lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr(x_6, x_24);
x_57 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_57, 0, x_55);
lean_ctor_set(x_57, 1, x_56);
x_58 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_58, 0, x_57);
lean_ctor_set_uint8(x_58, sizeof(void*)*1, x_13);
x_59 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_59, 0, x_54);
lean_ctor_set(x_59, 1, x_58);
x_60 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14, &lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14);
x_61 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__15));
x_62 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_62, 0, x_61);
lean_ctor_set(x_62, 1, x_59);
x_63 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__16));
x_64 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_64, 0, x_62);
lean_ctor_set(x_64, 1, x_63);
x_65 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_65, 0, x_60);
lean_ctor_set(x_65, 1, x_64);
x_66 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_66, 0, x_65);
lean_ctor_set_uint8(x_66, sizeof(void*)*1, x_13);
return x_66;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr(x_1, x_2);
lean_dec(x_2);
return x_3;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqUser_beq(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; uint8_t x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; uint8_t x_12; uint8_t x_13; 
x_3 = lean_ctor_get(x_1, 0);
x_4 = lean_ctor_get(x_1, 1);
x_5 = lean_ctor_get(x_1, 2);
x_6 = lean_ctor_get(x_1, 3);
x_7 = lean_ctor_get_uint8(x_1, sizeof(void*)*4);
x_8 = lean_ctor_get(x_2, 0);
x_9 = lean_ctor_get(x_2, 1);
x_10 = lean_ctor_get(x_2, 2);
x_11 = lean_ctor_get(x_2, 3);
x_12 = lean_ctor_get_uint8(x_2, sizeof(void*)*4);
x_13 = lean_string_dec_eq(x_3, x_8);
if (x_13 == 0)
{
return x_13;
}
else
{
uint8_t x_14; 
x_14 = lp_VerifiableAuthSpec_VerifiableAuth_instBEqSalt_beq(x_4, x_9);
if (x_14 == 0)
{
return x_14;
}
else
{
uint8_t x_15; 
x_15 = lean_nat_dec_eq(x_5, x_10);
if (x_15 == 0)
{
return x_15;
}
else
{
uint8_t x_16; 
x_16 = lean_nat_dec_eq(x_6, x_11);
if (x_16 == 0)
{
return x_16;
}
else
{
uint8_t x_17; 
x_17 = lp_VerifiableAuthSpec_VerifiableAuth_instBEqLockState_beq(x_7, x_12);
return x_17;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqUser_beq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instBEqUser_beq(x_1, x_2);
lean_dec_ref(x_2);
lean_dec_ref(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuthState_decEq(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; uint8_t x_8; 
x_3 = lean_ctor_get(x_1, 0);
lean_inc(x_3);
x_4 = lean_ctor_get(x_1, 1);
lean_inc(x_4);
lean_dec_ref(x_1);
x_5 = lean_ctor_get(x_2, 0);
lean_inc(x_5);
x_6 = lean_ctor_get(x_2, 1);
lean_inc(x_6);
lean_dec_ref(x_2);
x_7 = lean_alloc_closure((void*)(lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqUser___boxed), 2, 0);
x_8 = l_instDecidableEqList___redArg(x_7, x_3, x_5);
if (x_8 == 0)
{
lean_dec(x_6);
lean_dec(x_4);
return x_8;
}
else
{
lean_object* x_9; uint8_t x_10; 
x_9 = lean_alloc_closure((void*)(l_instDecidableEqString___boxed), 2, 0);
x_10 = l_Option_instDecidableEq___redArg(x_9, x_4, x_6);
return x_10;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuthState_decEq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuthState_decEq(x_1, x_2);
x_4 = lean_box(x_3);
return x_4;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuthState(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuthState_decEq(x_1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuthState___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuthState(x_1, x_2);
x_4 = lean_box(x_3);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1(lean_object* x_1, lean_object* x_2) {
_start:
{
if (lean_obj_tag(x_1) == 0)
{
lean_object* x_3; 
x_3 = ((lean_object*)(lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___closed__1));
return x_3;
}
else
{
uint8_t x_4; 
x_4 = !lean_is_exclusive(x_1);
if (x_4 == 0)
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; 
x_5 = lean_ctor_get(x_1, 0);
x_6 = ((lean_object*)(lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___closed__3));
x_7 = l_String_quote(x_5);
lean_ctor_set_tag(x_1, 3);
lean_ctor_set(x_1, 0, x_7);
x_8 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_8, 0, x_6);
lean_ctor_set(x_8, 1, x_1);
x_9 = l_Repr_addAppParen(x_8, x_2);
return x_9;
}
else
{
lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; 
x_10 = lean_ctor_get(x_1, 0);
lean_inc(x_10);
lean_dec(x_1);
x_11 = ((lean_object*)(lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___closed__3));
x_12 = l_String_quote(x_10);
x_13 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_13, 0, x_12);
x_14 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_14, 0, x_11);
lean_ctor_set(x_14, 1, x_13);
x_15 = l_Repr_addAppParen(x_14, x_2);
return x_15;
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1(x_1, x_2);
lean_dec(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_List_foldl___at___00List_foldl___at___00Std_Format_joinSep___at___00List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0_spec__0_spec__2_spec__3(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
if (lean_obj_tag(x_3) == 0)
{
lean_dec(x_1);
return x_2;
}
else
{
uint8_t x_4; 
x_4 = !lean_is_exclusive(x_3);
if (x_4 == 0)
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; 
x_5 = lean_ctor_get(x_3, 0);
x_6 = lean_ctor_get(x_3, 1);
lean_inc(x_1);
lean_ctor_set_tag(x_3, 5);
lean_ctor_set(x_3, 1, x_1);
lean_ctor_set(x_3, 0, x_2);
x_7 = lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg(x_5);
x_8 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_8, 0, x_3);
lean_ctor_set(x_8, 1, x_7);
x_2 = x_8;
x_3 = x_6;
goto _start;
}
else
{
lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; 
x_10 = lean_ctor_get(x_3, 0);
x_11 = lean_ctor_get(x_3, 1);
lean_inc(x_11);
lean_inc(x_10);
lean_dec(x_3);
lean_inc(x_1);
x_12 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_12, 0, x_2);
lean_ctor_set(x_12, 1, x_1);
x_13 = lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg(x_10);
x_14 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_14, 0, x_12);
lean_ctor_set(x_14, 1, x_13);
x_2 = x_14;
x_3 = x_11;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_List_foldl___at___00Std_Format_joinSep___at___00List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0_spec__0_spec__2(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
if (lean_obj_tag(x_3) == 0)
{
lean_dec(x_1);
return x_2;
}
else
{
uint8_t x_4; 
x_4 = !lean_is_exclusive(x_3);
if (x_4 == 0)
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; 
x_5 = lean_ctor_get(x_3, 0);
x_6 = lean_ctor_get(x_3, 1);
lean_inc(x_1);
lean_ctor_set_tag(x_3, 5);
lean_ctor_set(x_3, 1, x_1);
lean_ctor_set(x_3, 0, x_2);
x_7 = lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg(x_5);
x_8 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_8, 0, x_3);
lean_ctor_set(x_8, 1, x_7);
x_9 = lp_VerifiableAuthSpec_List_foldl___at___00List_foldl___at___00Std_Format_joinSep___at___00List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0_spec__0_spec__2_spec__3(x_1, x_8, x_6);
return x_9;
}
else
{
lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; 
x_10 = lean_ctor_get(x_3, 0);
x_11 = lean_ctor_get(x_3, 1);
lean_inc(x_11);
lean_inc(x_10);
lean_dec(x_3);
lean_inc(x_1);
x_12 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_12, 0, x_2);
lean_ctor_set(x_12, 1, x_1);
x_13 = lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg(x_10);
x_14 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_14, 0, x_12);
lean_ctor_set(x_14, 1, x_13);
x_15 = lp_VerifiableAuthSpec_List_foldl___at___00List_foldl___at___00Std_Format_joinSep___at___00List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0_spec__0_spec__2_spec__3(x_1, x_14, x_11);
return x_15;
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_Std_Format_joinSep___at___00List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0_spec__0(lean_object* x_1, lean_object* x_2) {
_start:
{
if (lean_obj_tag(x_1) == 0)
{
lean_object* x_3; 
lean_dec(x_2);
x_3 = lean_box(0);
return x_3;
}
else
{
lean_object* x_4; 
x_4 = lean_ctor_get(x_1, 1);
if (lean_obj_tag(x_4) == 0)
{
lean_object* x_5; lean_object* x_6; 
lean_dec(x_2);
x_5 = lean_ctor_get(x_1, 0);
lean_inc(x_5);
lean_dec_ref(x_1);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg(x_5);
return x_6;
}
else
{
lean_object* x_7; lean_object* x_8; lean_object* x_9; 
lean_inc(x_4);
x_7 = lean_ctor_get(x_1, 0);
lean_inc(x_7);
lean_dec_ref(x_1);
x_8 = lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg(x_7);
x_9 = lp_VerifiableAuthSpec_List_foldl___at___00Std_Format_joinSep___at___00List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0_spec__0_spec__2(x_2, x_8, x_4);
return x_9;
}
}
}
}
static lean_object* _init_lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__5(void) {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = ((lean_object*)(lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__2));
x_2 = lean_string_length(x_1);
return x_2;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__6(void) {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_obj_once(&lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__5, &lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__5_once, _init_lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__5);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg(lean_object* x_1) {
_start:
{
if (lean_obj_tag(x_1) == 0)
{
lean_object* x_2; 
x_2 = ((lean_object*)(lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__1));
return x_2;
}
else
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; uint8_t x_11; lean_object* x_12; 
x_3 = ((lean_object*)(lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__3));
x_4 = lp_VerifiableAuthSpec_Std_Format_joinSep___at___00List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0_spec__0(x_1, x_3);
x_5 = lean_obj_once(&lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__6, &lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__6_once, _init_lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__6);
x_6 = ((lean_object*)(lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__7));
x_7 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_7, 0, x_6);
lean_ctor_set(x_7, 1, x_4);
x_8 = ((lean_object*)(lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg___closed__8));
x_9 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_9, 0, x_7);
lean_ctor_set(x_9, 1, x_8);
x_10 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_10, 0, x_5);
lean_ctor_set(x_10, 1, x_9);
x_11 = 0;
x_12 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_12, 0, x_10);
lean_ctor_set_uint8(x_12, sizeof(void*)*1, x_11);
return x_12;
}
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__6(void) {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(17u);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg(lean_object* x_1) {
_start:
{
uint8_t x_2; 
x_2 = !lean_is_exclusive(x_1);
if (x_2 == 0)
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; uint8_t x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; lean_object* x_22; lean_object* x_23; lean_object* x_24; lean_object* x_25; lean_object* x_26; lean_object* x_27; lean_object* x_28; lean_object* x_29; lean_object* x_30; lean_object* x_31; 
x_3 = lean_ctor_get(x_1, 0);
x_4 = lean_ctor_get(x_1, 1);
x_5 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5));
x_6 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__3));
x_7 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7, &lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7);
x_8 = lean_unsigned_to_nat(0u);
x_9 = lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg(x_3);
lean_ctor_set_tag(x_1, 4);
lean_ctor_set(x_1, 1, x_9);
lean_ctor_set(x_1, 0, x_7);
x_10 = 0;
x_11 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_11, 0, x_1);
lean_ctor_set_uint8(x_11, sizeof(void*)*1, x_10);
x_12 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_12, 0, x_6);
lean_ctor_set(x_12, 1, x_11);
x_13 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__9));
x_14 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_14, 0, x_12);
lean_ctor_set(x_14, 1, x_13);
x_15 = lean_box(1);
x_16 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_16, 0, x_14);
lean_ctor_set(x_16, 1, x_15);
x_17 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__5));
x_18 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_18, 0, x_16);
lean_ctor_set(x_18, 1, x_17);
x_19 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_19, 0, x_18);
lean_ctor_set(x_19, 1, x_5);
x_20 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__6, &lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__6_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__6);
x_21 = lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1(x_4, x_8);
x_22 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_22, 0, x_20);
lean_ctor_set(x_22, 1, x_21);
x_23 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_23, 0, x_22);
lean_ctor_set_uint8(x_23, sizeof(void*)*1, x_10);
x_24 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_24, 0, x_19);
lean_ctor_set(x_24, 1, x_23);
x_25 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14, &lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14);
x_26 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__15));
x_27 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_27, 0, x_26);
lean_ctor_set(x_27, 1, x_24);
x_28 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__16));
x_29 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_29, 0, x_27);
lean_ctor_set(x_29, 1, x_28);
x_30 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_30, 0, x_25);
lean_ctor_set(x_30, 1, x_29);
x_31 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_31, 0, x_30);
lean_ctor_set_uint8(x_31, sizeof(void*)*1, x_10);
return x_31;
}
else
{
lean_object* x_32; lean_object* x_33; lean_object* x_34; lean_object* x_35; lean_object* x_36; lean_object* x_37; lean_object* x_38; lean_object* x_39; uint8_t x_40; lean_object* x_41; lean_object* x_42; lean_object* x_43; lean_object* x_44; lean_object* x_45; lean_object* x_46; lean_object* x_47; lean_object* x_48; lean_object* x_49; lean_object* x_50; lean_object* x_51; lean_object* x_52; lean_object* x_53; lean_object* x_54; lean_object* x_55; lean_object* x_56; lean_object* x_57; lean_object* x_58; lean_object* x_59; lean_object* x_60; lean_object* x_61; 
x_32 = lean_ctor_get(x_1, 0);
x_33 = lean_ctor_get(x_1, 1);
lean_inc(x_33);
lean_inc(x_32);
lean_dec(x_1);
x_34 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5));
x_35 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__3));
x_36 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7, &lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7);
x_37 = lean_unsigned_to_nat(0u);
x_38 = lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg(x_32);
x_39 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_39, 0, x_36);
lean_ctor_set(x_39, 1, x_38);
x_40 = 0;
x_41 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_41, 0, x_39);
lean_ctor_set_uint8(x_41, sizeof(void*)*1, x_40);
x_42 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_42, 0, x_35);
lean_ctor_set(x_42, 1, x_41);
x_43 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__9));
x_44 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_44, 0, x_42);
lean_ctor_set(x_44, 1, x_43);
x_45 = lean_box(1);
x_46 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_46, 0, x_44);
lean_ctor_set(x_46, 1, x_45);
x_47 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__5));
x_48 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_48, 0, x_46);
lean_ctor_set(x_48, 1, x_47);
x_49 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_49, 0, x_48);
lean_ctor_set(x_49, 1, x_34);
x_50 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__6, &lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__6_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg___closed__6);
x_51 = lp_VerifiableAuthSpec_Option_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__1(x_33, x_37);
x_52 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_52, 0, x_50);
lean_ctor_set(x_52, 1, x_51);
x_53 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_53, 0, x_52);
lean_ctor_set_uint8(x_53, sizeof(void*)*1, x_40);
x_54 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_54, 0, x_49);
lean_ctor_set(x_54, 1, x_53);
x_55 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14, &lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14);
x_56 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__15));
x_57 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_57, 0, x_56);
lean_ctor_set(x_57, 1, x_54);
x_58 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__16));
x_59 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_59, 0, x_57);
lean_ctor_set(x_59, 1, x_58);
x_60 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_60, 0, x_55);
lean_ctor_set(x_60, 1, x_59);
x_61 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_61, 0, x_60);
lean_ctor_set_uint8(x_61, sizeof(void*)*1, x_40);
return x_61;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr(x_1, x_2);
lean_dec(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___redArg(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_List_repr___at___00VerifiableAuth_instReprAuthState_repr_spec__0(x_1, x_2);
lean_dec(x_2);
return x_3;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_Option_instBEq_beq___at___00VerifiableAuth_instBEqAuthState_beq_spec__1(lean_object* x_1, lean_object* x_2) {
_start:
{
if (lean_obj_tag(x_1) == 0)
{
if (lean_obj_tag(x_2) == 0)
{
uint8_t x_3; 
x_3 = 1;
return x_3;
}
else
{
uint8_t x_4; 
x_4 = 0;
return x_4;
}
}
else
{
if (lean_obj_tag(x_2) == 0)
{
uint8_t x_5; 
x_5 = 0;
return x_5;
}
else
{
lean_object* x_6; lean_object* x_7; uint8_t x_8; 
x_6 = lean_ctor_get(x_1, 0);
x_7 = lean_ctor_get(x_2, 0);
x_8 = lean_string_dec_eq(x_6, x_7);
return x_8;
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_Option_instBEq_beq___at___00VerifiableAuth_instBEqAuthState_beq_spec__1___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_Option_instBEq_beq___at___00VerifiableAuth_instBEqAuthState_beq_spec__1(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_List_beq___at___00VerifiableAuth_instBEqAuthState_beq_spec__0(lean_object* x_1, lean_object* x_2) {
_start:
{
if (lean_obj_tag(x_1) == 0)
{
if (lean_obj_tag(x_2) == 0)
{
uint8_t x_3; 
x_3 = 1;
return x_3;
}
else
{
uint8_t x_4; 
x_4 = 0;
return x_4;
}
}
else
{
if (lean_obj_tag(x_2) == 0)
{
uint8_t x_5; 
x_5 = 0;
return x_5;
}
else
{
lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; uint8_t x_10; 
x_6 = lean_ctor_get(x_1, 0);
x_7 = lean_ctor_get(x_1, 1);
x_8 = lean_ctor_get(x_2, 0);
x_9 = lean_ctor_get(x_2, 1);
x_10 = lp_VerifiableAuthSpec_VerifiableAuth_instBEqUser_beq(x_6, x_8);
if (x_10 == 0)
{
return x_10;
}
else
{
x_1 = x_7;
x_2 = x_9;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_List_beq___at___00VerifiableAuth_instBEqAuthState_beq_spec__0___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_List_beq___at___00VerifiableAuth_instBEqAuthState_beq_spec__0(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuthState_beq(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; uint8_t x_7; 
x_3 = lean_ctor_get(x_1, 0);
x_4 = lean_ctor_get(x_1, 1);
x_5 = lean_ctor_get(x_2, 0);
x_6 = lean_ctor_get(x_2, 1);
x_7 = lp_VerifiableAuthSpec_List_beq___at___00VerifiableAuth_instBEqAuthState_beq_spec__0(x_3, x_5);
if (x_7 == 0)
{
return x_7;
}
else
{
uint8_t x_8; 
x_8 = lp_VerifiableAuthSpec_Option_instBEq_beq___at___00VerifiableAuth_instBEqAuthState_beq_spec__1(x_4, x_6);
return x_8;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuthState_beq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuthState_beq(x_1, x_2);
lean_dec_ref(x_2);
lean_dec_ref(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorIdx(uint8_t x_1) {
_start:
{
if (x_1 == 0)
{
lean_object* x_2; 
x_2 = lean_unsigned_to_nat(0u);
return x_2;
}
else
{
lean_object* x_3; 
x_3 = lean_unsigned_to_nat(1u);
return x_3;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorIdx___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = lean_unbox(x_1);
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorIdx(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_toCtorIdx(uint8_t x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorIdx(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_toCtorIdx___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = lean_unbox(x_1);
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_toCtorIdx(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorElim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorElim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorElim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorElim(lean_object* x_1, lean_object* x_2, uint8_t x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
lean_inc(x_5);
return x_5;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorElim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
uint8_t x_6; lean_object* x_7; 
x_6 = lean_unbox(x_3);
x_7 = lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorElim(x_1, x_2, x_6, x_4, x_5);
lean_dec(x_5);
lean_dec(x_2);
return x_7;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_success_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_success_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_success_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_success_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_success_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_success_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_duplicate_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_duplicate_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_duplicate_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_duplicate_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_duplicate_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_duplicate_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ofNat(lean_object* x_1) {
_start:
{
lean_object* x_2; uint8_t x_3; 
x_2 = lean_unsigned_to_nat(0u);
x_3 = lean_nat_dec_le(x_1, x_2);
if (x_3 == 0)
{
uint8_t x_4; 
x_4 = 1;
return x_4;
}
else
{
uint8_t x_5; 
x_5 = 0;
return x_5;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ofNat___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ofNat(x_1);
lean_dec(x_1);
x_3 = lean_box(x_2);
return x_3;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqRegisterResult(uint8_t x_1, uint8_t x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; uint8_t x_5; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorIdx(x_1);
x_4 = lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorIdx(x_2);
x_5 = lean_nat_dec_eq(x_3, x_4);
lean_dec(x_4);
lean_dec(x_3);
return x_5;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqRegisterResult___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; uint8_t x_4; uint8_t x_5; lean_object* x_6; 
x_3 = lean_unbox(x_1);
x_4 = lean_unbox(x_2);
x_5 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqRegisterResult(x_3, x_4);
x_6 = lean_box(x_5);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr(uint8_t x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_10; 
if (x_1 == 0)
{
lean_object* x_17; uint8_t x_18; 
x_17 = lean_unsigned_to_nat(1024u);
x_18 = lean_nat_dec_le(x_17, x_2);
if (x_18 == 0)
{
lean_object* x_19; 
x_19 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_3 = x_19;
goto block_9;
}
else
{
lean_object* x_20; 
x_20 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_3 = x_20;
goto block_9;
}
}
else
{
lean_object* x_21; uint8_t x_22; 
x_21 = lean_unsigned_to_nat(1024u);
x_22 = lean_nat_dec_le(x_21, x_2);
if (x_22 == 0)
{
lean_object* x_23; 
x_23 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_10 = x_23;
goto block_16;
}
else
{
lean_object* x_24; 
x_24 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_10 = x_24;
goto block_16;
}
}
block_9:
{
lean_object* x_4; lean_object* x_5; uint8_t x_6; lean_object* x_7; lean_object* x_8; 
x_4 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___closed__1));
x_5 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_5, 0, x_3);
lean_ctor_set(x_5, 1, x_4);
x_6 = 0;
x_7 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_7, 0, x_5);
lean_ctor_set_uint8(x_7, sizeof(void*)*1, x_6);
x_8 = l_Repr_addAppParen(x_7, x_2);
return x_8;
}
block_16:
{
lean_object* x_11; lean_object* x_12; uint8_t x_13; lean_object* x_14; lean_object* x_15; 
x_11 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___closed__3));
x_12 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_12, 0, x_10);
lean_ctor_set(x_12, 1, x_11);
x_13 = 0;
x_14 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_14, 0, x_12);
lean_ctor_set_uint8(x_14, sizeof(void*)*1, x_13);
x_15 = l_Repr_addAppParen(x_14, x_2);
return x_15;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lean_unbox(x_1);
x_4 = lp_VerifiableAuthSpec_VerifiableAuth_instReprRegisterResult_repr(x_3, x_2);
lean_dec(x_2);
return x_4;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqRegisterResult_beq(uint8_t x_1, uint8_t x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; uint8_t x_5; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorIdx(x_1);
x_4 = lp_VerifiableAuthSpec_VerifiableAuth_RegisterResult_ctorIdx(x_2);
x_5 = lean_nat_dec_eq(x_3, x_4);
lean_dec(x_4);
lean_dec(x_3);
return x_5;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqRegisterResult_beq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; uint8_t x_4; uint8_t x_5; lean_object* x_6; 
x_3 = lean_unbox(x_1);
x_4 = lean_unbox(x_2);
x_5 = lp_VerifiableAuthSpec_VerifiableAuth_instBEqRegisterResult_beq(x_3, x_4);
x_6 = lean_box(x_5);
return x_6;
}
}
static uint8_t _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedRegisterResult_default(void) {
_start:
{
uint8_t x_1; 
x_1 = 0;
return x_1;
}
}
static uint8_t _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedRegisterResult(void) {
_start:
{
uint8_t x_1; 
x_1 = 0;
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorIdx(uint8_t x_1) {
_start:
{
switch (x_1) {
case 0:
{
lean_object* x_2; 
x_2 = lean_unsigned_to_nat(0u);
return x_2;
}
case 1:
{
lean_object* x_3; 
x_3 = lean_unsigned_to_nat(1u);
return x_3;
}
case 2:
{
lean_object* x_4; 
x_4 = lean_unsigned_to_nat(2u);
return x_4;
}
case 3:
{
lean_object* x_5; 
x_5 = lean_unsigned_to_nat(3u);
return x_5;
}
default: 
{
lean_object* x_6; 
x_6 = lean_unsigned_to_nat(4u);
return x_6;
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorIdx___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = lean_unbox(x_1);
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorIdx(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_toCtorIdx(uint8_t x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorIdx(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_toCtorIdx___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = lean_unbox(x_1);
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_toCtorIdx(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorElim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorElim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorElim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorElim(lean_object* x_1, lean_object* x_2, uint8_t x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
lean_inc(x_5);
return x_5;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorElim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
uint8_t x_6; lean_object* x_7; 
x_6 = lean_unbox(x_3);
x_7 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorElim(x_1, x_2, x_6, x_4, x_5);
lean_dec(x_5);
lean_dec(x_2);
return x_7;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_success_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_success_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_success_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_success_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_success_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_success_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_unknownUser_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_unknownUser_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_unknownUser_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_unknownUser_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_unknownUser_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_unknownUser_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_lockedOut_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_lockedOut_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_lockedOut_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_lockedOut_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_lockedOut_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_lockedOut_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_wrongPassword_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_wrongPassword_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_wrongPassword_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_wrongPassword_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_wrongPassword_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_wrongPassword_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_alreadyAuthenticated_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_alreadyAuthenticated_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_alreadyAuthenticated_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_alreadyAuthenticated_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_alreadyAuthenticated_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_alreadyAuthenticated_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ofNat(lean_object* x_1) {
_start:
{
lean_object* x_2; uint8_t x_3; 
x_2 = lean_unsigned_to_nat(1u);
x_3 = lean_nat_dec_le(x_1, x_2);
if (x_3 == 0)
{
lean_object* x_4; uint8_t x_5; 
x_4 = lean_unsigned_to_nat(2u);
x_5 = lean_nat_dec_le(x_1, x_4);
if (x_5 == 0)
{
lean_object* x_6; uint8_t x_7; 
x_6 = lean_unsigned_to_nat(3u);
x_7 = lean_nat_dec_le(x_1, x_6);
if (x_7 == 0)
{
uint8_t x_8; 
x_8 = 4;
return x_8;
}
else
{
uint8_t x_9; 
x_9 = 3;
return x_9;
}
}
else
{
uint8_t x_10; 
x_10 = 2;
return x_10;
}
}
else
{
lean_object* x_11; uint8_t x_12; 
x_11 = lean_unsigned_to_nat(0u);
x_12 = lean_nat_dec_le(x_1, x_11);
if (x_12 == 0)
{
uint8_t x_13; 
x_13 = 1;
return x_13;
}
else
{
uint8_t x_14; 
x_14 = 0;
return x_14;
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ofNat___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ofNat(x_1);
lean_dec(x_1);
x_3 = lean_box(x_2);
return x_3;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqLoginResult(uint8_t x_1, uint8_t x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; uint8_t x_5; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorIdx(x_1);
x_4 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorIdx(x_2);
x_5 = lean_nat_dec_eq(x_3, x_4);
lean_dec(x_4);
lean_dec(x_3);
return x_5;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqLoginResult___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; uint8_t x_4; uint8_t x_5; lean_object* x_6; 
x_3 = lean_unbox(x_1);
x_4 = lean_unbox(x_2);
x_5 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqLoginResult(x_3, x_4);
x_6 = lean_box(x_5);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr(uint8_t x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_10; lean_object* x_17; lean_object* x_24; lean_object* x_31; 
switch (x_1) {
case 0:
{
lean_object* x_38; uint8_t x_39; 
x_38 = lean_unsigned_to_nat(1024u);
x_39 = lean_nat_dec_le(x_38, x_2);
if (x_39 == 0)
{
lean_object* x_40; 
x_40 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_3 = x_40;
goto block_9;
}
else
{
lean_object* x_41; 
x_41 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_3 = x_41;
goto block_9;
}
}
case 1:
{
lean_object* x_42; uint8_t x_43; 
x_42 = lean_unsigned_to_nat(1024u);
x_43 = lean_nat_dec_le(x_42, x_2);
if (x_43 == 0)
{
lean_object* x_44; 
x_44 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_10 = x_44;
goto block_16;
}
else
{
lean_object* x_45; 
x_45 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_10 = x_45;
goto block_16;
}
}
case 2:
{
lean_object* x_46; uint8_t x_47; 
x_46 = lean_unsigned_to_nat(1024u);
x_47 = lean_nat_dec_le(x_46, x_2);
if (x_47 == 0)
{
lean_object* x_48; 
x_48 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_17 = x_48;
goto block_23;
}
else
{
lean_object* x_49; 
x_49 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_17 = x_49;
goto block_23;
}
}
case 3:
{
lean_object* x_50; uint8_t x_51; 
x_50 = lean_unsigned_to_nat(1024u);
x_51 = lean_nat_dec_le(x_50, x_2);
if (x_51 == 0)
{
lean_object* x_52; 
x_52 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_24 = x_52;
goto block_30;
}
else
{
lean_object* x_53; 
x_53 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_24 = x_53;
goto block_30;
}
}
default: 
{
lean_object* x_54; uint8_t x_55; 
x_54 = lean_unsigned_to_nat(1024u);
x_55 = lean_nat_dec_le(x_54, x_2);
if (x_55 == 0)
{
lean_object* x_56; 
x_56 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_31 = x_56;
goto block_37;
}
else
{
lean_object* x_57; 
x_57 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_31 = x_57;
goto block_37;
}
}
}
block_9:
{
lean_object* x_4; lean_object* x_5; uint8_t x_6; lean_object* x_7; lean_object* x_8; 
x_4 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__1));
x_5 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_5, 0, x_3);
lean_ctor_set(x_5, 1, x_4);
x_6 = 0;
x_7 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_7, 0, x_5);
lean_ctor_set_uint8(x_7, sizeof(void*)*1, x_6);
x_8 = l_Repr_addAppParen(x_7, x_2);
return x_8;
}
block_16:
{
lean_object* x_11; lean_object* x_12; uint8_t x_13; lean_object* x_14; lean_object* x_15; 
x_11 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__3));
x_12 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_12, 0, x_10);
lean_ctor_set(x_12, 1, x_11);
x_13 = 0;
x_14 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_14, 0, x_12);
lean_ctor_set_uint8(x_14, sizeof(void*)*1, x_13);
x_15 = l_Repr_addAppParen(x_14, x_2);
return x_15;
}
block_23:
{
lean_object* x_18; lean_object* x_19; uint8_t x_20; lean_object* x_21; lean_object* x_22; 
x_18 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__5));
x_19 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_19, 0, x_17);
lean_ctor_set(x_19, 1, x_18);
x_20 = 0;
x_21 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_21, 0, x_19);
lean_ctor_set_uint8(x_21, sizeof(void*)*1, x_20);
x_22 = l_Repr_addAppParen(x_21, x_2);
return x_22;
}
block_30:
{
lean_object* x_25; lean_object* x_26; uint8_t x_27; lean_object* x_28; lean_object* x_29; 
x_25 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__7));
x_26 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_26, 0, x_24);
lean_ctor_set(x_26, 1, x_25);
x_27 = 0;
x_28 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_28, 0, x_26);
lean_ctor_set_uint8(x_28, sizeof(void*)*1, x_27);
x_29 = l_Repr_addAppParen(x_28, x_2);
return x_29;
}
block_37:
{
lean_object* x_32; lean_object* x_33; uint8_t x_34; lean_object* x_35; lean_object* x_36; 
x_32 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___closed__9));
x_33 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_33, 0, x_31);
lean_ctor_set(x_33, 1, x_32);
x_34 = 0;
x_35 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_35, 0, x_33);
lean_ctor_set_uint8(x_35, sizeof(void*)*1, x_34);
x_36 = l_Repr_addAppParen(x_35, x_2);
return x_36;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lean_unbox(x_1);
x_4 = lp_VerifiableAuthSpec_VerifiableAuth_instReprLoginResult_repr(x_3, x_2);
lean_dec(x_2);
return x_4;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqLoginResult_beq(uint8_t x_1, uint8_t x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; uint8_t x_5; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorIdx(x_1);
x_4 = lp_VerifiableAuthSpec_VerifiableAuth_LoginResult_ctorIdx(x_2);
x_5 = lean_nat_dec_eq(x_3, x_4);
lean_dec(x_4);
lean_dec(x_3);
return x_5;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqLoginResult_beq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; uint8_t x_4; uint8_t x_5; lean_object* x_6; 
x_3 = lean_unbox(x_1);
x_4 = lean_unbox(x_2);
x_5 = lp_VerifiableAuthSpec_VerifiableAuth_instBEqLoginResult_beq(x_3, x_4);
x_6 = lean_box(x_5);
return x_6;
}
}
static uint8_t _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLoginResult_default(void) {
_start:
{
uint8_t x_1; 
x_1 = 0;
return x_1;
}
}
static uint8_t _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLoginResult(void) {
_start:
{
uint8_t x_1; 
x_1 = 0;
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorIdx(uint8_t x_1) {
_start:
{
switch (x_1) {
case 0:
{
lean_object* x_2; 
x_2 = lean_unsigned_to_nat(0u);
return x_2;
}
case 1:
{
lean_object* x_3; 
x_3 = lean_unsigned_to_nat(1u);
return x_3;
}
case 2:
{
lean_object* x_4; 
x_4 = lean_unsigned_to_nat(2u);
return x_4;
}
default: 
{
lean_object* x_5; 
x_5 = lean_unsigned_to_nat(3u);
return x_5;
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorIdx___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = lean_unbox(x_1);
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorIdx(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_toCtorIdx(uint8_t x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorIdx(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_toCtorIdx___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = lean_unbox(x_1);
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_toCtorIdx(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorElim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorElim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorElim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorElim(lean_object* x_1, lean_object* x_2, uint8_t x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
lean_inc(x_5);
return x_5;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorElim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
uint8_t x_6; lean_object* x_7; 
x_6 = lean_unbox(x_3);
x_7 = lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorElim(x_1, x_2, x_6, x_4, x_5);
lean_dec(x_5);
lean_dec(x_2);
return x_7;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_success_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_success_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_success_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_success_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_success_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_success_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_unauthorized_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_unauthorized_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_unauthorized_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_unauthorized_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_unauthorized_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_unauthorized_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_wrongPassword_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_wrongPassword_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_wrongPassword_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_wrongPassword_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_wrongPassword_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_wrongPassword_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_systemError_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_systemError_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_systemError_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_systemError_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_systemError_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_systemError_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ofNat(lean_object* x_1) {
_start:
{
lean_object* x_2; uint8_t x_3; 
x_2 = lean_unsigned_to_nat(1u);
x_3 = lean_nat_dec_le(x_1, x_2);
if (x_3 == 0)
{
lean_object* x_4; uint8_t x_5; 
x_4 = lean_unsigned_to_nat(2u);
x_5 = lean_nat_dec_le(x_1, x_4);
if (x_5 == 0)
{
uint8_t x_6; 
x_6 = 3;
return x_6;
}
else
{
uint8_t x_7; 
x_7 = 2;
return x_7;
}
}
else
{
lean_object* x_8; uint8_t x_9; 
x_8 = lean_unsigned_to_nat(0u);
x_9 = lean_nat_dec_le(x_1, x_8);
if (x_9 == 0)
{
uint8_t x_10; 
x_10 = 1;
return x_10;
}
else
{
uint8_t x_11; 
x_11 = 0;
return x_11;
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ofNat___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ofNat(x_1);
lean_dec(x_1);
x_3 = lean_box(x_2);
return x_3;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqChangePasswordResult(uint8_t x_1, uint8_t x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; uint8_t x_5; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorIdx(x_1);
x_4 = lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorIdx(x_2);
x_5 = lean_nat_dec_eq(x_3, x_4);
lean_dec(x_4);
lean_dec(x_3);
return x_5;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqChangePasswordResult___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; uint8_t x_4; uint8_t x_5; lean_object* x_6; 
x_3 = lean_unbox(x_1);
x_4 = lean_unbox(x_2);
x_5 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqChangePasswordResult(x_3, x_4);
x_6 = lean_box(x_5);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr(uint8_t x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_10; lean_object* x_17; lean_object* x_24; 
switch (x_1) {
case 0:
{
lean_object* x_31; uint8_t x_32; 
x_31 = lean_unsigned_to_nat(1024u);
x_32 = lean_nat_dec_le(x_31, x_2);
if (x_32 == 0)
{
lean_object* x_33; 
x_33 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_3 = x_33;
goto block_9;
}
else
{
lean_object* x_34; 
x_34 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_3 = x_34;
goto block_9;
}
}
case 1:
{
lean_object* x_35; uint8_t x_36; 
x_35 = lean_unsigned_to_nat(1024u);
x_36 = lean_nat_dec_le(x_35, x_2);
if (x_36 == 0)
{
lean_object* x_37; 
x_37 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_10 = x_37;
goto block_16;
}
else
{
lean_object* x_38; 
x_38 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_10 = x_38;
goto block_16;
}
}
case 2:
{
lean_object* x_39; uint8_t x_40; 
x_39 = lean_unsigned_to_nat(1024u);
x_40 = lean_nat_dec_le(x_39, x_2);
if (x_40 == 0)
{
lean_object* x_41; 
x_41 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_17 = x_41;
goto block_23;
}
else
{
lean_object* x_42; 
x_42 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_17 = x_42;
goto block_23;
}
}
default: 
{
lean_object* x_43; uint8_t x_44; 
x_43 = lean_unsigned_to_nat(1024u);
x_44 = lean_nat_dec_le(x_43, x_2);
if (x_44 == 0)
{
lean_object* x_45; 
x_45 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_24 = x_45;
goto block_30;
}
else
{
lean_object* x_46; 
x_46 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_24 = x_46;
goto block_30;
}
}
}
block_9:
{
lean_object* x_4; lean_object* x_5; uint8_t x_6; lean_object* x_7; lean_object* x_8; 
x_4 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__1));
x_5 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_5, 0, x_3);
lean_ctor_set(x_5, 1, x_4);
x_6 = 0;
x_7 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_7, 0, x_5);
lean_ctor_set_uint8(x_7, sizeof(void*)*1, x_6);
x_8 = l_Repr_addAppParen(x_7, x_2);
return x_8;
}
block_16:
{
lean_object* x_11; lean_object* x_12; uint8_t x_13; lean_object* x_14; lean_object* x_15; 
x_11 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__3));
x_12 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_12, 0, x_10);
lean_ctor_set(x_12, 1, x_11);
x_13 = 0;
x_14 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_14, 0, x_12);
lean_ctor_set_uint8(x_14, sizeof(void*)*1, x_13);
x_15 = l_Repr_addAppParen(x_14, x_2);
return x_15;
}
block_23:
{
lean_object* x_18; lean_object* x_19; uint8_t x_20; lean_object* x_21; lean_object* x_22; 
x_18 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__5));
x_19 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_19, 0, x_17);
lean_ctor_set(x_19, 1, x_18);
x_20 = 0;
x_21 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_21, 0, x_19);
lean_ctor_set_uint8(x_21, sizeof(void*)*1, x_20);
x_22 = l_Repr_addAppParen(x_21, x_2);
return x_22;
}
block_30:
{
lean_object* x_25; lean_object* x_26; uint8_t x_27; lean_object* x_28; lean_object* x_29; 
x_25 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___closed__7));
x_26 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_26, 0, x_24);
lean_ctor_set(x_26, 1, x_25);
x_27 = 0;
x_28 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_28, 0, x_26);
lean_ctor_set_uint8(x_28, sizeof(void*)*1, x_27);
x_29 = l_Repr_addAppParen(x_28, x_2);
return x_29;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lean_unbox(x_1);
x_4 = lp_VerifiableAuthSpec_VerifiableAuth_instReprChangePasswordResult_repr(x_3, x_2);
lean_dec(x_2);
return x_4;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqChangePasswordResult_beq(uint8_t x_1, uint8_t x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; uint8_t x_5; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorIdx(x_1);
x_4 = lp_VerifiableAuthSpec_VerifiableAuth_ChangePasswordResult_ctorIdx(x_2);
x_5 = lean_nat_dec_eq(x_3, x_4);
lean_dec(x_4);
lean_dec(x_3);
return x_5;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqChangePasswordResult_beq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; uint8_t x_4; uint8_t x_5; lean_object* x_6; 
x_3 = lean_unbox(x_1);
x_4 = lean_unbox(x_2);
x_5 = lp_VerifiableAuthSpec_VerifiableAuth_instBEqChangePasswordResult_beq(x_3, x_4);
x_6 = lean_box(x_5);
return x_6;
}
}
static uint8_t _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedChangePasswordResult_default(void) {
_start:
{
uint8_t x_1; 
x_1 = 0;
return x_1;
}
}
static uint8_t _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedChangePasswordResult(void) {
_start:
{
uint8_t x_1; 
x_1 = 0;
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LogoutResult_toCtorIdx(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_unsigned_to_nat(0u);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LogoutResult_ofNat(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_box(0);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_LogoutResult_ofNat___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_LogoutResult_ofNat(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqLogoutResult(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; 
x_3 = 1;
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqLogoutResult___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqLogoutResult(x_1, x_2);
x_4 = lean_box(x_3);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr___redArg(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_9; uint8_t x_10; 
x_9 = lean_unsigned_to_nat(1024u);
x_10 = lean_nat_dec_le(x_9, x_1);
if (x_10 == 0)
{
lean_object* x_11; 
x_11 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_2 = x_11;
goto block_8;
}
else
{
lean_object* x_12; 
x_12 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_2 = x_12;
goto block_8;
}
block_8:
{
lean_object* x_3; lean_object* x_4; uint8_t x_5; lean_object* x_6; lean_object* x_7; 
x_3 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr___redArg___closed__1));
x_4 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_4, 0, x_2);
lean_ctor_set(x_4, 1, x_3);
x_5 = 0;
x_6 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_6, 0, x_4);
lean_ctor_set_uint8(x_6, sizeof(void*)*1, x_5);
x_7 = l_Repr_addAppParen(x_6, x_1);
return x_7;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr___redArg(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instReprLogoutResult_repr(x_1, x_2);
lean_dec(x_2);
return x_3;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqLogoutResult_beq(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; 
x_3 = 1;
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqLogoutResult_beq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instBEqLogoutResult_beq(x_1, x_2);
x_4 = lean_box(x_3);
return x_4;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLogoutResult_default(void) {
_start:
{
lean_object* x_1; 
x_1 = lean_box(0);
return x_1;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLogoutResult(void) {
_start:
{
lean_object* x_1; 
x_1 = lean_box(0);
return x_1;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__6(void) {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__13, &lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__13_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__13);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; 
x_3 = !lean_is_exclusive(x_2);
if (x_3 == 0)
{
lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; uint8_t x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; lean_object* x_22; lean_object* x_23; lean_object* x_24; lean_object* x_25; lean_object* x_26; lean_object* x_27; lean_object* x_28; lean_object* x_29; lean_object* x_30; lean_object* x_31; lean_object* x_32; 
x_4 = lean_ctor_get(x_2, 0);
x_5 = lean_ctor_get(x_2, 1);
x_6 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5));
x_7 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__3));
x_8 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7, &lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7);
x_9 = lean_unsigned_to_nat(0u);
x_10 = lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg(x_4);
lean_ctor_set_tag(x_2, 4);
lean_ctor_set(x_2, 1, x_10);
lean_ctor_set(x_2, 0, x_8);
x_11 = 0;
x_12 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_12, 0, x_2);
lean_ctor_set_uint8(x_12, sizeof(void*)*1, x_11);
x_13 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_13, 0, x_7);
lean_ctor_set(x_13, 1, x_12);
x_14 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__9));
x_15 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_15, 0, x_13);
lean_ctor_set(x_15, 1, x_14);
x_16 = lean_box(1);
x_17 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_17, 0, x_15);
lean_ctor_set(x_17, 1, x_16);
x_18 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__5));
x_19 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_19, 0, x_17);
lean_ctor_set(x_19, 1, x_18);
x_20 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_20, 0, x_19);
lean_ctor_set(x_20, 1, x_6);
x_21 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__4);
x_22 = lean_apply_2(x_1, x_5, x_9);
x_23 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_23, 0, x_21);
lean_ctor_set(x_23, 1, x_22);
x_24 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_24, 0, x_23);
lean_ctor_set_uint8(x_24, sizeof(void*)*1, x_11);
x_25 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_25, 0, x_20);
lean_ctor_set(x_25, 1, x_24);
x_26 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__6, &lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__6_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__6);
x_27 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__15));
x_28 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_28, 0, x_27);
lean_ctor_set(x_28, 1, x_25);
x_29 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__16));
x_30 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_30, 0, x_28);
lean_ctor_set(x_30, 1, x_29);
x_31 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_31, 0, x_26);
lean_ctor_set(x_31, 1, x_30);
x_32 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_32, 0, x_31);
lean_ctor_set_uint8(x_32, sizeof(void*)*1, x_11);
return x_32;
}
else
{
lean_object* x_33; lean_object* x_34; lean_object* x_35; lean_object* x_36; lean_object* x_37; lean_object* x_38; lean_object* x_39; lean_object* x_40; uint8_t x_41; lean_object* x_42; lean_object* x_43; lean_object* x_44; lean_object* x_45; lean_object* x_46; lean_object* x_47; lean_object* x_48; lean_object* x_49; lean_object* x_50; lean_object* x_51; lean_object* x_52; lean_object* x_53; lean_object* x_54; lean_object* x_55; lean_object* x_56; lean_object* x_57; lean_object* x_58; lean_object* x_59; lean_object* x_60; lean_object* x_61; lean_object* x_62; 
x_33 = lean_ctor_get(x_2, 0);
x_34 = lean_ctor_get(x_2, 1);
lean_inc(x_34);
lean_inc(x_33);
lean_dec(x_2);
x_35 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5));
x_36 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__3));
x_37 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7, &lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__7);
x_38 = lean_unsigned_to_nat(0u);
x_39 = lp_VerifiableAuthSpec_VerifiableAuth_instReprAuthState_repr___redArg(x_33);
x_40 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_40, 0, x_37);
lean_ctor_set(x_40, 1, x_39);
x_41 = 0;
x_42 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_42, 0, x_40);
lean_ctor_set_uint8(x_42, sizeof(void*)*1, x_41);
x_43 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_43, 0, x_36);
lean_ctor_set(x_43, 1, x_42);
x_44 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__9));
x_45 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_45, 0, x_43);
lean_ctor_set(x_45, 1, x_44);
x_46 = lean_box(1);
x_47 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_47, 0, x_45);
lean_ctor_set(x_47, 1, x_46);
x_48 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__5));
x_49 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_49, 0, x_47);
lean_ctor_set(x_49, 1, x_48);
x_50 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_50, 0, x_49);
lean_ctor_set(x_50, 1, x_35);
x_51 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprPasswordHash_repr___redArg___closed__4);
x_52 = lean_apply_2(x_1, x_34, x_38);
x_53 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_53, 0, x_51);
lean_ctor_set(x_53, 1, x_52);
x_54 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_54, 0, x_53);
lean_ctor_set_uint8(x_54, sizeof(void*)*1, x_41);
x_55 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_55, 0, x_50);
lean_ctor_set(x_55, 1, x_54);
x_56 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__6, &lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__6_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg___closed__6);
x_57 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__15));
x_58 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_58, 0, x_57);
lean_ctor_set(x_58, 1, x_55);
x_59 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__16));
x_60 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_60, 0, x_58);
lean_ctor_set(x_60, 1, x_59);
x_61 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_61, 0, x_56);
lean_ctor_set(x_61, 1, x_60);
x_62 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_62, 0, x_61);
lean_ctor_set_uint8(x_62, sizeof(void*)*1, x_41);
return x_62;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___redArg(x_2, x_3);
return x_5;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr(x_1, x_2, x_3, x_4);
lean_dec(x_4);
return x_5;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome___redArg(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_alloc_closure((void*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___boxed), 4, 2);
lean_closure_set(x_2, 0, lean_box(0));
lean_closure_set(x_2, 1, x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lean_alloc_closure((void*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprOutcome_repr___boxed), 4, 2);
lean_closure_set(x_3, 0, lean_box(0));
lean_closure_set(x_3, 1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorIdx(uint8_t x_1) {
_start:
{
switch (x_1) {
case 0:
{
lean_object* x_2; 
x_2 = lean_unsigned_to_nat(0u);
return x_2;
}
case 1:
{
lean_object* x_3; 
x_3 = lean_unsigned_to_nat(1u);
return x_3;
}
case 2:
{
lean_object* x_4; 
x_4 = lean_unsigned_to_nat(2u);
return x_4;
}
case 3:
{
lean_object* x_5; 
x_5 = lean_unsigned_to_nat(3u);
return x_5;
}
case 4:
{
lean_object* x_6; 
x_6 = lean_unsigned_to_nat(4u);
return x_6;
}
default: 
{
lean_object* x_7; 
x_7 = lean_unsigned_to_nat(5u);
return x_7;
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorIdx___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = lean_unbox(x_1);
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorIdx(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_toCtorIdx(uint8_t x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorIdx(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_toCtorIdx___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = lean_unbox(x_1);
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_toCtorIdx(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorElim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorElim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorElim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorElim(lean_object* x_1, lean_object* x_2, uint8_t x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
lean_inc(x_5);
return x_5;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorElim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
uint8_t x_6; lean_object* x_7; 
x_6 = lean_unbox(x_3);
x_7 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorElim(x_1, x_2, x_6, x_4, x_5);
lean_dec(x_5);
lean_dec(x_2);
return x_7;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_register_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_register_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_register_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_register_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_register_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_register_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginSuccess_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginSuccess_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginSuccess_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginSuccess_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginSuccess_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginSuccess_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginFailure_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginFailure_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginFailure_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginFailure_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginFailure_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_loginFailure_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_lock_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_lock_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_lock_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_lock_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_lock_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_lock_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_passwordChange_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_passwordChange_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_passwordChange_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_passwordChange_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_passwordChange_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_passwordChange_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_logout_elim___redArg(lean_object* x_1) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_logout_elim___redArg___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_logout_elim___redArg(x_1);
lean_dec(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_logout_elim(lean_object* x_1, uint8_t x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_inc(x_4);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_logout_elim___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_2);
x_6 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_logout_elim(x_1, x_5, x_3, x_4);
lean_dec(x_4);
return x_6;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ofNat(lean_object* x_1) {
_start:
{
lean_object* x_2; uint8_t x_3; 
x_2 = lean_unsigned_to_nat(2u);
x_3 = lean_nat_dec_le(x_1, x_2);
if (x_3 == 0)
{
lean_object* x_4; uint8_t x_5; 
x_4 = lean_unsigned_to_nat(3u);
x_5 = lean_nat_dec_le(x_1, x_4);
if (x_5 == 0)
{
lean_object* x_6; uint8_t x_7; 
x_6 = lean_unsigned_to_nat(4u);
x_7 = lean_nat_dec_le(x_1, x_6);
if (x_7 == 0)
{
uint8_t x_8; 
x_8 = 5;
return x_8;
}
else
{
uint8_t x_9; 
x_9 = 4;
return x_9;
}
}
else
{
uint8_t x_10; 
x_10 = 3;
return x_10;
}
}
else
{
lean_object* x_11; uint8_t x_12; 
x_11 = lean_unsigned_to_nat(0u);
x_12 = lean_nat_dec_le(x_1, x_11);
if (x_12 == 0)
{
lean_object* x_13; uint8_t x_14; 
x_13 = lean_unsigned_to_nat(1u);
x_14 = lean_nat_dec_le(x_1, x_13);
if (x_14 == 0)
{
uint8_t x_15; 
x_15 = 2;
return x_15;
}
else
{
uint8_t x_16; 
x_16 = 1;
return x_16;
}
}
else
{
uint8_t x_17; 
x_17 = 0;
return x_17;
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ofNat___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ofNat(x_1);
lean_dec(x_1);
x_3 = lean_box(x_2);
return x_3;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuditEventType(uint8_t x_1, uint8_t x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; uint8_t x_5; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorIdx(x_1);
x_4 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorIdx(x_2);
x_5 = lean_nat_dec_eq(x_3, x_4);
lean_dec(x_4);
lean_dec(x_3);
return x_5;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuditEventType___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; uint8_t x_4; uint8_t x_5; lean_object* x_6; 
x_3 = lean_unbox(x_1);
x_4 = lean_unbox(x_2);
x_5 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuditEventType(x_3, x_4);
x_6 = lean_box(x_5);
return x_6;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr(uint8_t x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_10; lean_object* x_17; lean_object* x_24; lean_object* x_31; lean_object* x_38; 
switch (x_1) {
case 0:
{
lean_object* x_45; uint8_t x_46; 
x_45 = lean_unsigned_to_nat(1024u);
x_46 = lean_nat_dec_le(x_45, x_2);
if (x_46 == 0)
{
lean_object* x_47; 
x_47 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_3 = x_47;
goto block_9;
}
else
{
lean_object* x_48; 
x_48 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_3 = x_48;
goto block_9;
}
}
case 1:
{
lean_object* x_49; uint8_t x_50; 
x_49 = lean_unsigned_to_nat(1024u);
x_50 = lean_nat_dec_le(x_49, x_2);
if (x_50 == 0)
{
lean_object* x_51; 
x_51 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_10 = x_51;
goto block_16;
}
else
{
lean_object* x_52; 
x_52 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_10 = x_52;
goto block_16;
}
}
case 2:
{
lean_object* x_53; uint8_t x_54; 
x_53 = lean_unsigned_to_nat(1024u);
x_54 = lean_nat_dec_le(x_53, x_2);
if (x_54 == 0)
{
lean_object* x_55; 
x_55 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_17 = x_55;
goto block_23;
}
else
{
lean_object* x_56; 
x_56 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_17 = x_56;
goto block_23;
}
}
case 3:
{
lean_object* x_57; uint8_t x_58; 
x_57 = lean_unsigned_to_nat(1024u);
x_58 = lean_nat_dec_le(x_57, x_2);
if (x_58 == 0)
{
lean_object* x_59; 
x_59 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_24 = x_59;
goto block_30;
}
else
{
lean_object* x_60; 
x_60 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_24 = x_60;
goto block_30;
}
}
case 4:
{
lean_object* x_61; uint8_t x_62; 
x_61 = lean_unsigned_to_nat(1024u);
x_62 = lean_nat_dec_le(x_61, x_2);
if (x_62 == 0)
{
lean_object* x_63; 
x_63 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_31 = x_63;
goto block_37;
}
else
{
lean_object* x_64; 
x_64 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_31 = x_64;
goto block_37;
}
}
default: 
{
lean_object* x_65; uint8_t x_66; 
x_65 = lean_unsigned_to_nat(1024u);
x_66 = lean_nat_dec_le(x_65, x_2);
if (x_66 == 0)
{
lean_object* x_67; 
x_67 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__4);
x_38 = x_67;
goto block_44;
}
else
{
lean_object* x_68; 
x_68 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5, &lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprLockState_repr___closed__5);
x_38 = x_68;
goto block_44;
}
}
}
block_9:
{
lean_object* x_4; lean_object* x_5; uint8_t x_6; lean_object* x_7; lean_object* x_8; 
x_4 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__1));
x_5 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_5, 0, x_3);
lean_ctor_set(x_5, 1, x_4);
x_6 = 0;
x_7 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_7, 0, x_5);
lean_ctor_set_uint8(x_7, sizeof(void*)*1, x_6);
x_8 = l_Repr_addAppParen(x_7, x_2);
return x_8;
}
block_16:
{
lean_object* x_11; lean_object* x_12; uint8_t x_13; lean_object* x_14; lean_object* x_15; 
x_11 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__3));
x_12 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_12, 0, x_10);
lean_ctor_set(x_12, 1, x_11);
x_13 = 0;
x_14 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_14, 0, x_12);
lean_ctor_set_uint8(x_14, sizeof(void*)*1, x_13);
x_15 = l_Repr_addAppParen(x_14, x_2);
return x_15;
}
block_23:
{
lean_object* x_18; lean_object* x_19; uint8_t x_20; lean_object* x_21; lean_object* x_22; 
x_18 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__5));
x_19 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_19, 0, x_17);
lean_ctor_set(x_19, 1, x_18);
x_20 = 0;
x_21 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_21, 0, x_19);
lean_ctor_set_uint8(x_21, sizeof(void*)*1, x_20);
x_22 = l_Repr_addAppParen(x_21, x_2);
return x_22;
}
block_30:
{
lean_object* x_25; lean_object* x_26; uint8_t x_27; lean_object* x_28; lean_object* x_29; 
x_25 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__7));
x_26 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_26, 0, x_24);
lean_ctor_set(x_26, 1, x_25);
x_27 = 0;
x_28 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_28, 0, x_26);
lean_ctor_set_uint8(x_28, sizeof(void*)*1, x_27);
x_29 = l_Repr_addAppParen(x_28, x_2);
return x_29;
}
block_37:
{
lean_object* x_32; lean_object* x_33; uint8_t x_34; lean_object* x_35; lean_object* x_36; 
x_32 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__9));
x_33 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_33, 0, x_31);
lean_ctor_set(x_33, 1, x_32);
x_34 = 0;
x_35 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_35, 0, x_33);
lean_ctor_set_uint8(x_35, sizeof(void*)*1, x_34);
x_36 = l_Repr_addAppParen(x_35, x_2);
return x_36;
}
block_44:
{
lean_object* x_39; lean_object* x_40; uint8_t x_41; lean_object* x_42; lean_object* x_43; 
x_39 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___closed__11));
x_40 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_40, 0, x_38);
lean_ctor_set(x_40, 1, x_39);
x_41 = 0;
x_42 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_42, 0, x_40);
lean_ctor_set_uint8(x_42, sizeof(void*)*1, x_41);
x_43 = l_Repr_addAppParen(x_42, x_2);
return x_43;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lean_unbox(x_1);
x_4 = lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr(x_3, x_2);
lean_dec(x_2);
return x_4;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEventType_beq(uint8_t x_1, uint8_t x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; uint8_t x_5; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorIdx(x_1);
x_4 = lp_VerifiableAuthSpec_VerifiableAuth_AuditEventType_ctorIdx(x_2);
x_5 = lean_nat_dec_eq(x_3, x_4);
lean_dec(x_4);
lean_dec(x_3);
return x_5;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEventType_beq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; uint8_t x_4; uint8_t x_5; lean_object* x_6; 
x_3 = lean_unbox(x_1);
x_4 = lean_unbox(x_2);
x_5 = lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEventType_beq(x_3, x_4);
x_6 = lean_box(x_5);
return x_6;
}
}
static uint8_t _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEventType_default(void) {
_start:
{
uint8_t x_1; 
x_1 = 0;
return x_1;
}
}
static uint8_t _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEventType(void) {
_start:
{
uint8_t x_1; 
x_1 = 0;
return x_1;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuditEvent_decEq(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; lean_object* x_5; uint8_t x_6; lean_object* x_7; lean_object* x_8; uint8_t x_9; 
x_3 = lean_ctor_get_uint8(x_1, sizeof(void*)*2);
x_4 = lean_ctor_get(x_1, 0);
x_5 = lean_ctor_get(x_1, 1);
x_6 = lean_ctor_get_uint8(x_2, sizeof(void*)*2);
x_7 = lean_ctor_get(x_2, 0);
x_8 = lean_ctor_get(x_2, 1);
x_9 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuditEventType(x_3, x_6);
if (x_9 == 0)
{
return x_9;
}
else
{
uint8_t x_10; 
x_10 = lean_string_dec_eq(x_4, x_7);
if (x_10 == 0)
{
return x_10;
}
else
{
uint8_t x_11; 
x_11 = lean_string_dec_eq(x_5, x_8);
return x_11;
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuditEvent_decEq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuditEvent_decEq(x_1, x_2);
lean_dec_ref(x_2);
lean_dec_ref(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuditEvent(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuditEvent_decEq(x_1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuditEvent___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqAuditEvent(x_1, x_2);
lean_dec_ref(x_2);
lean_dec_ref(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__6(void) {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(14u);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; uint8_t x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; lean_object* x_22; lean_object* x_23; lean_object* x_24; lean_object* x_25; lean_object* x_26; lean_object* x_27; lean_object* x_28; lean_object* x_29; lean_object* x_30; lean_object* x_31; lean_object* x_32; lean_object* x_33; lean_object* x_34; lean_object* x_35; lean_object* x_36; lean_object* x_37; lean_object* x_38; lean_object* x_39; lean_object* x_40; lean_object* x_41; lean_object* x_42; lean_object* x_43; lean_object* x_44; 
x_2 = lean_ctor_get_uint8(x_1, sizeof(void*)*2);
x_3 = lean_ctor_get(x_1, 0);
lean_inc_ref(x_3);
x_4 = lean_ctor_get(x_1, 1);
lean_inc_ref(x_4);
lean_dec_ref(x_1);
x_5 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5));
x_6 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__3));
x_7 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__16, &lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__16_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__16);
x_8 = lean_unsigned_to_nat(0u);
x_9 = lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEventType_repr(x_2, x_8);
x_10 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_10, 0, x_7);
lean_ctor_set(x_10, 1, x_9);
x_11 = 0;
x_12 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_12, 0, x_10);
lean_ctor_set_uint8(x_12, sizeof(void*)*1, x_11);
x_13 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_13, 0, x_6);
lean_ctor_set(x_13, 1, x_12);
x_14 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__9));
x_15 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_15, 0, x_13);
lean_ctor_set(x_15, 1, x_14);
x_16 = lean_box(1);
x_17 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_17, 0, x_15);
lean_ctor_set(x_17, 1, x_16);
x_18 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__1));
x_19 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_19, 0, x_17);
lean_ctor_set(x_19, 1, x_18);
x_20 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_20, 0, x_19);
lean_ctor_set(x_20, 1, x_5);
x_21 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__4);
x_22 = l_String_quote(x_3);
x_23 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_23, 0, x_22);
x_24 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_24, 0, x_21);
lean_ctor_set(x_24, 1, x_23);
x_25 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_25, 0, x_24);
lean_ctor_set_uint8(x_25, sizeof(void*)*1, x_11);
x_26 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_26, 0, x_20);
lean_ctor_set(x_26, 1, x_25);
x_27 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_27, 0, x_26);
lean_ctor_set(x_27, 1, x_14);
x_28 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_28, 0, x_27);
lean_ctor_set(x_28, 1, x_16);
x_29 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__5));
x_30 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_30, 0, x_28);
lean_ctor_set(x_30, 1, x_29);
x_31 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_31, 0, x_30);
lean_ctor_set(x_31, 1, x_5);
x_32 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__6, &lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__6_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg___closed__6);
x_33 = l_String_quote(x_4);
x_34 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_34, 0, x_33);
x_35 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_35, 0, x_32);
lean_ctor_set(x_35, 1, x_34);
x_36 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_36, 0, x_35);
lean_ctor_set_uint8(x_36, sizeof(void*)*1, x_11);
x_37 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_37, 0, x_31);
lean_ctor_set(x_37, 1, x_36);
x_38 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14, &lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14);
x_39 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__15));
x_40 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_40, 0, x_39);
lean_ctor_set(x_40, 1, x_37);
x_41 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__16));
x_42 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_42, 0, x_40);
lean_ctor_set(x_42, 1, x_41);
x_43 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_43, 0, x_38);
lean_ctor_set(x_43, 1, x_42);
x_44 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_44, 0, x_43);
lean_ctor_set_uint8(x_44, sizeof(void*)*1, x_11);
return x_44;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___redArg(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instReprAuditEvent_repr(x_1, x_2);
lean_dec(x_2);
return x_3;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEvent_beq(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; lean_object* x_5; uint8_t x_6; lean_object* x_7; lean_object* x_8; uint8_t x_9; 
x_3 = lean_ctor_get_uint8(x_1, sizeof(void*)*2);
x_4 = lean_ctor_get(x_1, 0);
x_5 = lean_ctor_get(x_1, 1);
x_6 = lean_ctor_get_uint8(x_2, sizeof(void*)*2);
x_7 = lean_ctor_get(x_2, 0);
x_8 = lean_ctor_get(x_2, 1);
x_9 = lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEventType_beq(x_3, x_6);
if (x_9 == 0)
{
return x_9;
}
else
{
uint8_t x_10; 
x_10 = lean_string_dec_eq(x_4, x_7);
if (x_10 == 0)
{
return x_10;
}
else
{
uint8_t x_11; 
x_11 = lean_string_dec_eq(x_5, x_8);
return x_11;
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEvent_beq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instBEqAuditEvent_beq(x_1, x_2);
lean_dec_ref(x_2);
lean_dec_ref(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEvent_default___closed__0(void) {
_start:
{
lean_object* x_1; uint8_t x_2; lean_object* x_3; 
x_1 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedSalt_default___closed__0));
x_2 = 0;
x_3 = lean_alloc_ctor(0, 2, 1);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_1);
lean_ctor_set_uint8(x_3, sizeof(void*)*2, x_2);
return x_3;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEvent_default(void) {
_start:
{
lean_object* x_1; 
x_1 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEvent_default___closed__0, &lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEvent_default___closed__0_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEvent_default___closed__0);
return x_1;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEvent(void) {
_start:
{
lean_object* x_1; 
x_1 = lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEvent_default;
return x_1;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqMetrics_decEq(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; uint8_t x_9; 
x_3 = lean_ctor_get(x_1, 0);
x_4 = lean_ctor_get(x_1, 1);
x_5 = lean_ctor_get(x_1, 2);
x_6 = lean_ctor_get(x_2, 0);
x_7 = lean_ctor_get(x_2, 1);
x_8 = lean_ctor_get(x_2, 2);
x_9 = lean_nat_dec_eq(x_3, x_6);
if (x_9 == 0)
{
return x_9;
}
else
{
uint8_t x_10; 
x_10 = lean_nat_dec_eq(x_4, x_7);
if (x_10 == 0)
{
return x_10;
}
else
{
uint8_t x_11; 
x_11 = lean_nat_dec_eq(x_5, x_8);
return x_11;
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqMetrics_decEq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqMetrics_decEq(x_1, x_2);
lean_dec_ref(x_2);
lean_dec_ref(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqMetrics(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqMetrics_decEq(x_1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqMetrics___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instDecidableEqMetrics(x_1, x_2);
lean_dec_ref(x_2);
lean_dec_ref(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
static lean_object* _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__4(void) {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(21u);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; uint8_t x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; lean_object* x_22; lean_object* x_23; lean_object* x_24; lean_object* x_25; lean_object* x_26; lean_object* x_27; lean_object* x_28; lean_object* x_29; lean_object* x_30; lean_object* x_31; lean_object* x_32; lean_object* x_33; lean_object* x_34; lean_object* x_35; lean_object* x_36; lean_object* x_37; lean_object* x_38; lean_object* x_39; lean_object* x_40; lean_object* x_41; lean_object* x_42; lean_object* x_43; 
x_2 = lean_ctor_get(x_1, 0);
lean_inc(x_2);
x_3 = lean_ctor_get(x_1, 1);
lean_inc(x_3);
x_4 = lean_ctor_get(x_1, 2);
lean_inc(x_4);
lean_dec_ref(x_1);
x_5 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__5));
x_6 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__3));
x_7 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__4, &lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__4_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__4);
x_8 = l_Nat_reprFast(x_2);
x_9 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_9, 0, x_8);
x_10 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_10, 0, x_7);
lean_ctor_set(x_10, 1, x_9);
x_11 = 0;
x_12 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_12, 0, x_10);
lean_ctor_set_uint8(x_12, sizeof(void*)*1, x_11);
x_13 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_13, 0, x_6);
lean_ctor_set(x_13, 1, x_12);
x_14 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__9));
x_15 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_15, 0, x_13);
lean_ctor_set(x_15, 1, x_14);
x_16 = lean_box(1);
x_17 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_17, 0, x_15);
lean_ctor_set(x_17, 1, x_16);
x_18 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__6));
x_19 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_19, 0, x_17);
lean_ctor_set(x_19, 1, x_18);
x_20 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_20, 0, x_19);
lean_ctor_set(x_20, 1, x_5);
x_21 = l_Nat_reprFast(x_3);
x_22 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_22, 0, x_21);
x_23 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_23, 0, x_7);
lean_ctor_set(x_23, 1, x_22);
x_24 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_24, 0, x_23);
lean_ctor_set_uint8(x_24, sizeof(void*)*1, x_11);
x_25 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_25, 0, x_20);
lean_ctor_set(x_25, 1, x_24);
x_26 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_26, 0, x_25);
lean_ctor_set(x_26, 1, x_14);
x_27 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_27, 0, x_26);
lean_ctor_set(x_27, 1, x_16);
x_28 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg___closed__8));
x_29 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_29, 0, x_27);
lean_ctor_set(x_29, 1, x_28);
x_30 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_30, 0, x_29);
lean_ctor_set(x_30, 1, x_5);
x_31 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__10, &lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__10_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprUser_repr___redArg___closed__10);
x_32 = l_Nat_reprFast(x_4);
x_33 = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(x_33, 0, x_32);
x_34 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_34, 0, x_31);
lean_ctor_set(x_34, 1, x_33);
x_35 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_35, 0, x_34);
lean_ctor_set_uint8(x_35, sizeof(void*)*1, x_11);
x_36 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_36, 0, x_30);
lean_ctor_set(x_36, 1, x_35);
x_37 = lean_obj_once(&lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14, &lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14_once, _init_lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__14);
x_38 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__15));
x_39 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_39, 0, x_38);
lean_ctor_set(x_39, 1, x_36);
x_40 = ((lean_object*)(lp_VerifiableAuthSpec_VerifiableAuth_instReprSalt_repr___redArg___closed__16));
x_41 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_41, 0, x_39);
lean_ctor_set(x_41, 1, x_40);
x_42 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_42, 0, x_37);
lean_ctor_set(x_42, 1, x_41);
x_43 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_43, 0, x_42);
lean_ctor_set_uint8(x_43, sizeof(void*)*1, x_11);
return x_43;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___redArg(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instReprMetrics_repr(x_1, x_2);
lean_dec(x_2);
return x_3;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_instBEqMetrics_beq(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; uint8_t x_9; 
x_3 = lean_ctor_get(x_1, 0);
x_4 = lean_ctor_get(x_1, 1);
x_5 = lean_ctor_get(x_1, 2);
x_6 = lean_ctor_get(x_2, 0);
x_7 = lean_ctor_get(x_2, 1);
x_8 = lean_ctor_get(x_2, 2);
x_9 = lean_nat_dec_eq(x_3, x_6);
if (x_9 == 0)
{
return x_9;
}
else
{
uint8_t x_10; 
x_10 = lean_nat_dec_eq(x_4, x_7);
if (x_10 == 0)
{
return x_10;
}
else
{
uint8_t x_11; 
x_11 = lean_nat_dec_eq(x_5, x_8);
return x_11;
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_instBEqMetrics_beq___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_instBEqMetrics_beq(x_1, x_2);
lean_dec_ref(x_2);
lean_dec_ref(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
lean_object* initialize_Init(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_VerifiableAuthSpec_VerifiableAuth_Types(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_VerifiableAuthSpec_VerifiableAuth_lockoutThreshold = _init_lp_VerifiableAuthSpec_VerifiableAuth_lockoutThreshold();
lean_mark_persistent(lp_VerifiableAuthSpec_VerifiableAuth_lockoutThreshold);
lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLockState_default = _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLockState_default();
lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLockState = _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLockState();
lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedPasswordHash_default = _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedPasswordHash_default();
lean_mark_persistent(lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedPasswordHash_default);
lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedPasswordHash = _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedPasswordHash();
lean_mark_persistent(lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedPasswordHash);
lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedRegisterResult_default = _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedRegisterResult_default();
lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedRegisterResult = _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedRegisterResult();
lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLoginResult_default = _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLoginResult_default();
lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLoginResult = _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLoginResult();
lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedChangePasswordResult_default = _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedChangePasswordResult_default();
lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedChangePasswordResult = _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedChangePasswordResult();
lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLogoutResult_default = _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLogoutResult_default();
lean_mark_persistent(lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLogoutResult_default);
lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLogoutResult = _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLogoutResult();
lean_mark_persistent(lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedLogoutResult);
lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEventType_default = _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEventType_default();
lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEventType = _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEventType();
lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEvent_default = _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEvent_default();
lean_mark_persistent(lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEvent_default);
lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEvent = _init_lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEvent();
lean_mark_persistent(lp_VerifiableAuthSpec_VerifiableAuth_instInhabitedAuditEvent);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
