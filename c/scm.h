#include <stdlib.h>
#include <stdio.h>

enum scm_type {
  scm_type_number,
  scm_type_boolean,
  scm_type_string,
  scm_type_symbol,
  scm_type_vector,
  scm_type_null,
  scm_type_pair,
  scm_type_fptr
};

typedef struct scm scm;

typedef scm* (*scm_fptr)();

struct scm {
  enum scm_type t;
  union {
    int n;
    char *s;
    struct scm** v;
    struct {
      struct scm *car;
      struct scm *cdr;
    } cons;
    scm_fptr f;
  } v;
};

scm *scmalloc(scm s);

scm* scm_string(char *s);

scm* scm_vector_ref(scm* vec, int i);

scm* scm_vector0();
scm* scm_vector1(scm *v0);
scm* scm_vector2(scm *v0, scm *v1);
scm* scm_vector3(scm *v0, scm *v1, scm *v2);
scm* scm_vector4(scm *v0, scm *v1, scm *v2, scm *v3);
scm* scm_vector5(scm *v0, scm *v1, scm *v2, scm *v3, scm *v4);
scm* scm_vector6(scm *v0, scm *v1, scm *v2, scm *v3, scm *v4, scm *v5);
scm* scm_vector7(scm *v0, scm *v1, scm *v2, scm *v3, scm *v4, scm *v5, scm *v6);
scm* scm_vector8(scm *v0, scm *v1, scm *v2, scm *v3, scm *v4, scm *v5, scm *v6, scm *v7);
scm* scm_vector9(scm *v0, scm *v1, scm *v2, scm *v3, scm *v4, scm *v5, scm *v6, scm *v7, scm *v8);

scm* scm_make_pair(scm* car, scm* cdr);
scm* scm_make_symbol(char *s);

scm* scm_make_closure(scm_fptr code, scm* env);
scm* scm_invoke_closure1(scm* clos);
scm* scm_invoke_closure2(scm* clos, scm* p1);
scm* scm_invoke_closure3(scm* clos, scm* p1, scm* p2);
scm* scm_invoke_closure4(scm* clos, scm* p1, scm* p2, scm* p3);
scm* scm_invoke_closure5(scm* clos, scm* p1, scm* p2, scm* p3, scm* p4);

// PRIMITIVES

scm* scm_wrap_prim(scm_fptr prim);

scm* scm_print(scm* env, scm* s);
scm* scm_newline(scm* env);

scm* scm_cons(scm* env, scm* car, scm* cdr);
scm* scm_car(scm* env, scm* pair);
scm* scm_cdr(scm* env, scm* pair);

scm* scm_add(scm* env, scm* s);
scm* scm_mul(scm* env, scm* s);
scm* scm_sub(scm* env, scm* s);
scm* scm_num_eq(scm* env, scm* s);

scm* scm_boolean(scm* env, scm* b, scm* thn, scm* els);
scm* scm_null_question(scm* env, scm* n);
scm* scm_eq_question(scm* env, scm* a, scm* b);
