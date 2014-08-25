#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum scm_type {
  scm_type_number,
  scm_type_boolean,
  scm_type_string,
  scm_type_char,
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

scm* scm_char(char *s);
scm* scm_string(char *s);

scm* scm_vector_ref(scm* vec, int i);

#include "scm_vector.h"

scm* scm_make_pair(scm* car, scm* cdr);
scm* scm_make_symbol(char *s);

scm* scm_make_closure(scm_fptr code, scm* env);
scm* scm_invoke_closure1(scm* clos);
scm* scm_invoke_closure2(scm* clos, scm* p1);
scm* scm_invoke_closure3(scm* clos, scm* p1, scm* p2);
scm* scm_invoke_closure4(scm* clos, scm* p1, scm* p2, scm* p3);
scm* scm_invoke_closure5(scm* clos, scm* p1, scm* p2, scm* p3, scm* p4);

/* PRIMITIVES */

scm* scm_wrap_prim(scm_fptr prim);

scm* scm_print(scm* env, scm* s);
scm* scm_newline(scm* env);
scm* scm_put_string(scm* env, scm *s);
scm* scm_string_append(scm* env, scm *a, scm *b);
scm* scm_string_length(scm* env, scm* s);

scm* scm_string_to_char(scm *env, scm *s);
scm* scm_string_to_symbol(scm *env, scm *s);
scm* scm_string_to_number(scm *env, scm *s);

scm* scm_cons(scm* env, scm* car, scm* cdr);
scm* scm_car(scm* env, scm* pair);
scm* scm_cdr(scm* env, scm* pair);
scm* scm_set_car(scm* env, scm* pair, scm *newcar);
scm* scm_set_cdr(scm* env, scm* pair, scm *newcdr);

scm* scm_add(scm* env, scm* a, scm* b);
scm* scm_mul(scm* env, scm* a, scm* b);
scm* scm_sub(scm* env, scm* a, scm* b);
scm* scm_div(scm* env, scm* a, scm* b);
scm* scm_num_eq(scm* env, scm* a, scm* b);
scm* scm_num_lt(scm* env, scm* a, scm* b);
scm* scm_num_lte(scm* env, scm* a, scm* b);
scm* scm_num_gt(scm* env, scm* a, scm* b);
scm* scm_num_gte(scm* env, scm* a, scm* b);
scm* scm_number_to_string(scm* env, scm* n);

scm* scm_boolean(scm* env, scm* b, scm* thn, scm* els);
scm* scm_eq_question(scm* env, scm* a, scm* b);
scm* scm_string_equal_question(scm* env, scm* a, scm* b);

scm* scm_number_question(scm* env, scm* obj);
scm* scm_boolean_question(scm* env, scm* obj);
scm* scm_char_question(scm* env, scm* obj);
scm* scm_string_question(scm* env, scm* obj);
scm* scm_symbol_question(scm* env, scm* obj);
scm* scm_vector_question(scm* env, scm* obj);
scm* scm_null_question(scm* env, scm* obj);
scm* scm_pair_question(scm* env, scm* obj);
scm* scm_procedure_question(scm* env, scm* obj);
