#include "scm.h"
#include "gc.h"

#include <assert.h>

scm *scalloc(scm s) {
  //scm *sp = malloc(sizeof(scm));
  scm *sp = (scm*)gc_alloc(sizeof(scm));
  *sp = s;
  return sp;
}

scm* scm_char(char *s) {
  assert((unsigned)strlen(s) == 1);
  return scalloc((scm){ .t = scm_type_char, .v.s = s });
}

scm* scm_newchar(char *s) {
  char *t = malloc(2);
  t[0]=s[0];
  t[1]=0;
  return scalloc((scm){ .t = scm_type_char, .v.s = t });
}

scm* scm_string(char *s) {
  return scalloc((scm){ .t = scm_type_string, .v.s = s });
}

scm* scm_vector_ref(scm *vec, int i) {
  return vec->v.vektor.v[i];
}

scm* scm_make_pair(scm* car, scm* cdr) {
  scm p;
  
  p.t = scm_type_pair;
  p.v.cons.car = car;
  p.v.cons.cdr = cdr;
  
  return scalloc(p);
}

scm* scm_make_symbol(char *s) {
  return scalloc((scm){ .t = scm_type_symbol, .v.s = s });
}

scm* scm_make_closure(scm_fptr code, scm* env) {
  return scm_make_pair(scalloc((scm){ .t = scm_type_fptr, .v.f = code}), env);
}

scm* scm_invoke_closure1(scm *clos) {
  if(clos->t != scm_type_pair) { puts("!PAIR"); exit(0); }
  if(clos->v.cons.car->t != scm_type_fptr) { puts("!FPTR"); exit(0); }
  if(clos->v.cons.cdr->t != scm_type_vector) { puts("!VECTOR"); exit(0); }
  
  scm_fptr code = clos->v.cons.car->v.f;
  scm** env = clos->v.cons.cdr->v.vektor.v;
  return code(env);
}

scm* scm_invoke_closure2(scm *clos, scm *p1) {
  if(clos->t != scm_type_pair) { puts("!PAIR"); exit(0); }
  if(clos->v.cons.car->t != scm_type_fptr) { puts("!FPTR"); exit(0); }
  if(clos->v.cons.cdr->t != scm_type_vector) { puts("!VECTOR"); exit(0); }
  
  scm_fptr code = clos->v.cons.car->v.f;
  scm** env = clos->v.cons.cdr->v.vektor.v;
  return code(env,p1);
}

scm* scm_invoke_closure3(scm *clos, scm *p1, scm *p2) {
  if(clos->t != scm_type_pair) { puts("!PAIR"); exit(0); }
  if(clos->v.cons.car->t != scm_type_fptr) { puts("!FPTR"); exit(0); }
  if(clos->v.cons.cdr->t != scm_type_vector) { puts("!VECTOR"); exit(0); }
  
  scm_fptr code = clos->v.cons.car->v.f;
  scm** env = clos->v.cons.cdr->v.vektor.v;
  return code(env,p1,p2);
}

scm* scm_invoke_closure4(scm *clos, scm *p1, scm *p2, scm *p3) {
  if(clos->t != scm_type_pair) { puts("!PAIR"); exit(0); }
  if(clos->v.cons.car->t != scm_type_fptr) { puts("!FPTR"); exit(0); }
  if(clos->v.cons.cdr->t != scm_type_vector) { puts("!VECTOR"); exit(0); }
  
  scm_fptr code = clos->v.cons.car->v.f;
  scm** env = clos->v.cons.cdr->v.vektor.v;
  return code(env,p1,p2,p3);
}

scm* scm_invoke_closure5(scm *clos, scm *p1, scm *p2, scm *p3, scm *p4) {
  if(clos->t != scm_type_pair) { puts("!PAIR"); exit(0); }
  if(clos->v.cons.car->t != scm_type_fptr) { puts("!FPTR"); exit(0); }
  if(clos->v.cons.cdr->t != scm_type_vector) { puts("!VECTOR"); exit(0); }
  
  scm_fptr code = clos->v.cons.car->v.f;
  scm** env = clos->v.cons.cdr->v.vektor.v;
  return code(env,p1,p2,p3,p4);
}

