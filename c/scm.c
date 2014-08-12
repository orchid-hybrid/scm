#include "scm.h"

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
