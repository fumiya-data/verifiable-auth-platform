// Lean compiler output
// Module: VerifiableAuth.StateModel
// Imports: public import Init public import VerifiableAuth.Types
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
lean_object* lean_nat_add(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_User_noteFailedLogin(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_User_clearFailedAttempts(lean_object*);
lean_object* lp_VerifiableAuthSpec_VerifiableAuth_Salt_rotate(lean_object*);
lean_object* lp_VerifiableAuthSpec_VerifiableAuth_derivePasswordHash(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_User_changePassword(lean_object*, lean_object*);
lean_object* lp_VerifiableAuthSpec_VerifiableAuth_Salt_initial(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_mkRegisteredUser(lean_object*, lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec___private_VerifiableAuth_StateModel_0__VerifiableAuth_lookupUserInList(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec___private_VerifiableAuth_StateModel_0__VerifiableAuth_lookupUserInList___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec___private_VerifiableAuth_StateModel_0__VerifiableAuth_replaceUserInList(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuthState_lookupUser_x3f(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuthState_lookupUser_x3f___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_AuthState_containsUser(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuthState_containsUser___boxed(lean_object*, lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuthState_insertUser(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuthState_replaceUser(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuthState_clearSession(lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuthState_setAuthenticated(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_User_noteFailedLogin(lean_object* x_1) {
_start:
{
uint8_t x_2; 
x_2 = !lean_is_exclusive(x_1);
if (x_2 == 0)
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; uint8_t x_7; 
x_3 = lean_ctor_get(x_1, 3);
x_4 = lean_unsigned_to_nat(1u);
x_5 = lean_nat_add(x_3, x_4);
lean_dec(x_3);
x_6 = lean_unsigned_to_nat(3u);
x_7 = lean_nat_dec_le(x_6, x_5);
if (x_7 == 0)
{
uint8_t x_8; 
x_8 = 0;
lean_ctor_set(x_1, 3, x_5);
lean_ctor_set_uint8(x_1, sizeof(void*)*4, x_8);
return x_1;
}
else
{
uint8_t x_9; 
x_9 = 1;
lean_ctor_set(x_1, 3, x_5);
lean_ctor_set_uint8(x_1, sizeof(void*)*4, x_9);
return x_1;
}
}
else
{
lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; uint8_t x_17; 
x_10 = lean_ctor_get(x_1, 0);
x_11 = lean_ctor_get(x_1, 1);
x_12 = lean_ctor_get(x_1, 2);
x_13 = lean_ctor_get(x_1, 3);
lean_inc(x_13);
lean_inc(x_12);
lean_inc(x_11);
lean_inc(x_10);
lean_dec(x_1);
x_14 = lean_unsigned_to_nat(1u);
x_15 = lean_nat_add(x_13, x_14);
lean_dec(x_13);
x_16 = lean_unsigned_to_nat(3u);
x_17 = lean_nat_dec_le(x_16, x_15);
if (x_17 == 0)
{
uint8_t x_18; lean_object* x_19; 
x_18 = 0;
x_19 = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(x_19, 0, x_10);
lean_ctor_set(x_19, 1, x_11);
lean_ctor_set(x_19, 2, x_12);
lean_ctor_set(x_19, 3, x_15);
lean_ctor_set_uint8(x_19, sizeof(void*)*4, x_18);
return x_19;
}
else
{
uint8_t x_20; lean_object* x_21; 
x_20 = 1;
x_21 = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(x_21, 0, x_10);
lean_ctor_set(x_21, 1, x_11);
lean_ctor_set(x_21, 2, x_12);
lean_ctor_set(x_21, 3, x_15);
lean_ctor_set_uint8(x_21, sizeof(void*)*4, x_20);
return x_21;
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_User_clearFailedAttempts(lean_object* x_1) {
_start:
{
uint8_t x_2; 
x_2 = !lean_is_exclusive(x_1);
if (x_2 == 0)
{
lean_object* x_3; lean_object* x_4; 
x_3 = lean_ctor_get(x_1, 3);
lean_dec(x_3);
x_4 = lean_unsigned_to_nat(0u);
lean_ctor_set(x_1, 3, x_4);
return x_1;
}
else
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; uint8_t x_8; lean_object* x_9; lean_object* x_10; 
x_5 = lean_ctor_get(x_1, 0);
x_6 = lean_ctor_get(x_1, 1);
x_7 = lean_ctor_get(x_1, 2);
x_8 = lean_ctor_get_uint8(x_1, sizeof(void*)*4);
lean_inc(x_7);
lean_inc(x_6);
lean_inc(x_5);
lean_dec(x_1);
x_9 = lean_unsigned_to_nat(0u);
x_10 = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(x_10, 0, x_5);
lean_ctor_set(x_10, 1, x_6);
lean_ctor_set(x_10, 2, x_7);
lean_ctor_set(x_10, 3, x_9);
lean_ctor_set_uint8(x_10, sizeof(void*)*4, x_8);
return x_10;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_User_changePassword(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; 
x_3 = !lean_is_exclusive(x_1);
if (x_3 == 0)
{
lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; uint8_t x_10; 
x_4 = lean_ctor_get(x_1, 1);
x_5 = lean_ctor_get(x_1, 3);
lean_dec(x_5);
x_6 = lean_ctor_get(x_1, 2);
lean_dec(x_6);
x_7 = lp_VerifiableAuthSpec_VerifiableAuth_Salt_rotate(x_4);
lean_inc_ref(x_7);
x_8 = lp_VerifiableAuthSpec_VerifiableAuth_derivePasswordHash(x_2, x_7);
x_9 = lean_unsigned_to_nat(0u);
x_10 = 0;
lean_ctor_set(x_1, 3, x_9);
lean_ctor_set(x_1, 2, x_8);
lean_ctor_set(x_1, 1, x_7);
lean_ctor_set_uint8(x_1, sizeof(void*)*4, x_10);
return x_1;
}
else
{
lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; uint8_t x_16; lean_object* x_17; 
x_11 = lean_ctor_get(x_1, 0);
x_12 = lean_ctor_get(x_1, 1);
lean_inc(x_12);
lean_inc(x_11);
lean_dec(x_1);
x_13 = lp_VerifiableAuthSpec_VerifiableAuth_Salt_rotate(x_12);
lean_inc_ref(x_13);
x_14 = lp_VerifiableAuthSpec_VerifiableAuth_derivePasswordHash(x_2, x_13);
x_15 = lean_unsigned_to_nat(0u);
x_16 = 0;
x_17 = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(x_17, 0, x_11);
lean_ctor_set(x_17, 1, x_13);
lean_ctor_set(x_17, 2, x_14);
lean_ctor_set(x_17, 3, x_15);
lean_ctor_set_uint8(x_17, sizeof(void*)*4, x_16);
return x_17;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_mkRegisteredUser(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; uint8_t x_6; lean_object* x_7; 
lean_inc_ref(x_1);
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_Salt_initial(x_1);
lean_inc_ref(x_3);
x_4 = lp_VerifiableAuthSpec_VerifiableAuth_derivePasswordHash(x_2, x_3);
x_5 = lean_unsigned_to_nat(0u);
x_6 = 0;
x_7 = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(x_7, 0, x_1);
lean_ctor_set(x_7, 1, x_3);
lean_ctor_set(x_7, 2, x_4);
lean_ctor_set(x_7, 3, x_5);
lean_ctor_set_uint8(x_7, sizeof(void*)*4, x_6);
return x_7;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec___private_VerifiableAuth_StateModel_0__VerifiableAuth_lookupUserInList(lean_object* x_1, lean_object* x_2) {
_start:
{
if (lean_obj_tag(x_1) == 0)
{
lean_object* x_3; 
x_3 = lean_box(0);
return x_3;
}
else
{
lean_object* x_4; lean_object* x_5; lean_object* x_6; uint8_t x_7; 
x_4 = lean_ctor_get(x_1, 0);
x_5 = lean_ctor_get(x_1, 1);
x_6 = lean_ctor_get(x_4, 0);
x_7 = lean_string_dec_eq(x_6, x_2);
if (x_7 == 0)
{
x_1 = x_5;
goto _start;
}
else
{
lean_object* x_9; 
lean_inc(x_4);
x_9 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_9, 0, x_4);
return x_9;
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec___private_VerifiableAuth_StateModel_0__VerifiableAuth_lookupUserInList___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec___private_VerifiableAuth_StateModel_0__VerifiableAuth_lookupUserInList(x_1, x_2);
lean_dec_ref(x_2);
lean_dec(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec___private_VerifiableAuth_StateModel_0__VerifiableAuth_replaceUserInList(lean_object* x_1, lean_object* x_2) {
_start:
{
if (lean_obj_tag(x_1) == 0)
{
lean_dec_ref(x_2);
return x_1;
}
else
{
uint8_t x_3; 
x_3 = !lean_is_exclusive(x_1);
if (x_3 == 0)
{
lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; uint8_t x_8; 
x_4 = lean_ctor_get(x_1, 0);
x_5 = lean_ctor_get(x_1, 1);
x_6 = lean_ctor_get(x_4, 0);
x_7 = lean_ctor_get(x_2, 0);
x_8 = lean_string_dec_eq(x_6, x_7);
if (x_8 == 0)
{
lean_object* x_9; 
x_9 = lp_VerifiableAuthSpec___private_VerifiableAuth_StateModel_0__VerifiableAuth_replaceUserInList(x_5, x_2);
lean_ctor_set(x_1, 1, x_9);
return x_1;
}
else
{
lean_dec(x_4);
lean_ctor_set(x_1, 0, x_2);
return x_1;
}
}
else
{
lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; uint8_t x_14; 
x_10 = lean_ctor_get(x_1, 0);
x_11 = lean_ctor_get(x_1, 1);
lean_inc(x_11);
lean_inc(x_10);
lean_dec(x_1);
x_12 = lean_ctor_get(x_10, 0);
x_13 = lean_ctor_get(x_2, 0);
x_14 = lean_string_dec_eq(x_12, x_13);
if (x_14 == 0)
{
lean_object* x_15; lean_object* x_16; 
x_15 = lp_VerifiableAuthSpec___private_VerifiableAuth_StateModel_0__VerifiableAuth_replaceUserInList(x_11, x_2);
x_16 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_16, 0, x_10);
lean_ctor_set(x_16, 1, x_15);
return x_16;
}
else
{
lean_object* x_17; 
lean_dec(x_10);
x_17 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_17, 0, x_2);
lean_ctor_set(x_17, 1, x_11);
return x_17;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuthState_lookupUser_x3f(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; 
x_3 = lean_ctor_get(x_1, 0);
x_4 = lp_VerifiableAuthSpec___private_VerifiableAuth_StateModel_0__VerifiableAuth_lookupUserInList(x_3, x_2);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuthState_lookupUser_x3f___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_AuthState_lookupUser_x3f(x_1, x_2);
lean_dec_ref(x_2);
lean_dec_ref(x_1);
return x_3;
}
}
LEAN_EXPORT uint8_t lp_VerifiableAuthSpec_VerifiableAuth_AuthState_containsUser(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_AuthState_lookupUser_x3f(x_1, x_2);
if (lean_obj_tag(x_3) == 0)
{
uint8_t x_4; 
x_4 = 0;
return x_4;
}
else
{
uint8_t x_5; 
lean_dec_ref(x_3);
x_5 = 1;
return x_5;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuthState_containsUser___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = lp_VerifiableAuthSpec_VerifiableAuth_AuthState_containsUser(x_1, x_2);
lean_dec_ref(x_2);
lean_dec_ref(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuthState_insertUser(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; 
x_3 = !lean_is_exclusive(x_1);
if (x_3 == 0)
{
lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; 
x_4 = lean_ctor_get(x_1, 0);
x_5 = lean_box(0);
x_6 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_6, 0, x_2);
lean_ctor_set(x_6, 1, x_5);
x_7 = l_List_appendTR___redArg(x_4, x_6);
lean_ctor_set(x_1, 0, x_7);
return x_1;
}
else
{
lean_object* x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; 
x_8 = lean_ctor_get(x_1, 0);
x_9 = lean_ctor_get(x_1, 1);
lean_inc(x_9);
lean_inc(x_8);
lean_dec(x_1);
x_10 = lean_box(0);
x_11 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_11, 0, x_2);
lean_ctor_set(x_11, 1, x_10);
x_12 = l_List_appendTR___redArg(x_8, x_11);
x_13 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_13, 0, x_12);
lean_ctor_set(x_13, 1, x_9);
return x_13;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuthState_replaceUser(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; 
x_3 = !lean_is_exclusive(x_1);
if (x_3 == 0)
{
lean_object* x_4; lean_object* x_5; 
x_4 = lean_ctor_get(x_1, 0);
x_5 = lp_VerifiableAuthSpec___private_VerifiableAuth_StateModel_0__VerifiableAuth_replaceUserInList(x_4, x_2);
lean_ctor_set(x_1, 0, x_5);
return x_1;
}
else
{
lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; 
x_6 = lean_ctor_get(x_1, 0);
x_7 = lean_ctor_get(x_1, 1);
lean_inc(x_7);
lean_inc(x_6);
lean_dec(x_1);
x_8 = lp_VerifiableAuthSpec___private_VerifiableAuth_StateModel_0__VerifiableAuth_replaceUserInList(x_6, x_2);
x_9 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_9, 0, x_8);
lean_ctor_set(x_9, 1, x_7);
return x_9;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuthState_clearSession(lean_object* x_1) {
_start:
{
uint8_t x_2; 
x_2 = !lean_is_exclusive(x_1);
if (x_2 == 0)
{
lean_object* x_3; lean_object* x_4; 
x_3 = lean_ctor_get(x_1, 1);
lean_dec(x_3);
x_4 = lean_box(0);
lean_ctor_set(x_1, 1, x_4);
return x_1;
}
else
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; 
x_5 = lean_ctor_get(x_1, 0);
lean_inc(x_5);
lean_dec(x_1);
x_6 = lean_box(0);
x_7 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_7, 0, x_5);
lean_ctor_set(x_7, 1, x_6);
return x_7;
}
}
}
LEAN_EXPORT lean_object* lp_VerifiableAuthSpec_VerifiableAuth_AuthState_setAuthenticated(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; 
x_3 = !lean_is_exclusive(x_1);
if (x_3 == 0)
{
lean_object* x_4; lean_object* x_5; 
x_4 = lean_ctor_get(x_1, 1);
lean_dec(x_4);
x_5 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_5, 0, x_2);
lean_ctor_set(x_1, 1, x_5);
return x_1;
}
else
{
lean_object* x_6; lean_object* x_7; lean_object* x_8; 
x_6 = lean_ctor_get(x_1, 0);
lean_inc(x_6);
lean_dec(x_1);
x_7 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_7, 0, x_2);
x_8 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_8, 0, x_6);
lean_ctor_set(x_8, 1, x_7);
return x_8;
}
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_VerifiableAuthSpec_VerifiableAuth_Types(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_VerifiableAuthSpec_VerifiableAuth_StateModel(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_VerifiableAuthSpec_VerifiableAuth_Types(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