scm* scm_invoke_closure6(scm *clos, scm *p1, scm *p2, scm *p3, scm *p4, scm *p5) {
  if(clos->t != scm_type_pair) { puts("!PAIR"); exit(0); }
  if(clos->v.cons.car->t != scm_type_fptr) { puts("!FPTR"); exit(0); }
  if(clos->v.cons.cdr->t != scm_type_vector) { puts("!VECTOR"); exit(0); }
  
  scm_fptr code = clos->v.cons.car->v.f;
  scm** env = clos->v.cons.cdr->v.vektor.v;
  return code(env,p1,p2,p3,p4,p5);
}

scm* scm_invoke_closure7(scm *clos, scm *p1, scm *p2, scm *p3, scm *p4, scm *p5, scm *p6) {
  if(clos->t != scm_type_pair) { puts("!PAIR"); exit(0); }
  if(clos->v.cons.car->t != scm_type_fptr) { puts("!FPTR"); exit(0); }
  if(clos->v.cons.cdr->t != scm_type_vector) { puts("!VECTOR"); exit(0); }
  
  scm_fptr code = clos->v.cons.car->v.f;
  scm** env = clos->v.cons.cdr->v.vektor.v;
  return code(env,p1,p2,p3,p4,p5,p6);
}


scm* scm_invoke_closure8(scm *clos, scm *p1, scm *p2, scm *p3, scm *p4, scm *p5, scm *p6, scm *p7) {
  if(clos->t != scm_type_pair) { puts("!PAIR"); exit(0); }
  if(clos->v.cons.car->t != scm_type_fptr) { puts("!FPTR"); exit(0); }
  if(clos->v.cons.cdr->t != scm_type_vector) { puts("!VECTOR"); exit(0); }
  
  scm_fptr code = clos->v.cons.car->v.f;
  scm** env = clos->v.cons.cdr->v.vektor.v;
  return code(env,p1,p2,p3,p4,p5,p6,p7);
}

