#include <stdlib.h>
#include <stdio.h>

enum scm_type {
  scm_type_string,
  scm_type_vector,
  scm_type_pair,
  scm_type_fptr
};

typedef struct scm scm;

typedef scm (*scm_fptr)();

struct scm {
  enum scm_type t;
  union {
    char *s;
    struct scm* v;
    struct {
      struct scm *car;
      struct scm *cdr;
    } cons;
    scm_fptr f;
  } v;
};

scm scm_string(char *s) {
  return (scm){ .t = scm_type_string, .v.s = s };
}

scm scm_vector_ref(scm vec, int i) {
  return vec.v.v[i];
}

scm scm_vector0() {
  return (scm){ .t = scm_type_vector, .v.v = NULL };
}

scm scm_vector1(scm v0) {
  scm *v = malloc(sizeof(scm));
  v[0] = v0;
  return (scm){ .t = scm_type_vector, .v.v = v };
}

scm scm_vector2(scm v0, scm v1) {
  scm *v = malloc(2*sizeof(scm));
  v[0] = v0;
  v[1] = v1;
  return (scm){ .t = scm_type_vector, .v.v = v };
}

scm scm_make_pair(scm car, scm cdr) {
  scm p;
  
  p.t = scm_type_pair;
  p.v.cons.car = malloc(sizeof(scm));
  *p.v.cons.car = car;
  p.v.cons.cdr = malloc(sizeof(scm));
  *p.v.cons.cdr = cdr;
  
  return p;
}

scm scm_make_closure(scm_fptr code, scm env) {
  return scm_make_pair((scm){ .t = scm_type_fptr, .v.f = code}, env);
}

scm scm_invoke_closure1(scm clos) {
  if(clos.t != scm_type_pair) { puts("!PAIR"); exit(0); }
  if(clos.v.cons.car->t != scm_type_fptr) { puts("!FPTR"); exit(0); }
  if(clos.v.cons.cdr->t != scm_type_vector) { puts("!VECTOR"); exit(0); }
  
  scm_fptr code = clos.v.cons.car->v.f;
  scm* env = clos.v.cons.cdr->v.v;
  return code(env);
}

scm scm_invoke_closure2(scm clos, scm p1) {
  if(clos.t != scm_type_pair) { puts("!PAIR"); exit(0); }
  if(clos.v.cons.car->t != scm_type_fptr) { puts("!FPTR"); exit(0); }
  if(clos.v.cons.cdr->t != scm_type_vector) { puts("!VECTOR"); exit(0); }
  
  scm_fptr code = clos.v.cons.car->v.f;
  scm* env = clos.v.cons.cdr->v.v;
  return code(env,p1);
}

scm scm_invoke_closure3(scm clos, scm p1, scm p2) {
  if(clos.t != scm_type_pair) { puts("!!PAIR"); exit(0); }
  if(clos.v.cons.car->t != scm_type_fptr) { puts("!!FPTR"); exit(0); }
  if(clos.v.cons.cdr->t != scm_type_vector) { puts("!!VECTOR"); exit(0); }
  
  scm_fptr code = clos.v.cons.car->v.f;
  scm* env = clos.v.cons.cdr->v.v;
  return code(env,p1,p2);
}

scm scm_print(scm* env, scm s) {
  puts(s.v.s);
}

//

/* test2

scm lambda0(scm *env, scm a, scm b) {
  return scm_invoke_closure1(env[0],b);
}

scm lambda1(scm *env, scm f) {
  return scm_invoke_closure2(scm_make_closure(lambda0, scm_vector1(f)), scm_invoke_closure1(f,scm_string("hello")), scm_string("world"));
}

scm lambda2(scm *env, scm s) {
  return scm_invoke_closure1(env[0],s);
}

*/

//

scm lambda0(scm *env, scm z, scm s) {
  return scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],z,s),s);
}
scm lambda1(scm *env, scm m, scm n) {
  return scm_make_closure(lambda0,scm_vector2(n,m));
}
scm lambda2(scm *env, scm z, scm s) {
  return scm_invoke_closure1(s,scm_invoke_closure1(s,scm_invoke_closure1(s,z)));
}
scm lambda3(scm *env, scm z, scm s) {
  return scm_invoke_closure1(s,scm_invoke_closure1(s,scm_invoke_closure1(s,scm_invoke_closure1(s,scm_invoke_closure1(s,z)))));
}
scm lambda4(scm *env, scm x, scm y) {
  return x;
}

scm lambda5(scm *env, scm s) {
  return scm_invoke_closure2(scm_make_closure(lambda4, scm_vector0()),
			     s,
			     scm_invoke_closure1(env[0], s));
}

//

main() {
  //scm_invoke_closure1(scm_make_closure(scm_print,scm_vector0()),scm_string("hello world"));
  
  //scm_invoke_closure1(scm_make_closure(lambda1,scm_vector0()),scm_make_closure(lambda2,scm_vector1(scm_make_closure(scm_print,scm_vector0()))));
  
  scm_invoke_closure2(scm_invoke_closure2(scm_make_closure(lambda1,scm_vector0()),
                                          scm_make_closure(lambda2,scm_vector0()),
                                          scm_make_closure(lambda3,scm_vector0())),
                      scm_string("HELLO WORLD!!!"),
                      scm_make_closure(lambda5,scm_vector1(scm_make_closure(scm_print,scm_vector0()))));


  scm_invoke_closure3(scm_invoke_closure3(make_closure(lambda1,scm_vector0()),
                                          make_closure(lambda2,scm_vector0()),
                                          make_closure(lambda3,scm_vector0())),
                      scm_string("HELLO WORLD!!!"),
                      make_closure(lambda5,scm_vector1(print)));

}
