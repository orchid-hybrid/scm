#include "scm.h"

#include <assert.h>

scm *scmalloc(scm s) {
  scm *sp = malloc(sizeof(scm));
  *sp = s;
  return sp;
}

scm* scm_string(char *s) {
  return scmalloc((scm){ .t = scm_type_string, .v.s = s });
}

scm* scm_vector_ref(scm *vec, int i) {
  return vec->v.v[i];
}

scm* scm_vector0() {
  return scmalloc((scm){ .t = scm_type_vector, .v.v = NULL });
}

scm* scm_vector1(scm *v0) {
  scm **v = malloc(sizeof(scm*));
  v[0] = v0;
  return scmalloc((scm){ .t = scm_type_vector, .v.v = v });
}

scm* scm_vector2(scm *v0, scm *v1) {
  scm **v = malloc(2*sizeof(scm*));
  v[0] = v0;
  v[1] = v1;
  return scmalloc((scm){ .t = scm_type_vector, .v.v = v });
}

scm* scm_vector3(scm *v0, scm *v1, scm *v2) {
  scm **v = malloc(3*sizeof(scm*));
  v[0] = v0;
  v[1] = v1;
  v[2] = v2;
  return scmalloc((scm){ .t = scm_type_vector, .v.v = v });
}

scm* scm_vector4(scm *v0, scm *v1, scm *v2, scm *v3) {
  scm **v = malloc(4*sizeof(scm*));
  v[0] = v0;
  v[1] = v1;
  v[2] = v2;
  v[3] = v3;
  return scmalloc((scm){ .t = scm_type_vector, .v.v = v });
}

scm* scm_vector5(scm *v0, scm *v1, scm *v2, scm *v3, scm *v4) {
  scm **v = malloc(5*sizeof(scm*));
  v[0] = v0;
  v[1] = v1;
  v[2] = v2;
  v[3] = v3;
  v[4] = v4;
  return scmalloc((scm){ .t = scm_type_vector, .v.v = v });
}

scm* scm_vector6(scm *v0, scm *v1, scm *v2, scm *v3, scm *v4, scm *v5) {
  scm **v = malloc(6*sizeof(scm*));
  v[0] = v0;
  v[1] = v1;
  v[2] = v2;
  v[3] = v3;
  v[4] = v4;
  v[5] = v5;
  return scmalloc((scm){ .t = scm_type_vector, .v.v = v });
}

scm* scm_vector7(scm *v0, scm *v1, scm *v2, scm *v3, scm *v4, scm *v5, scm *v6) {
  scm **v = malloc(7*sizeof(scm*));
  v[0] = v0;
  v[1] = v1;
  v[2] = v2;
  v[3] = v3;
  v[4] = v4;
  v[5] = v5;
  v[6] = v6;
  return scmalloc((scm){ .t = scm_type_vector, .v.v = v });
}

scm* scm_vector8(scm *v0, scm *v1, scm *v2, scm *v3, scm *v4, scm *v5, scm *v6, scm *v7) {
  scm **v = malloc(8*sizeof(scm*));
  v[0] = v0;
  v[1] = v1;
  v[2] = v2;
  v[3] = v3;
  v[4] = v4;
  v[5] = v5;
  v[6] = v6;
  v[7] = v7;
  return scmalloc((scm){ .t = scm_type_vector, .v.v = v });
}
scm* scm_vector9(scm *v0, scm *v1, scm *v2, scm *v3, scm *v4, scm *v5, scm *v6, scm *v7, scm *v8) {
  scm **v = malloc(9*sizeof(scm*));
  v[0] = v0;
  v[1] = v1;
  v[2] = v2;
  v[3] = v3;
  v[4] = v4;
  v[5] = v5;
  v[6] = v6;
  v[7] = v7;
 v[8] = v8;
  return scmalloc((scm){ .t = scm_type_vector, .v.v = v });
}


scm* scm_make_pair(scm* car, scm* cdr) {
  scm p;
  
  p.t = scm_type_pair;
  p.v.cons.car = car;
  p.v.cons.cdr = cdr;
  
  return scmalloc(p);
}

scm* scm_make_symbol(char *s) {
  return scmalloc((scm){ .t = scm_type_symbol, .v.s = s });
}

scm* scm_make_closure(scm_fptr code, scm* env) {
  return scm_make_pair(scmalloc((scm){ .t = scm_type_fptr, .v.f = code}), env);
}

scm* scm_invoke_closure1(scm *clos) {
  if(clos->t != scm_type_pair) { puts("!PAIR"); exit(0); }
  if(clos->v.cons.car->t != scm_type_fptr) { puts("!FPTR"); exit(0); }
  if(clos->v.cons.cdr->t != scm_type_vector) { puts("!VECTOR"); exit(0); }
  
  scm_fptr code = clos->v.cons.car->v.f;
  scm** env = clos->v.cons.cdr->v.v;
  return code(env);
}

scm* scm_invoke_closure2(scm *clos, scm *p1) {
  if(clos->t != scm_type_pair) { puts("!PAIR"); exit(0); }
  if(clos->v.cons.car->t != scm_type_fptr) { puts("!FPTR"); exit(0); }
  if(clos->v.cons.cdr->t != scm_type_vector) { puts("!VECTOR"); exit(0); }
  
  scm_fptr code = clos->v.cons.car->v.f;
  scm** env = clos->v.cons.cdr->v.v;
  return code(env,p1);
}

