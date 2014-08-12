#include "scm.h"

scm lambda0(scm* env, scm z, scm s) {
  return scm_invoke_closure3(env[0],scm_invoke_closure3(env[1],z,s),s);
}

scm lambda1(scm* env, scm m, scm n) {
  return scm_make_closure(lambda0,scm_vector2(n,m));
}

scm lambda2(scm* env, scm z, scm s) {
  return scm_invoke_closure2(s,scm_invoke_closure2(s,scm_invoke_closure2(s,z)));
}

scm lambda3(scm* env, scm z, scm s) {
  return scm_invoke_closure2(s,scm_invoke_closure2(s,scm_invoke_closure2(s,scm_invoke_closure2(s,scm_invoke_closure2(s,z)))));
}

scm lambda4(scm* env, scm x, scm y) {
  return x;
}

scm lambda5(scm* env, scm s) {
  return scm_invoke_closure3(scm_make_closure(lambda4,scm_vector0()),s,scm_invoke_closure2(env[0],s));
}

void main() {
  scm_invoke_closure3(scm_invoke_closure3(scm_make_closure(lambda1,scm_vector0()),scm_make_closure(lambda2,scm_vector0()),scm_make_closure(lambda3,scm_vector0())),scm_string("HELLO WORLD!!!"),scm_make_closure(lambda5,scm_vector1(scm_make_closure(scm_print,scm_vector0()))));
}