scm* scm_invoke_closure9(scm *clos, scm *p1, scm *p2, scm *p3, scm *p4, scm *p5, scm *p6, scm *p7, scm *p8) {
  if(clos->t != scm_type_pair) { puts("!PAIR"); exit(0); }
  if(clos->v.cons.car->t != scm_type_fptr) { puts("!FPTR"); exit(0); }
  if(clos->v.cons.cdr->t != scm_type_vector) { puts("!VECTOR"); exit(0); }
  
  scm_fptr code = clos->v.cons.car->v.f;
  scm** env = clos->v.cons.cdr->v.vektor.v;
  return code(env,p1,p2,p3,p4,p5,p6,p7,p8);
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

scm* scm_error(scm* env, scm *s) {
  puts("EXITING WITH ERROR");
  puts(s->v.s);
  puts("EXITING WITH ERROR");
  exit(-1);
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

scm* scm_newline_character(scm* env) {
  char* s = "\n";
  return scm_newchar(s);
}

scm* scm_read_char0(scm *env) {
  int c = getc(stdin);
  
  if(c == -1) {
    // eof object
    return scalloc((scm){ .t = scm_type_number, .v.n = -1 });
  }
  else {
    char x = c;
    return scm_newchar(&x);
  }
}

scm* scm_peek_char0(scm *env) {
  int c = getc(stdin);
  
  if(c == -1) {
    // eof object
    return scalloc((scm){ .t = scm_type_number, .v.n = -1 });
  }
  else {
    char x = c;
    
    ungetc(c, stdin);
    
    return scm_newchar(&x);
  }
}


scm* scm_symbol_to_string(scm *env, scm *s) {
  assert(s->t == scm_type_symbol);
  return scm_string(s->v.s);
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
  return scalloc((scm){ .t = scm_type_number, .v.n = atoi(s->v.s) });
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
  return scalloc((scm){ .t = scm_type_number, .v.n = strlen(s->v.s) });
}

scm* scm_string_ref(scm *env, scm *i, scm *s) {
  assert(s->t == scm_type_string);
  assert(i->t == scm_type_number);
  return scm_newchar(s->v.s + i->v.n);
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
  return scalloc((scm){ .t = scm_type_number, .v.n = sum });
}
scm* scm_mul(scm* env, scm* a, scm* b) {
  assert(a->t == scm_type_number && b->t == scm_type_number);
  int prod = a->v.n * b->v.n;
  return scalloc((scm){ .t = scm_type_number, .v.n = prod });
}

scm* scm_div(scm* env, scm* a, scm* b) {
  assert(a->t == scm_type_number && b->t == scm_type_number);
  int quot = a->v.n / b->v.n;
  return scalloc((scm){ .t = scm_type_number, .v.n = quot });
}

scm *scm_sub(scm* env, scm* a, scm* b) {
  assert(a->t == scm_type_number && b->t == scm_type_number);
  int diff = a->v.n - b->v.n;
  return scalloc((scm){ .t = scm_type_number, .v.n = diff });  
}

scm *scm_num_eq(scm* env, scm* a, scm* b) {
  assert(a->t == scm_type_number && b->t == scm_type_number);
  int eqp = a->v.n == b->v.n;
  return scalloc((scm){ .t = scm_type_boolean, .v.n = eqp });  
}

scm *scm_num_lt(scm* env, scm* a, scm* b) {
  assert(a->t == scm_type_number && b->t == scm_type_number);
  int eqp = a->v.n < b->v.n;
  return scalloc((scm){ .t = scm_type_boolean, .v.n = eqp });  
}

scm *scm_num_lte(scm* env, scm* a, scm* b) {
  assert(a->t == scm_type_number && b->t == scm_type_number);
  int eqp = a->v.n <= b->v.n;
  return scalloc((scm){ .t = scm_type_boolean, .v.n = eqp });  
}

scm *scm_num_gt(scm* env, scm* a, scm* b) {
  assert(a->t == scm_type_number && b->t == scm_type_number);
  int eqp = a->v.n > b->v.n;
  return scalloc((scm){ .t = scm_type_boolean, .v.n = eqp });  
}

scm *scm_num_gte(scm* env, scm* a, scm* b) {
  assert(a->t == scm_type_number && b->t == scm_type_number);
  int eqp = a->v.n >= b->v.n;
  return scalloc((scm){ .t = scm_type_boolean, .v.n = eqp });  
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
  if(a->t != b->t) return scalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
  
  if((a->t == scm_type_symbol || a->t == scm_type_string || a->t == scm_type_char) &&
     !strcmp(a->v.s,b->v.s))
    return scalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  
  return scalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm *scm_number_question(scm* env, scm* obj) {
  if(obj->t == scm_type_number)
    return scalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  return scalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}
scm *scm_boolean_question(scm* env, scm* obj) {
  if(obj->t == scm_type_boolean)
    return scalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  return scalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}
scm *scm_char_question(scm* env, scm* obj) {
  if(obj->t == scm_type_char)
    return scalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  return scalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}
scm *scm_string_question(scm* env, scm* obj) {
  //printf("oee\n");
  //printf("%p\n", obj);
  if(obj->t == scm_type_string) {
    //printf("ok1\n");
    return scalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  }
  //printf("ok2\n");
  return scalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}
scm *scm_symbol_question(scm* env, scm* obj) {
  if(obj->t == scm_type_symbol)
    return scalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  return scalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}
scm *scm_vector_question(scm* env, scm* obj) {
  if(obj->t == scm_type_vector)
    return scalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  return scalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}
scm *scm_null_question(scm* env, scm* obj) {
  if(obj->t == scm_type_null)
    return scalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  return scalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}
scm *scm_pair_question(scm* env, scm* obj) {
  if(obj->t == scm_type_pair)
    return scalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  return scalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}
scm *scm_procedure_question(scm* env, scm* obj) {
  if(obj->t == scm_type_pair &&
     obj->v.cons.car->t == scm_type_fptr)
    return scalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
  return scalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}


scm* scm_string_to_list(scm* env, scm* str) {
  assert(str->t == scm_type_string);
  
  char *s = str->v.s;
  scm *list = scalloc((scm){ .t = scm_type_null });
  int i;
  
  for(i = strlen(s)-1; i >= 0; i--) {
    list = scm_make_pair(scm_newchar(s+i), list);
  }
  
  return list;
}