scm* scm_invoke_closure3(scm *clos, scm *p1, scm *p2) {
  if(clos->t != scm_type_pair) { puts("!PAIR"); exit(0); }
  if(clos->v.cons.car->t != scm_type_fptr) { puts("!FPTR"); exit(0); }
  if(clos->v.cons.cdr->t != scm_type_vector) { puts("!VECTOR"); exit(0); }
  
  scm_fptr code = clos->v.cons.car->v.f;
  scm** env = clos->v.cons.cdr->v.v;
  return code(env,p1,p2);
}

scm* scm_invoke_closure4(scm *clos, scm *p1, scm *p2, scm *p3) {
  if(clos->t != scm_type_pair) { puts("!PAIR"); exit(0); }
  if(clos->v.cons.car->t != scm_type_fptr) { puts("!FPTR"); exit(0); }
  if(clos->v.cons.cdr->t != scm_type_vector) { puts("!VECTOR"); exit(0); }
  
  scm_fptr code = clos->v.cons.car->v.f;
  scm** env = clos->v.cons.cdr->v.v;
  return code(env,p1,p2,p3);
}

scm* scm_invoke_closure5(scm *clos, scm *p1, scm *p2, scm *p3, scm *p4) {
  if(clos->t != scm_type_pair) { puts("!PAIR"); exit(0); }
  if(clos->v.cons.car->t != scm_type_fptr) { puts("!FPTR"); exit(0); }
  if(clos->v.cons.cdr->t != scm_type_vector) { puts("!VECTOR"); exit(0); }
  
  scm_fptr code = clos->v.cons.car->v.f;
  scm** env = clos->v.cons.cdr->v.v;
  return code(env,p1,p2,p3,p4);
}


scm* scm_wrap_prim(scm_fptr prim) {
  return scm_make_closure(prim, scm_vector0());
}

scm* scm_print(scm* env, scm *s) {
  puts(s->v.s);
  return NULL;
}

scm* scm_newline(scm* env) {
  puts("");
  return NULL;
}

scm* scm_cons(scm* env, scm *car, scm *cdr) {
  return scm_make_pair(car,cdr);
}
scm* scm_car(scm* env, scm* pair) {
  assert(pair->t == scm_type_pair);
  return pair->v.cons.car;
}
scm* scm_cdr(scm* env, scm* pair) {
  assert(pair->t == scm_type_pair);
  return pair->v.cons.cdr;
}
scm* scm_set_car(scm* env, scm* pair, scm *newcar) {
  assert(pair->t == scm_type_pair);
  pair->v.cons.car = newcar;
  return NULL;
}
scm* scm_set_cdr(scm* env, scm* pair, scm *newcdr) {
  assert(pair->t == scm_type_pair);
  pair->v.cons.cdr = newcdr;
  return NULL;
}

scm* scm_add(scm* env, scm* a, scm* b) {
  assert(a->t == scm_type_number && b->t == scm_type_number);
  int sum = a->v.n + b->v.n;
  return scmalloc((scm){ .t = scm_type_number, .v.n = sum });
}
scm* scm_mul(scm* env, scm* a, scm* b) {
  assert(a->t == scm_type_number && b->t == scm_type_number);
  int prod = a->v.n * b->v.n;
  return scmalloc((scm){ .t = scm_type_number, .v.n = prod });
}

scm* scm_div(scm* env, scm* a, scm* b) {
  assert(a->t == scm_type_number && b->t == scm_type_number);
  int quot = a->v.n / b->v.n;
  return scmalloc((scm){ .t = scm_type_number, .v.n = quot });
}

scm *scm_sub(scm* env, scm* a, scm* b) {
  assert(a->t == scm_type_number && b->t == scm_type_number);
  int diff = a->v.n - b->v.n;
  return scmalloc((scm){ .t = scm_type_number, .v.n = diff });  
}

scm *scm_num_eq(scm* env, scm* a, scm* b) {
  assert(a->t == scm_type_number && b->t == scm_type_number);
  int eqp = a->v.n == b->v.n;
  return scmalloc((scm){ .t = scm_type_number, .v.n = eqp });  
}

scm *scm_num_to_string(scm* env, scm* n) {
  assert(n->t == scm_type_number);
  char* buff = malloc(sizeof(char) * 30);
  sprintf(buff, "%i", n->v.n);
  return scm_string(buff);
}


scm *scm_boolean(scm* env, scm* b, scm* thn, scm* els) {
  //assert(b.t == scm_type_boolean);
  if(b->t == scm_type_boolean &&
     b->v.n == 0) {
    return scm_invoke_closure1(els);
  }
  return scm_invoke_closure1(thn);
}

scm* scm_eq_question(scm* env, scm* a, scm* b) {
  if(a->t != b->t) return scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
  
  if(a->t == scm_type_symbol &&
     !strcmp(a->v.s,b->v.s))
    return scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  
  return scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm *scm_number_question(scm* env, scm* obj) {
  if(obj->t == scm_type_number)
    return scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  return scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}
scm *scm_boolean_question(scm* env, scm* obj) {
  if(obj->t == scm_type_boolean)
    return scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  return scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}
scm *scm_string_question(scm* env, scm* obj) {
  if(obj->t == scm_type_string)
    return scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  return scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}
scm *scm_symbol_question(scm* env, scm* obj) {
  if(obj->t == scm_type_symbol)
    return scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  return scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}
scm *scm_vector_question(scm* env, scm* obj) {
  if(obj->t == scm_type_vector)
    return scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  return scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}
scm *scm_null_question(scm* env, scm* obj) {
  if(obj->t == scm_type_null)
    return scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  return scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}
scm *scm_pair_question(scm* env, scm* obj) {
  if(obj->t == scm_type_pair)
    return scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  return scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}
scm *scm_procedure_question(scm* env, scm* obj) {
  if(obj->t == scm_type_fptr)
    return scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  return scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}
