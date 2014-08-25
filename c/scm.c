#include "scm.h"

#include <assert.h>

scm *scmalloc(scm s) {
  scm *sp = malloc(sizeof(scm));
  *sp = s;
  return sp;
}

scm* scm_char(char *s) {
  assert((unsigned)strlen(s) == 1);
  return scmalloc((scm){ .t = scm_type_char, .v.s = s });
}

scm* scm_string(char *s) {
  return scmalloc((scm){ .t = scm_type_string, .v.s = s });
}

scm* scm_vector_ref(scm *vec, int i) {
  return vec->v.v[i];
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
  if(s->t == scm_type_string || s->t == scm_type_symbol) {
    puts(s->v.s);
  }
  else if(s->t == scm_type_boolean) {
    printf("#%c\n", s->v.n ? 't' : 'f');
  }
  else if(s->t == scm_type_number) {
    printf("%d\n", s->v.n);
  }
  
  return NULL;
}

scm* scm_newline(scm* env) {
  puts("");
  return NULL;
}

scm* scm_put_string(scm* env, scm *s) {
  printf("%s", s->v.s);
  return NULL;
}


scm* scm_char_to_string(scm *env, scm *s) {
  assert(s->t == scm_type_char);
  return scm_string(s->v.s);
}

scm* scm_string_to_char(scm *env, scm *s) {
  assert(s->t == scm_type_string);
  return scm_char(s->v.s);
}

scm* scm_string_to_number(scm *env, scm *s) {
  assert(s->t == scm_type_string);
  return scmalloc((scm){ .t = scm_type_number, .v.n = atoi(s->v.s) });
}

scm* scm_string_to_symbol(scm *env, scm *s) {
  assert(s->t == scm_type_string);
  return scm_make_symbol(s->v.s);
}

scm* scm_string_append(scm* env, scm *a, scm *b) {
  assert((a->t == scm_type_string && b->t == scm_type_string)
         || (a->t == scm_type_char && b->t == scm_type_char));
  char* s1 = a->v.s;
  char* s2 = b->v.s;
  char* new = malloc(strlen(s1)+strlen(s2)+1);
  new[0] = '\0';
  strcat(new,s1);
  strcat(new,s2);
  return scm_string(new);
}

scm* scm_string_length(scm* env, scm* s) {
  return scmalloc((scm){ .t = scm_type_number, .v.n = strlen(s->v.s) });
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
  return scmalloc((scm){ .t = scm_type_boolean, .v.n = eqp });  
}

scm *scm_num_lt(scm* env, scm* a, scm* b) {
  assert(a->t == scm_type_number && b->t == scm_type_number);
  int eqp = a->v.n < b->v.n;
  return scmalloc((scm){ .t = scm_type_boolean, .v.n = eqp });  
}

scm *scm_num_lte(scm* env, scm* a, scm* b) {
  assert(a->t == scm_type_number && b->t == scm_type_number);
  int eqp = a->v.n <= b->v.n;
  return scmalloc((scm){ .t = scm_type_boolean, .v.n = eqp });  
}

scm *scm_num_gt(scm* env, scm* a, scm* b) {
  assert(a->t == scm_type_number && b->t == scm_type_number);
  int eqp = a->v.n > b->v.n;
  return scmalloc((scm){ .t = scm_type_boolean, .v.n = eqp });  
}

scm *scm_num_gte(scm* env, scm* a, scm* b) {
  assert(a->t == scm_type_number && b->t == scm_type_number);
  int eqp = a->v.n >= b->v.n;
  return scmalloc((scm){ .t = scm_type_boolean, .v.n = eqp });  
}

scm *scm_number_to_string(scm* env, scm* n) {
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
  
  if((a->t == scm_type_symbol || a->t == scm_type_string) &&
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
scm *scm_char_question(scm* env, scm* obj) {
  if(obj->t == scm_type_char)
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
  if(obj->t == scm_type_pair &&
     obj->v.cons.car->t == scm_type_fptr)
    return scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  return scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}
