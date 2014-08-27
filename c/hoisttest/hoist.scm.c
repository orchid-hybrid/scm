#include "scm.h"

scm* __print;
scm* __error;
scm* __newline;
scm* __put_string;
scm* __string_append;
scm* __number_to_string;
scm* __char_to_string;
scm* __symbol_to_string;
scm* __string_to_char;
scm* __string_to_symbol;
scm* __string_to_number;
scm* __cons;
scm* __car;
scm* __cdr;
scm* __set_car;
scm* __set_cdr;
scm* __boolean;
scm* __eq_question;
scm* __number_question;
scm* __boolean_question;
scm* __char_question;
scm* __string_question;
scm* __symbol_question;
scm* __vector_question;
scm* __null_question;
scm* __pair_question;
scm* __procedure_question;
scm* __add;
scm* __sub;
scm* __mul;
scm* __div;
scm* __num_eq;
scm* __num_lt;
scm* __num_lte;
scm* __num_gt;
scm* __num_gte;
scm* equal_question;
scm* member;
scm* tostring;
scm* display;
scm* print;
scm* not;
scm* make_cell;
scm* set_cell_bang;
scm* cell_value;
scm* list__gtstring;
scm* length;
scm* list_question;
scm* append;
scm* foldl;
scm* foldr;
scm* map;
scm* for_each;
scm* caar;
scm* cadr;
scm* cdar;
scm* cddr;
scm* caaar;
scm* caadr;
scm* cadar;
scm* caddr;
scm* cdraar;
scm* cdadr;
scm* cddar;
scm* cdddr;
scm* caaaar;
scm* caaadr;
scm* caadar;
scm* caaddr;
scm* cadaar;
scm* cadadr;
scm* caddar;
scm* cadddr;
scm* cdaaar;
scm* cdaadr;
scm* cdadar;
scm* cdaddr;
scm* cddaar;
scm* cddadr;
scm* cdddar;
scm* cddddr;
scm* y_combinator_1;
scm* y_combinator_2;
scm* y_combinator_3;
scm* y_combinator_4;
scm* y_combinator_5;
scm* y_combinator_6;
scm* all;
scm* any;
scm* fold;
scm* list_index_star;
scm* list_index;
scm* set_remove_element;
scm* set_remove;
scm* set_intersect;
scm* filter;
scm* set_union;
scm* set_union_star;
scm* variable_form_question;
scm* lambda_form_question;
scm* lambda_star_form_question;
scm* application_form_question;
scm* traverse;
scm* make_cell;
scm* set_cell_bang;
scm* cell_value;
scm* make_collector;
scm* member;
scm* symbol_add;
scm* add_all_symbols;
scm* generate_symbol;
scm* hoist;
scm* test_hoist;
scm* moo;
scm* symbol_table;


scm* lambda0(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda1(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda2(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda0,scm_vector0()),scm_make_closure(lambda1,scm_vector0()));
}

scm* lambda3(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda4(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda5(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda6(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda7(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda5,scm_vector0()),scm_make_closure(lambda6,scm_vector0()));
}

scm* lambda8(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda9(scm** env) {
  return 
scm_invoke_closure3(env[0],env[1],env[2]);
}

scm* lambda10(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda11(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda12(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda10,scm_vector0()),scm_make_closure(lambda11,scm_vector0()));
}

scm* lambda13(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda14(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda15(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda16(scm** env) {
  return 
scm_invoke_closure4(env[0],env[1],scm_make_closure(lambda14,scm_vector0()),scm_make_closure(lambda15,scm_vector0()));
}

scm* lambda17(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda18(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda19(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda20(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda21(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda19,scm_vector0()),scm_make_closure(lambda20,scm_vector0()));
}

scm* lambda22(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda23(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda24(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda25(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda21,scm_vector3(env[0],env[1],env[3])),scm_make_closure(lambda22,scm_vector0())),scm_make_closure(lambda23,scm_vector0()),scm_make_closure(lambda24,scm_vector0()));
}

scm* lambda26(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure4(env[0],env[1],scm_make_closure(lambda16,scm_vector2(env[0],env[2])),scm_make_closure(lambda17,scm_vector0())),scm_make_closure(lambda18,scm_vector0()),scm_make_closure(lambda25,scm_vector4(env[0],env[3],env[1],env[2])));
}

scm* lambda27(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda28(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda29(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda27,scm_vector0()),scm_make_closure(lambda28,scm_vector0()));
}

scm* lambda30(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda31(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda32(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda33(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda34(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda32,scm_vector0()),scm_make_closure(lambda33,scm_vector0()));
}

scm* lambda35(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda36(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda37(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda38(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda34,scm_vector3(env[0],env[1],env[3])),scm_make_closure(lambda35,scm_vector0())),scm_make_closure(lambda36,scm_vector0()),scm_make_closure(lambda37,scm_vector0()));
}

scm* lambda39(scm** env) {
  return 
scm_invoke_closure3(env[0],env[1],env[2]);
}

scm* lambda40(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda41(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda42(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda40,scm_vector0()),scm_make_closure(lambda41,scm_vector0()));
}

scm* lambda43(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda44(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda45(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda46(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda47(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda45,scm_vector0()),scm_make_closure(lambda46,scm_vector0()));
}

scm* lambda48(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda49(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda50(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda51(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],scm_invoke_closure2(env[2],env[3]),scm_invoke_closure2(env[2],env[4])),scm_make_closure(lambda49,scm_vector0()),scm_make_closure(lambda50,scm_vector0()));
}

scm* lambda52(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda53(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],scm_invoke_closure2(env[2],env[3]),scm_invoke_closure2(env[2],env[4])),scm_make_closure(lambda51,scm_vector5(env[0],env[1],env[5],env[3],env[4])),scm_make_closure(lambda52,scm_vector0()));
}

scm* lambda54(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda55(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_null });
}

scm* lambda56(scm** env) {
  return 
scm_invoke_closure4(env[0],scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 }),scm_make_closure(lambda54,scm_vector0()),scm_make_closure(lambda55,scm_vector0()));
}

scm* lambda57(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda47,scm_vector3(env[0],env[1],env[3])),scm_make_closure(lambda48,scm_vector0())),scm_make_closure(lambda53,scm_vector6(env[0],env[4],env[5],env[2],env[3],env[6])),scm_make_closure(lambda56,scm_vector1(env[0])));
}

scm* lambda58(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda42,scm_vector3(env[0],env[1],env[3])),scm_make_closure(lambda43,scm_vector0())),scm_make_closure(lambda44,scm_vector0()),scm_make_closure(lambda57,scm_vector7(env[0],env[4],env[2],env[3],env[5],env[6],env[7])));
}

scm* lambda59(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure4(env[0],scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda29,scm_vector3(env[0],env[1],env[3])),scm_make_closure(lambda30,scm_vector0())),scm_make_closure(lambda31,scm_vector0()),scm_make_closure(lambda38,scm_vector4(env[0],env[4],env[2],env[3]))),scm_make_closure(lambda39,scm_vector3(env[5],env[2],env[3])),scm_make_closure(lambda58,scm_vector8(env[0],env[6],env[2],env[3],env[7],env[8],env[9],env[10])));
}

scm* lambda60(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda12,scm_vector3(env[0],env[1],env[3])),scm_make_closure(lambda13,scm_vector0())),scm_make_closure(lambda26,scm_vector4(env[0],env[2],env[3],env[4])),scm_make_closure(lambda59,scm_vector11(env[0],env[5],env[2],env[3],env[6],env[7],env[8],env[9],env[10],env[11],env[12])));
}

scm* lambda61(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda7,scm_vector3(env[0],env[1],env[3])),scm_make_closure(lambda8,scm_vector0())),scm_make_closure(lambda9,scm_vector3(env[4],env[2],env[3])),scm_make_closure(lambda60,scm_vector13(env[0],env[5],env[2],env[3],env[6],env[7],env[8],env[9],env[10],env[11],env[12],env[13],env[14])));
}

scm* lambda62(scm** env, scm* p, scm* q) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],p),scm_make_closure(lambda2,scm_vector3(env[0],env[1],q)),scm_make_closure(lambda3,scm_vector0())),scm_make_closure(lambda4,scm_vector0()),scm_make_closure(lambda61,scm_vector15(env[0],env[2],p,q,env[3],env[4],env[5],env[6],env[7],env[8],env[9],env[10],env[11],env[12],env[13])));
}

scm* lambda63(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda64(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda65(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda66(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda67(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],env[2],scm_invoke_closure2(env[3],env[4])),scm_make_closure(lambda65,scm_vector0()),scm_make_closure(lambda66,scm_vector0()));
}

scm* lambda68(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],env[2],scm_invoke_closure2(env[3],env[4])),scm_make_closure(lambda64,scm_vector0()),scm_make_closure(lambda67,scm_vector5(env[0],env[5],env[2],env[6],env[4])));
}

scm* lambda69(scm** env, scm* s, scm* l) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],l),scm_make_closure(lambda63,scm_vector0()),scm_make_closure(lambda68,scm_vector7(env[0],env[2],s,env[3],l,env[4],env[5])));
}

scm* lambda70(scm** env) {
  return 
env[0];
}

scm* lambda71(scm** env) {
  return 
scm_invoke_closure2(env[0],env[1]);
}

scm* lambda72(scm** env) {
  return 
scm_string("#t");
}

scm* lambda73(scm** env) {
  return 
scm_string("#f");
}

scm* lambda74(scm** env) {
  return 
scm_invoke_closure4(env[0],env[1],scm_make_closure(lambda72,scm_vector0()),scm_make_closure(lambda73,scm_vector0()));
}

scm* lambda75(scm** env) {
  return 
scm_string("#<procedure>");
}

scm* lambda76(scm** env) {
  return 
scm_invoke_closure2(env[0],env[1]);
}

scm* lambda77(scm** env) {
  return 
scm_invoke_closure2(env[0],env[1]);
}

scm* lambda78(scm** env) {
  return 
scm_string("()");
}

scm* lambda79(scm** env, scm* s) {
  return 
scm_invoke_closure3(env[0],scm_invoke_closure2(env[1],s),scm_string(" "));
}

scm* lambda80(scm** env) {
  return 
scm_invoke_closure4(env[0],env[1],scm_string("("),scm_invoke_closure3(env[2],scm_invoke_closure3(env[3],scm_make_closure(lambda79,scm_vector2(env[1],env[4])),env[5]),scm_invoke_closure3(env[6],scm_string(")"),scmalloc((scm){ .t = scm_type_null }))));
}

scm* lambda81(scm** env) {
  return 
scm_invoke_closure4(env[0],env[1],scm_string("("),scm_invoke_closure3(env[2],scm_invoke_closure2(env[3],scm_invoke_closure2(env[4],env[5])),scm_invoke_closure3(env[2],scm_string(" . "),scm_invoke_closure3(env[2],scm_invoke_closure2(env[3],scm_invoke_closure2(env[6],env[5])),scm_invoke_closure3(env[2],scm_string(")"),scmalloc((scm){ .t = scm_type_null }))))));
}

scm* lambda82(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_null });
}

scm* lambda83(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda81,scm_vector7(env[3],env[4],env[5],env[6],env[7],env[2],env[8])),scm_make_closure(lambda82,scm_vector0()));
}

scm* lambda84(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda80,scm_vector7(env[3],env[4],env[5],env[6],env[7],env[2],env[8])),scm_make_closure(lambda83,scm_vector9(env[0],env[9],env[2],env[3],env[4],env[8],env[7],env[10],env[11])));
}

scm* lambda85(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda78,scm_vector0()),scm_make_closure(lambda84,scm_vector12(env[0],env[3],env[2],env[4],env[5],env[6],env[7],env[8],env[9],env[10],env[11],env[12])));
}

scm* lambda86(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda77,scm_vector2(env[3],env[2])),scm_make_closure(lambda85,scm_vector13(env[0],env[4],env[2],env[5],env[6],env[7],env[8],env[9],env[10],env[11],env[12],env[13],env[14])));
}

scm* lambda87(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda76,scm_vector2(env[3],env[2])),scm_make_closure(lambda86,scm_vector15(env[0],env[4],env[2],env[5],env[6],env[7],env[8],env[9],env[10],env[11],env[12],env[13],env[14],env[15],env[16])));
}

scm* lambda88(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda75,scm_vector0()),scm_make_closure(lambda87,scm_vector17(env[0],env[3],env[2],env[4],env[5],env[6],env[7],env[8],env[9],env[10],env[11],env[12],env[13],env[14],env[15],env[16],env[17])));
}

scm* lambda89(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda74,scm_vector2(env[0],env[2])),scm_make_closure(lambda88,scm_vector18(env[0],env[3],env[2],env[4],env[5],env[6],env[7],env[8],env[9],env[10],env[11],env[12],env[13],env[14],env[15],env[16],env[17],env[18])));
}

scm* lambda90(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda71,scm_vector2(env[3],env[2])),scm_make_closure(lambda89,scm_vector19(env[0],env[4],env[2],env[5],env[6],env[7],env[8],env[9],env[10],env[11],env[12],env[13],env[14],env[15],env[16],env[17],env[18],env[19],env[20])));
}

scm* lambda91(scm** env, scm* obj) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],obj),scm_make_closure(lambda70,scm_vector1(obj)),scm_make_closure(lambda90,scm_vector21(env[0],env[2],obj,env[3],env[4],env[5],env[6],env[7],env[8],env[9],env[10],env[11],env[12],env[13],env[14],env[15],env[16],env[17],env[18],env[19],env[20])));
}

scm* lambda92(scm** env, scm* obj) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],obj));
}

scm* lambda93(scm** env) {
  return 
scm_invoke_closure1(env[0]);
}

scm* lambda94(scm** env, scm* obj) {
  return 
scm_invoke_closure2(scm_make_closure(lambda93,scm_vector1(env[0])),scm_invoke_closure2(env[1],obj));
}

scm* lambda95(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda96(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda97(scm** env, scm* b) {
  return 
scm_invoke_closure4(env[0],b,scm_make_closure(lambda95,scm_vector0()),scm_make_closure(lambda96,scm_vector0()));
}

scm* lambda98(scm** env, scm* v) {
  return 
scm_invoke_closure3(env[0],scm_make_symbol("cell"),v);
}

scm* lambda99(scm** env, scm* cell, scm* value) {
  return 
scm_invoke_closure3(env[0],cell,value);
}

scm* lambda100(scm** env, scm* cell) {
  return 
scm_invoke_closure2(env[0],cell);
}

scm* lambda101(scm** env) {
  return 
env[0];
}

scm* lambda102(scm** env, scm* c, scm* m) {
  return 
scm_invoke_closure3(env[0],scm_invoke_closure2(env[1],c),m);
}

scm* lambda103(scm** env, scm* lst) {
  return 
scm_invoke_closure2(scm_make_closure(lambda101,scm_vector1(lst)),scm_invoke_closure3(env[0],scm_make_closure(lambda102,scm_vector2(env[1],env[2])),scm_string("")));
}

scm* lambda104(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_number, .v.n = 0 });
}

scm* lambda105(scm** env) {
  return 
scm_invoke_closure3(env[0],scmalloc((scm){ .t = scm_type_number, .v.n = 1 }),scm_invoke_closure2(env[1],scm_invoke_closure2(env[2],env[3])));
}

scm* lambda106(scm** env, scm* lst) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],lst),scm_make_closure(lambda104,scm_vector0()),scm_make_closure(lambda105,scm_vector4(env[2],env[3],env[4],lst)));
}

scm* lambda107(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda108(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda109(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda110(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[2],env[3])),scm_make_closure(lambda108,scm_vector0()),scm_make_closure(lambda109,scm_vector0()));
}

scm* lambda111(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda112(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda113(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda114(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda110,scm_vector4(env[0],env[3],env[4],env[2])),scm_make_closure(lambda111,scm_vector0())),scm_make_closure(lambda112,scm_vector0()),scm_make_closure(lambda113,scm_vector0()));
}

scm* lambda115(scm** env, scm* lst) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],lst),scm_make_closure(lambda107,scm_vector0()),scm_make_closure(lambda114,scm_vector5(env[0],env[2],lst,env[3],env[4])));
}

scm* lambda116(scm** env) {
  return 
env[0];
}

scm* lambda117(scm** env) {
  return 
scm_invoke_closure3(env[0],scm_invoke_closure2(env[1],env[2]),scm_invoke_closure3(env[3],scm_invoke_closure2(env[4],env[2]),env[5]));
}

scm* lambda118(scm** env, scm* l, scm* m) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],l),scm_make_closure(lambda116,scm_vector1(m)),scm_make_closure(lambda117,scm_vector6(env[2],env[3],l,env[4],env[5],m)));
}

scm* lambda119(scm** env) {
  return 
env[0];
}

scm* lambda120(scm** env) {
  return 
scm_invoke_closure4(env[0],env[1],scm_invoke_closure3(env[1],env[2],scm_invoke_closure2(env[3],env[4])),scm_invoke_closure2(env[5],env[4]));
}

scm* lambda121(scm** env, scm* fn, scm* init, scm* lst) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],lst),scm_make_closure(lambda119,scm_vector1(init)),scm_make_closure(lambda120,scm_vector6(env[2],fn,init,env[3],lst,env[4])));
}

scm* lambda122(scm** env) {
  return 
env[0];
}

scm* lambda123(scm** env) {
  return 
scm_invoke_closure3(env[0],scm_invoke_closure2(env[1],env[2]),scm_invoke_closure4(env[3],env[0],env[4],scm_invoke_closure2(env[5],env[2])));
}

scm* lambda124(scm** env, scm* fn, scm* init, scm* lst) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],lst),scm_make_closure(lambda122,scm_vector1(init)),scm_make_closure(lambda123,scm_vector6(fn,env[2],lst,env[3],init,env[4])));
}

scm* lambda125(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_null });
}

scm* lambda126(scm** env) {
  return 
scm_invoke_closure3(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[2],env[3])),scm_invoke_closure3(env[4],env[1],scm_invoke_closure2(env[5],env[3])));
}

scm* lambda127(scm** env, scm* fn, scm* lst) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],lst),scm_make_closure(lambda125,scm_vector0()),scm_make_closure(lambda126,scm_vector6(env[2],fn,env[3],lst,env[4],env[5])));
}

scm* lambda128(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_null });
}

scm* lambda129(scm** env) {
  return 
scm_invoke_closure3(env[0],env[1],scm_invoke_closure2(env[2],env[3]));
}

scm* lambda130(scm** env) {
  return 
scm_invoke_closure2(scm_make_closure(lambda129,scm_vector4(env[0],env[1],env[2],env[3])),scm_invoke_closure2(env[1],scm_invoke_closure2(env[4],env[3])));
}

scm* lambda131(scm** env, scm* fn, scm* lst) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],lst),scm_make_closure(lambda128,scm_vector0()),scm_make_closure(lambda130,scm_vector5(env[2],fn,env[3],lst,env[4])));
}

scm* lambda132(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],x));
}

scm* lambda133(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],x));
}

scm* lambda134(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],x));
}

scm* lambda135(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],x));
}

scm* lambda136(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],x)));
}

scm* lambda137(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],x)));
}

scm* lambda138(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[0],x)));
}

scm* lambda139(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[1],x)));
}

scm* lambda140(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[1],x)));
}

scm* lambda141(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[0],x)));
}

scm* lambda142(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],x)));
}

scm* lambda143(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],x)));
}

scm* lambda144(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],x))));
}

scm* lambda145(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],x))));
}

scm* lambda146(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[0],x))));
}

scm* lambda147(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[1],x))));
}

scm* lambda148(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],x))));
}

scm* lambda149(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],x))));
}

scm* lambda150(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[1],scm_invoke_closure2(env[0],x))));
}

scm* lambda151(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[1],scm_invoke_closure2(env[1],x))));
}

scm* lambda152(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[1],scm_invoke_closure2(env[1],x))));
}

scm* lambda153(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[1],scm_invoke_closure2(env[0],x))));
}

scm* lambda154(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],x))));
}

scm* lambda155(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],x))));
}

scm* lambda156(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[1],x))));
}

scm* lambda157(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[0],x))));
}

scm* lambda158(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],x))));
}

scm* lambda159(scm** env, scm* x) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],scm_invoke_closure2(env[0],x))));
}

scm* lambda160(scm** env, scm* x) {
  return 
scm_invoke_closure2(x,x);
}

scm* lambda161(scm** env, scm* arg) {
  return 
scm_invoke_closure2(scm_invoke_closure2(env[0],env[0]),arg);
}

scm* lambda162(scm** env, scm* g) {
  return 
scm_invoke_closure2(env[0],scm_make_closure(lambda161,scm_vector1(g)));
}

scm* lambda163(scm** env, scm* f) {
  return 
scm_invoke_closure2(scm_make_closure(lambda160,scm_vector0()),scm_make_closure(lambda162,scm_vector1(f)));
}

scm* lambda164(scm** env, scm* x) {
  return 
scm_invoke_closure2(x,x);
}

scm* lambda165(scm** env, scm* arg1, scm* arg2) {
  return 
scm_invoke_closure3(scm_invoke_closure2(env[0],env[0]),arg1,arg2);
}

scm* lambda166(scm** env, scm* g) {
  return 
scm_invoke_closure2(env[0],scm_make_closure(lambda165,scm_vector1(g)));
}

scm* lambda167(scm** env, scm* f) {
  return 
scm_invoke_closure2(scm_make_closure(lambda164,scm_vector0()),scm_make_closure(lambda166,scm_vector1(f)));
}

scm* lambda168(scm** env, scm* x) {
  return 
scm_invoke_closure2(x,x);
}

scm* lambda169(scm** env, scm* arg1, scm* arg2, scm* arg3) {
  return 
scm_invoke_closure4(scm_invoke_closure2(env[0],env[0]),arg1,arg2,arg3);
}

scm* lambda170(scm** env, scm* g) {
  return 
scm_invoke_closure2(env[0],scm_make_closure(lambda169,scm_vector1(g)));
}

scm* lambda171(scm** env, scm* f) {
  return 
scm_invoke_closure2(scm_make_closure(lambda168,scm_vector0()),scm_make_closure(lambda170,scm_vector1(f)));
}

scm* lambda172(scm** env, scm* x) {
  return 
scm_invoke_closure2(x,x);
}

scm* lambda173(scm** env, scm* arg1, scm* arg2, scm* arg3, scm* arg4) {
  return 
scm_invoke_closure5(scm_invoke_closure2(env[0],env[0]),arg1,arg2,arg3,arg4);
}

scm* lambda174(scm** env, scm* g) {
  return 
scm_invoke_closure2(env[0],scm_make_closure(lambda173,scm_vector1(g)));
}

scm* lambda175(scm** env, scm* f) {
  return 
scm_invoke_closure2(scm_make_closure(lambda172,scm_vector0()),scm_make_closure(lambda174,scm_vector1(f)));
}

scm* lambda176(scm** env, scm* x) {
  return 
scm_invoke_closure2(x,x);
}

scm* lambda177(scm** env, scm* arg1, scm* arg2, scm* arg3, scm* arg4, scm* arg5) {
  return 
scm_invoke_closure6(scm_invoke_closure2(env[0],env[0]),arg1,arg2,arg3,arg4,arg5);
}

scm* lambda178(scm** env, scm* g) {
  return 
scm_invoke_closure2(env[0],scm_make_closure(lambda177,scm_vector1(g)));
}

scm* lambda179(scm** env, scm* f) {
  return 
scm_invoke_closure2(scm_make_closure(lambda176,scm_vector0()),scm_make_closure(lambda178,scm_vector1(f)));
}

scm* lambda180(scm** env, scm* x) {
  return 
scm_invoke_closure2(x,x);
}

scm* lambda181(scm** env, scm* arg1, scm* arg2, scm* arg3, scm* arg4, scm* arg5, scm* arg6) {
  return 
scm_invoke_closure7(scm_invoke_closure2(env[0],env[0]),arg1,arg2,arg3,arg4,arg5,arg6);
}

scm* lambda182(scm** env, scm* g) {
  return 
scm_invoke_closure2(env[0],scm_make_closure(lambda181,scm_vector1(g)));
}

scm* lambda183(scm** env, scm* f) {
  return 
scm_invoke_closure2(scm_make_closure(lambda180,scm_vector0()),scm_make_closure(lambda182,scm_vector1(f)));
}

scm* lambda184(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda185(scm** env) {
  return 
scm_invoke_closure3(env[0],env[1],scm_invoke_closure2(env[2],env[3]));
}

scm* lambda186(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda187(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[2],env[3])),scm_make_closure(lambda185,scm_vector4(env[4],env[1],env[5],env[3])),scm_make_closure(lambda186,scm_vector0()));
}

scm* lambda188(scm** env, scm* p, scm* l) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],l),scm_make_closure(lambda184,scm_vector0()),scm_make_closure(lambda187,scm_vector6(env[0],p,env[2],l,env[3],env[4])));
}

scm* lambda189(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda190(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda191(scm** env) {
  return 
scm_invoke_closure3(env[0],env[1],scm_invoke_closure2(env[2],env[3]));
}

scm* lambda192(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[2],env[3])),scm_make_closure(lambda190,scm_vector0()),scm_make_closure(lambda191,scm_vector4(env[4],env[1],env[5],env[3])));
}

scm* lambda193(scm** env, scm* p, scm* l) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],l),scm_make_closure(lambda189,scm_vector0()),scm_make_closure(lambda192,scm_vector6(env[0],p,env[2],l,env[3],env[4])));
}

scm* lambda194(scm** env) {
  return 
env[0];
}

scm* lambda195(scm** env) {
  return 
scm_invoke_closure3(env[0],scm_invoke_closure2(env[1],env[2]),scm_invoke_closure4(env[3],env[0],env[4],scm_invoke_closure2(env[5],env[2])));
}

scm* lambda196(scm** env, scm* kons, scm* knil, scm* klist) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],klist),scm_make_closure(lambda194,scm_vector1(knil)),scm_make_closure(lambda195,scm_vector6(kons,env[2],klist,env[3],knil,env[4])));
}

scm* lambda197(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda198(scm** env) {
  return 
env[0];
}

scm* lambda199(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],env[2],scmalloc((scm){ .t = scm_type_number, .v.n = 1 })),env[3],scm_invoke_closure2(env[4],env[5]));
}

scm* lambda200(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],env[2],scm_invoke_closure2(env[3],env[4])),scm_make_closure(lambda198,scm_vector1(env[5])),scm_make_closure(lambda199,scm_vector6(env[6],env[7],env[5],env[2],env[8],env[4])));
}

scm* lambda201(scm** env, scm* i, scm* elt, scm* list) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],list),scm_make_closure(lambda197,scm_vector0()),scm_make_closure(lambda200,scm_vector9(env[0],env[2],elt,env[3],list,i,env[4],env[5],env[6])));
}

scm* lambda202(scm** env, scm* elt, scm* list) {
  return 
scm_invoke_closure4(env[0],scmalloc((scm){ .t = scm_type_number, .v.n = 0 }),elt,list);
}

scm* lambda203(scm** env) {
  return 
env[0];
}

scm* lambda204(scm** env) {
  return 
scm_invoke_closure3(env[0],scm_invoke_closure2(env[1],env[2]),env[3]);
}

scm* lambda205(scm** env) {
  return 
scm_invoke_closure3(env[0],scm_invoke_closure2(env[1],env[2]),scm_invoke_closure3(env[3],scm_invoke_closure2(env[4],env[2]),env[5]));
}

scm* lambda206(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],scm_invoke_closure2(env[2],env[3]),env[4]),scm_make_closure(lambda204,scm_vector4(env[5],env[6],env[3],env[4])),scm_make_closure(lambda205,scm_vector6(env[7],env[2],env[3],env[5],env[6],env[4])));
}

scm* lambda207(scm** env, scm* set, scm* element) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],set),scm_make_closure(lambda203,scm_vector1(set)),scm_make_closure(lambda206,scm_vector8(env[0],env[2],env[3],set,element,env[4],env[5],env[6])));
}

scm* lambda208(scm** env) {
  return 
env[0];
}

scm* lambda209(scm** env) {
  return 
scm_invoke_closure3(env[0],scm_invoke_closure3(env[1],env[2],scm_invoke_closure2(env[3],env[4])),scm_invoke_closure2(env[5],env[4]));
}

scm* lambda210(scm** env, scm* set, scm* list) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],list),scm_make_closure(lambda208,scm_vector1(set)),scm_make_closure(lambda209,scm_vector6(env[2],env[3],set,env[4],list,env[5])));
}

scm* lambda211(scm** env) {
  return 
env[0];
}

scm* lambda212(scm** env) {
  return 
scm_invoke_closure3(env[0],scm_invoke_closure2(env[1],env[2]),scm_invoke_closure3(env[3],scm_invoke_closure2(env[4],env[2]),env[5]));
}

scm* lambda213(scm** env) {
  return 
scm_invoke_closure3(env[0],scm_invoke_closure2(env[1],env[2]),env[3]);
}

scm* lambda214(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],scm_invoke_closure2(env[2],env[3]),env[4]),scm_make_closure(lambda212,scm_vector6(env[5],env[2],env[3],env[6],env[7],env[4])),scm_make_closure(lambda213,scm_vector4(env[6],env[7],env[3],env[4])));
}

scm* lambda215(scm** env, scm* set_1, scm* set_2) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],set_1),scm_make_closure(lambda211,scm_vector1(set_1)),scm_make_closure(lambda214,scm_vector8(env[0],env[2],env[3],set_1,set_2,env[4],env[5],env[6])));
}

scm* lambda216(scm** env) {
  return 
env[0];
}

scm* lambda217(scm** env) {
  return 
scm_invoke_closure3(env[0],env[1],scm_invoke_closure2(env[2],env[3]));
}

scm* lambda218(scm** env) {
  return 
scm_invoke_closure3(env[0],scm_invoke_closure2(env[1],env[2]),scm_invoke_closure3(env[3],env[4],scm_invoke_closure2(env[5],env[2])));
}

scm* lambda219(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],scm_invoke_closure2(env[2],env[3]),env[4]),scm_make_closure(lambda217,scm_vector4(env[5],env[4],env[6],env[3])),scm_make_closure(lambda218,scm_vector6(env[7],env[2],env[3],env[5],env[4],env[6])));
}

scm* lambda220(scm** env, scm* set_1, scm* set_2) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],set_2),scm_make_closure(lambda216,scm_vector1(set_2)),scm_make_closure(lambda219,scm_vector8(env[0],env[2],env[3],set_2,set_1,env[4],env[5],env[6])));
}

scm* lambda221(scm** env, scm* set_1, scm* set_2) {
  return 
scm_invoke_closure3(env[0],set_1,scm_invoke_closure3(env[1],set_1,set_2));
}

scm* lambda222(scm** env) {
  return 
env[0];
}

scm* lambda223(scm** env) {
  return 
scm_invoke_closure3(env[0],scm_invoke_closure2(env[1],env[2]),scm_invoke_closure2(env[3],scm_invoke_closure2(env[4],env[2])));
}

scm* lambda224(scm** env, scm* sets) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],sets),scm_make_closure(lambda222,scm_vector1(sets)),scm_make_closure(lambda223,scm_vector5(env[2],env[3],sets,env[4],env[5])));
}

scm* lambda225(scm** env, scm* t) {
  return 
scm_invoke_closure2(env[0],t);
}

scm* lambda226(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda227(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda228(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],env[2],scm_invoke_closure2(env[3],env[4])),scm_make_closure(lambda226,scm_vector0()),scm_make_closure(lambda227,scm_vector0()));
}

scm* lambda229(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda230(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[2],env[3])),scm_make_closure(lambda228,scm_vector5(env[0],env[4],env[5],env[2],env[3])),scm_make_closure(lambda229,scm_vector0()));
}

scm* lambda231(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda232(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],scm_make_symbol("lambda"),scm_invoke_closure2(env[2],env[3])),scm_make_closure(lambda230,scm_vector6(env[0],env[4],env[5],env[3],env[6],env[7])),scm_make_closure(lambda231,scm_vector0()));
}

scm* lambda233(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda234(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],scmalloc((scm){ .t = scm_type_number, .v.n = 3 }),scm_invoke_closure2(env[2],env[3])),scm_make_closure(lambda232,scm_vector8(env[0],env[4],env[5],env[3],env[6],env[7],env[8],env[9])),scm_make_closure(lambda233,scm_vector0()));
}

scm* lambda235(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda236(scm** env, scm* t) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],t),scm_make_closure(lambda234,scm_vector10(env[0],env[2],env[3],t,env[4],env[5],env[1],env[6],env[7],env[8])),scm_make_closure(lambda235,scm_vector0()));
}

scm* lambda237(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda238(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda239(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],env[2],scm_invoke_closure2(env[3],env[4])),scm_make_closure(lambda237,scm_vector0()),scm_make_closure(lambda238,scm_vector0()));
}

scm* lambda240(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda241(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],env[2],scm_invoke_closure2(env[3],env[4])),scm_make_closure(lambda239,scm_vector5(env[0],env[1],env[2],env[5],env[4])),scm_make_closure(lambda240,scm_vector0()));
}

scm* lambda242(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda243(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[2],env[3])),scm_make_closure(lambda241,scm_vector6(env[0],env[4],env[5],env[2],env[3],env[6])),scm_make_closure(lambda242,scm_vector0()));
}

scm* lambda244(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda245(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],scm_make_symbol("lambda*"),scm_invoke_closure2(env[2],env[3])),scm_make_closure(lambda243,scm_vector7(env[0],env[4],env[5],env[3],env[6],env[7],env[8])),scm_make_closure(lambda244,scm_vector0()));
}

scm* lambda246(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda247(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],scmalloc((scm){ .t = scm_type_number, .v.n = 4 }),scm_invoke_closure2(env[2],env[3])),scm_make_closure(lambda245,scm_vector9(env[0],env[4],env[5],env[3],env[6],env[7],env[8],env[9],env[10])),scm_make_closure(lambda246,scm_vector0()));
}

scm* lambda248(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda249(scm** env, scm* t) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],t),scm_make_closure(lambda247,scm_vector11(env[0],env[2],env[3],t,env[4],env[5],env[1],env[6],env[7],env[8],env[9])),scm_make_closure(lambda248,scm_vector0()));
}

scm* lambda250(scm** env, scm* t) {
  return 
scm_invoke_closure2(env[0],t);
}

scm* lambda251(scm** env) {
  return 
scm_invoke_closure2(env[0],env[1]);
}

scm* lambda252(scm** env) {
  return 
scm_invoke_closure2(env[0],env[1]);
}

scm* lambda253(scm** env) {
  return 
scm_invoke_closure2(env[0],env[1]);
}

scm* lambda254(scm** env) {
  return 
scm_invoke_closure2(env[0],env[1]);
}

scm* lambda255(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda256(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda257(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],scm_invoke_closure2(env[2],env[3]),scm_make_symbol("quote")),scm_make_closure(lambda255,scm_vector0()),scm_make_closure(lambda256,scm_vector0()));
}

scm* lambda258(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda259(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],scm_invoke_closure2(env[2],env[3]),scmalloc((scm){ .t = scm_type_number, .v.n = 2 })),scm_make_closure(lambda257,scm_vector4(env[0],env[4],env[5],env[3])),scm_make_closure(lambda258,scm_vector0()));
}

scm* lambda260(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda261(scm** env) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],env[2]));
}

scm* lambda262(scm** env) {
  return 
scm_invoke_closure2(env[0],env[1]);
}

scm* lambda263(scm** env) {
  return 
scm_invoke_closure3(env[0],scm_invoke_closure2(env[1],env[2]),scm_invoke_closure2(env[3],env[2]));
}

scm* lambda264(scm** env) {
  return 
scm_invoke_closure2(env[0],env[1]);
}

scm* lambda265(scm** env) {
  return 
scm_invoke_closure2(env[0],scm_string("traverse"));
}

scm* lambda266(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda264,scm_vector2(env[3],env[2])),scm_make_closure(lambda265,scm_vector1(env[4])));
}

scm* lambda267(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda263,scm_vector4(env[3],env[4],env[2],env[5])),scm_make_closure(lambda266,scm_vector5(env[0],env[6],env[2],env[7],env[8])));
}

scm* lambda268(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda262,scm_vector2(env[3],env[2])),scm_make_closure(lambda267,scm_vector9(env[0],env[4],env[2],env[5],env[6],env[7],env[8],env[9],env[10])));
}

scm* lambda269(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda259,scm_vector6(env[0],env[3],env[4],env[2],env[5],env[6])),scm_make_closure(lambda260,scm_vector0())),scm_make_closure(lambda261,scm_vector3(env[7],env[8],env[2])),scm_make_closure(lambda268,scm_vector11(env[0],env[9],env[2],env[10],env[11],env[12],env[8],env[13],env[14],env[15],env[16])));
}

scm* lambda270(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda254,scm_vector2(env[3],env[2])),scm_make_closure(lambda269,scm_vector17(env[0],env[4],env[2],env[5],env[6],env[7],env[8],env[9],env[10],env[11],env[12],env[13],env[14],env[15],env[16],env[17],env[18])));
}

scm* lambda271(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda253,scm_vector2(env[3],env[2])),scm_make_closure(lambda270,scm_vector19(env[0],env[4],env[2],env[5],env[6],env[7],env[8],env[9],env[10],env[11],env[12],env[13],env[14],env[15],env[16],env[17],env[18],env[19],env[20])));
}

scm* lambda272(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda252,scm_vector2(env[3],env[2])),scm_make_closure(lambda271,scm_vector21(env[0],env[4],env[2],env[5],env[6],env[7],env[8],env[9],env[10],env[11],env[12],env[13],env[14],env[15],env[16],env[17],env[18],env[19],env[20],env[21],env[22])));
}

scm* lambda273(scm** env, scm* t) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],t),scm_make_closure(lambda251,scm_vector2(env[2],t)),scm_make_closure(lambda272,scm_vector23(env[0],env[3],t,env[4],env[5],env[6],env[7],env[8],env[9],env[10],env[11],env[12],env[13],env[14],env[15],env[16],env[17],env[18],env[19],env[20],env[21],env[22],env[23])));
}

scm* lambda274(scm** env, scm* string_case, scm* char_case, scm* number_case, scm* boolean_case, scm* quote_case, scm* variable_case, scm* lambda_case, scm* application_case) {
  return 
scm_make_closure(lambda273,scm_vector24(env[0],env[1],string_case,env[2],char_case,env[3],number_case,env[4],boolean_case,env[5],env[6],env[7],env[8],env[9],quote_case,env[10],env[11],variable_case,env[12],lambda_case,env[13],env[14],application_case,env[15]));
}

scm* lambda275(scm** env, scm* v) {
  return 
scm_invoke_closure3(env[0],scm_make_symbol("cell"),v);
}

scm* lambda276(scm** env, scm* cell, scm* value) {
  return 
scm_invoke_closure3(env[0],cell,value);
}

scm* lambda277(scm** env, scm* cell) {
  return 
scm_invoke_closure2(env[0],cell);
}

scm* lambda278(scm** env) {
  return 
scm_invoke_closure2(env[0],env[1]);
}

scm* lambda279(scm** env) {
  return 
scm_invoke_closure3(env[0],env[1],scm_invoke_closure2(env[2],env[3]));
}

scm* lambda280(scm** env) {
  return 
scm_invoke_closure2(scm_make_closure(lambda279,scm_vector4(env[0],env[1],env[2],env[3])),scm_invoke_closure3(env[0],env[3],scm_invoke_closure3(env[4],env[5],scmalloc((scm){ .t = scm_type_null }))));
}

scm* lambda281(scm** env) {
  return 
scm_invoke_closure3(env[0],env[1],scm_invoke_closure2(env[2],scm_invoke_closure2(env[3],env[1])));
}

scm* lambda282(scm** env) {
  return 
scm_invoke_closure2(scm_make_closure(lambda281,scm_vector4(env[0],env[1],env[2],env[3])),scm_invoke_closure3(env[4],scm_invoke_closure2(env[3],env[1]),scm_invoke_closure3(env[5],env[6],scmalloc((scm){ .t = scm_type_null }))));
}

scm* lambda283(scm** env, scm* value) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],scm_invoke_closure2(env[2],env[3])),scm_make_closure(lambda280,scm_vector6(env[4],env[3],env[2],env[5],env[6],value)),scm_make_closure(lambda282,scm_vector7(env[4],env[3],env[7],env[2],env[8],env[6],value)));
}

scm* lambda284(scm** env, scm* list, scm* last) {
  return 
scm_invoke_closure3(env[0],scm_make_closure(lambda278,scm_vector2(env[1],list)),scm_make_closure(lambda283,scm_vector9(env[2],env[3],env[1],last,env[4],list,env[0],env[5],env[6])));
}

scm* lambda285(scm** env) {
  return 
scm_invoke_closure3(scm_make_closure(lambda284,scm_vector7(env[0],env[1],env[2],env[3],env[4],env[5],env[6])),scm_invoke_closure2(env[7],scmalloc((scm){ .t = scm_type_null })),scm_invoke_closure2(env[7],scmalloc((scm){ .t = scm_type_null })));
}

scm* lambda286(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda287(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda288(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda289(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda290(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],env[2],scm_invoke_closure2(env[3],env[4])),scm_make_closure(lambda288,scm_vector0()),scm_make_closure(lambda289,scm_vector0()));
}

scm* lambda291(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],env[2],scm_invoke_closure2(env[3],env[4])),scm_make_closure(lambda287,scm_vector0()),scm_make_closure(lambda290,scm_vector5(env[0],env[5],env[2],env[6],env[4])));
}

scm* lambda292(scm** env, scm* s, scm* l) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],l),scm_make_closure(lambda286,scm_vector0()),scm_make_closure(lambda291,scm_vector7(env[0],env[2],s,env[3],l,env[4],env[5])));
}

scm* lambda293(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda294(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 1 });
}

scm* lambda295(scm** env) {
  return 
scm_invoke_closure2(scm_make_closure(lambda294,scm_vector0()),scm_invoke_closure3(env[0],env[1],scm_invoke_closure3(env[2],env[3],scm_invoke_closure2(env[4],env[1]))));
}

scm* lambda296(scm** env, scm* s) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure3(env[1],s,scm_invoke_closure2(env[2],env[3])),scm_make_closure(lambda293,scm_vector0()),scm_make_closure(lambda295,scm_vector5(env[4],env[3],env[5],s,env[2])));
}

scm* lambda297(scm** env) {
  return 
scm_invoke_closure2(env[0],env[1]);
}

scm* lambda298(scm** env) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure2(env[1],env[2]));
}

scm* lambda299(scm** env) {
  return 
scmalloc((scm){ .t = scm_type_boolean, .v.n = 0 });
}

scm* lambda300(scm** env) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],env[2]),scm_make_closure(lambda298,scm_vector3(env[3],env[4],env[2])),scm_make_closure(lambda299,scm_vector0()));
}

scm* lambda301(scm** env, scm* sexp) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],sexp),scm_make_closure(lambda297,scm_vector2(env[2],sexp)),scm_make_closure(lambda300,scm_vector5(env[0],env[3],sexp,env[4],env[5])));
}

scm* lambda302(scm** env) {
  return 
env[0];
}

scm* lambda303(scm** env) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure3(env[1],env[2],scmalloc((scm){ .t = scm_type_number, .v.n = 1 })));
}

scm* lambda304(scm** env, scm* s) {
  return 
scm_invoke_closure4(env[0],scm_invoke_closure2(env[1],s),scm_make_closure(lambda302,scm_vector1(s)),scm_make_closure(lambda303,scm_vector3(env[2],env[3],env[4])));
}

scm* lambda305(scm** env, scm* counter) {
  return 
scm_invoke_closure2(scm_make_closure(lambda304,scm_vector5(env[0],env[1],env[2],env[3],counter)),scm_invoke_closure2(env[4],scm_invoke_closure3(env[5],env[6],scm_invoke_closure2(env[7],counter))));
}

scm* lambda306(scm** env, scm* loop) {
  return 
scm_make_closure(lambda305,scm_vector8(env[0],env[1],loop,env[2],env[3],env[4],env[5],env[6]));
}

scm* lambda307(scm** env, scm* prefix) {
  return 
scm_invoke_closure2(scm_invoke_closure2(env[0],scm_make_closure(lambda306,scm_vector7(env[1],env[2],env[3],env[4],env[5],prefix,env[6]))),scmalloc((scm){ .t = scm_type_number, .v.n = 0 }));
}

scm* lambda308(scm** env, scm* s) {
  return 
s;
}

scm* lambda309(scm** env, scm* c) {
  return 
c;
}

scm* lambda310(scm** env, scm* n) {
  return 
n;
}

scm* lambda311(scm** env, scm* b) {
  return 
b;
}

scm* lambda312(scm** env, scm* q) {
  return 
scm_invoke_closure3(env[0],scm_make_symbol("quote"),scm_invoke_closure3(env[0],q,scmalloc((scm){ .t = scm_type_null })));
}

scm* lambda313(scm** env, scm* v) {
  return 
v;
}

scm* lambda314(scm** env) {
  return 
env[0];
}

scm* lambda315(scm** env, scm* name) {
  return 
scm_invoke_closure2(scm_make_closure(lambda314,scm_vector1(name)),scm_invoke_closure2(env[0],scm_invoke_closure3(env[1],scm_make_symbol("define"),scm_invoke_closure3(env[1],name,scm_invoke_closure3(env[1],scm_invoke_closure3(env[1],scm_make_symbol("lambda"),scm_invoke_closure3(env[1],env[2],scm_invoke_closure3(env[1],env[3],scmalloc((scm){ .t = scm_type_null })))),scmalloc((scm){ .t = scm_type_null }))))));
}

scm* lambda316(scm** env, scm* hoisted_body) {
  return 
scm_invoke_closure2(scm_make_closure(lambda315,scm_vector4(env[0],env[1],env[2],hoisted_body)),scm_invoke_closure2(env[3],scm_string("lambda")));
}

scm* lambda317(scm** env, scm* args, scm* body) {
  return 
scm_invoke_closure2(scm_make_closure(lambda316,scm_vector4(env[0],env[1],args,env[2])),scm_invoke_closure2(scm_invoke_closure2(env[3],env[0]),body));
}

scm* lambda318(scm** env, scm* terms) {
  return 
scm_invoke_closure3(env[0],scm_invoke_closure2(env[1],env[2]),terms);
}

scm* lambda319(scm** env, scm* collect) {
  return 
scm_invoke_closure9(env[0],scm_make_closure(lambda308,scm_vector0()),scm_make_closure(lambda309,scm_vector0()),scm_make_closure(lambda310,scm_vector0()),scm_make_closure(lambda311,scm_vector0()),scm_make_closure(lambda312,scm_vector1(env[1])),scm_make_closure(lambda313,scm_vector0()),scm_make_closure(lambda317,scm_vector4(collect,env[1],env[2],env[3])),scm_make_closure(lambda318,scm_vector3(env[4],env[3],collect)));
}

scm* lambda320(scm** env) {
  return 
scm_invoke_closure2(env[0],env[1]);
}

scm* lambda321(scm** env) {
  return 
scm_invoke_closure2(scm_make_closure(lambda320,scm_vector2(env[0],env[1])),scm_invoke_closure1(env[2]));
}

scm* lambda322(scm** env, scm* result) {
  return 
scm_invoke_closure2(scm_make_closure(lambda321,scm_vector3(env[0],result,env[1])),scm_invoke_closure3(env[2],env[0],scm_invoke_closure1(scm_invoke_closure2(env[3],env[4]))));
}

scm* lambda323(scm** env, scm* collector) {
  return 
scm_invoke_closure2(scm_make_closure(lambda322,scm_vector5(env[0],env[1],env[2],env[3],collector)),scm_invoke_closure2(scm_invoke_closure2(env[4],scm_invoke_closure2(env[5],collector)),env[6]));
}

scm* lambda324(scm** env, scm* t) {
  return 
scm_invoke_closure2(scm_make_closure(lambda323,scm_vector7(env[0],env[1],env[2],env[3],env[4],env[5],t)),scm_invoke_closure1(env[6]));
}

scm* lambda325(scm** env) {
  return 
scm_invoke_closure2(env[0],scm_invoke_closure3(env[1],scm_make_symbol("f"),scm_invoke_closure3(env[1],scm_invoke_closure3(env[1],scm_make_symbol("lambda"),scm_invoke_closure3(env[1],scmalloc((scm){ .t = scm_type_null }),scm_invoke_closure3(env[1],scm_invoke_closure3(env[1],scm_make_symbol("f"),scm_invoke_closure3(env[1],scm_invoke_closure3(env[1],scm_make_symbol("lambda"),scm_invoke_closure3(env[1],scm_invoke_closure3(env[1],scm_make_symbol("x"),scmalloc((scm){ .t = scm_type_null })),scm_invoke_closure3(env[1],scm_make_symbol("x"),scmalloc((scm){ .t = scm_type_null })))),scmalloc((scm){ .t = scm_type_null }))),scmalloc((scm){ .t = scm_type_null })))),scm_invoke_closure3(env[1],scm_invoke_closure3(env[1],scm_make_symbol("lambda"),scm_invoke_closure3(env[1],scmalloc((scm){ .t = scm_type_null }),scm_invoke_closure3(env[1],scm_invoke_closure3(env[1],scm_make_symbol("g"),scm_invoke_closure3(env[1],scm_invoke_closure3(env[1],scm_make_symbol("lambda"),scm_invoke_closure3(env[1],scm_invoke_closure3(env[1],scm_make_symbol("y"),scmalloc((scm){ .t = scm_type_null })),scm_invoke_closure3(env[1],scm_invoke_closure3(env[1],scm_make_symbol("x"),scm_invoke_closure3(env[1],scm_make_symbol("y"),scmalloc((scm){ .t = scm_type_null }))),scmalloc((scm){ .t = scm_type_null })))),scmalloc((scm){ .t = scm_type_null }))),scmalloc((scm){ .t = scm_type_null })))),scm_invoke_closure3(env[1],scm_make_symbol("z"),scmalloc((scm){ .t = scm_type_null }))))));
}

void main() {
__print = scm_wrap_prim(scm_print);
__error = scm_wrap_prim(scm_error);
__newline = scm_wrap_prim(scm_newline);
__put_string = scm_wrap_prim(scm_put_string);
__string_append = scm_wrap_prim(scm_string_append);
__number_to_string = scm_wrap_prim(scm_number_to_string);
__char_to_string = scm_wrap_prim(scm_char_to_string);
__symbol_to_string = scm_wrap_prim(scm_symbol_to_string);
__string_to_char = scm_wrap_prim(scm_string_to_char);
__string_to_symbol = scm_wrap_prim(scm_string_to_symbol);
__string_to_number = scm_wrap_prim(scm_string_to_number);
__cons = scm_wrap_prim(scm_cons);
__car = scm_wrap_prim(scm_car);
__cdr = scm_wrap_prim(scm_cdr);
__set_car = scm_wrap_prim(scm_set_car);
__set_cdr = scm_wrap_prim(scm_set_cdr);
__boolean = scm_wrap_prim(scm_boolean);
__eq_question = scm_wrap_prim(scm_eq_question);
__number_question = scm_wrap_prim(scm_number_question);
__boolean_question = scm_wrap_prim(scm_boolean_question);
__char_question = scm_wrap_prim(scm_char_question);
__string_question = scm_wrap_prim(scm_string_question);
__symbol_question = scm_wrap_prim(scm_symbol_question);
__vector_question = scm_wrap_prim(scm_vector_question);
__null_question = scm_wrap_prim(scm_null_question);
__pair_question = scm_wrap_prim(scm_pair_question);
__procedure_question = scm_wrap_prim(scm_procedure_question);
__add = scm_wrap_prim(scm_add);
__sub = scm_wrap_prim(scm_sub);
__mul = scm_wrap_prim(scm_mul);
__div = scm_wrap_prim(scm_div);
__num_eq = scm_wrap_prim(scm_num_eq);
__num_lt = scm_wrap_prim(scm_num_lt);
__num_lte = scm_wrap_prim(scm_num_lte);
__num_gt = scm_wrap_prim(scm_num_gt);
__num_gte = scm_wrap_prim(scm_num_gte);
equal_question = scm_make_closure(lambda62,scm_vector14(__boolean,__procedure_question,__number_question,__num_eq,__boolean_question,not,__symbol_question,__string_question,__eq_question,__null_question,__pair_question,equal_question,__car,__cdr));
member = scm_make_closure(lambda69,scm_vector6(__boolean,__null_question,equal_question,__car,member,__cdr));
tostring = scm_make_closure(lambda91,scm_vector21(__boolean,__string_question,__char_question,__char_to_string,__boolean_question,__procedure_question,__number_question,__number_to_string,__symbol_question,__symbol_to_string,__null_question,list_question,foldl,__string_append,append,map,tostring,__cons,__pair_question,__car,__cdr));
display = scm_make_closure(lambda92,scm_vector2(__put_string,tostring));
print = scm_make_closure(lambda94,scm_vector2(__newline,display));
not = scm_make_closure(lambda97,scm_vector1(__boolean));
make_cell = scm_make_closure(lambda98,scm_vector1(__cons));
set_cell_bang = scm_make_closure(lambda99,scm_vector1(__set_cdr));
cell_value = scm_make_closure(lambda100,scm_vector1(__cdr));
list__gtstring = scm_make_closure(lambda103,scm_vector3(foldr,__string_append,__char_to_string));
length = scm_make_closure(lambda106,scm_vector5(__boolean,__null_question,__add,length,__cdr));
list_question = scm_make_closure(lambda115,scm_vector5(__boolean,__null_question,__pair_question,list_question,__cdr));
append = scm_make_closure(lambda118,scm_vector6(__boolean,__null_question,__cons,__car,append,__cdr));
foldl = scm_make_closure(lambda121,scm_vector5(__boolean,__null_question,foldl,__car,__cdr));
foldr = scm_make_closure(lambda124,scm_vector5(__boolean,__null_question,__car,foldr,__cdr));
map = scm_make_closure(lambda127,scm_vector6(__boolean,__null_question,__cons,__car,map,__cdr));
for_each = scm_make_closure(lambda131,scm_vector5(__boolean,__null_question,for_each,__cdr,__car));
caar = scm_make_closure(lambda132,scm_vector1(__car));
cadr = scm_make_closure(lambda133,scm_vector2(__car,__cdr));
cdar = scm_make_closure(lambda134,scm_vector2(__cdr,__car));
cddr = scm_make_closure(lambda135,scm_vector1(__cdr));
caaar = scm_make_closure(lambda136,scm_vector1(__car));
caadr = scm_make_closure(lambda137,scm_vector2(__car,__cdr));
cadar = scm_make_closure(lambda138,scm_vector2(__car,__cdr));
caddr = scm_make_closure(lambda139,scm_vector2(__car,__cdr));
cdraar = scm_make_closure(lambda140,scm_vector2(__cdr,__car));
cdadr = scm_make_closure(lambda141,scm_vector2(__cdr,__car));
cddar = scm_make_closure(lambda142,scm_vector2(__cdr,__car));
cdddr = scm_make_closure(lambda143,scm_vector1(__cdr));
caaaar = scm_make_closure(lambda144,scm_vector1(__car));
caaadr = scm_make_closure(lambda145,scm_vector2(__car,__cdr));
caadar = scm_make_closure(lambda146,scm_vector2(__car,__cdr));
caaddr = scm_make_closure(lambda147,scm_vector2(__car,__cdr));
cadaar = scm_make_closure(lambda148,scm_vector2(__car,__cdr));
cadadr = scm_make_closure(lambda149,scm_vector2(__car,__cdr));
caddar = scm_make_closure(lambda150,scm_vector2(__car,__cdr));
cadddr = scm_make_closure(lambda151,scm_vector2(__car,__cdr));
cdaaar = scm_make_closure(lambda152,scm_vector2(__cdr,__car));
cdaadr = scm_make_closure(lambda153,scm_vector2(__cdr,__car));
cdadar = scm_make_closure(lambda154,scm_vector2(__cdr,__car));
cdaddr = scm_make_closure(lambda155,scm_vector2(__cdr,__car));
cddaar = scm_make_closure(lambda156,scm_vector2(__cdr,__car));
cddadr = scm_make_closure(lambda157,scm_vector2(__cdr,__car));
cdddar = scm_make_closure(lambda158,scm_vector2(__cdr,__car));
cddddr = scm_make_closure(lambda159,scm_vector1(__cdr));
y_combinator_1 = scm_make_closure(lambda163,scm_vector0());
y_combinator_2 = scm_make_closure(lambda167,scm_vector0());
y_combinator_3 = scm_make_closure(lambda171,scm_vector0());
y_combinator_4 = scm_make_closure(lambda175,scm_vector0());
y_combinator_5 = scm_make_closure(lambda179,scm_vector0());
y_combinator_6 = scm_make_closure(lambda183,scm_vector0());
all = scm_make_closure(lambda188,scm_vector5(__boolean,__null_question,__car,all,__cdr));
any = scm_make_closure(lambda193,scm_vector5(__boolean,__null_question,__car,any,__cdr));
fold = scm_make_closure(lambda196,scm_vector5(__boolean,__null_question,__car,fold,__cdr));
list_index_star = scm_make_closure(lambda201,scm_vector7(__boolean,__null_question,equal_question,__car,list_index_star,__add,__cdr));
list_index = scm_make_closure(lambda202,scm_vector1(list_index_star));
set_remove_element = scm_make_closure(lambda207,scm_vector7(__boolean,__null_question,equal_question,__car,set_remove_element,__cdr,__cons));
set_remove = scm_make_closure(lambda210,scm_vector6(__boolean,__null_question,set_remove,set_remove_element,__car,__cdr));
set_intersect = scm_make_closure(lambda215,scm_vector7(__boolean,__null_question,member,__car,__cons,set_intersect,__cdr));
filter = scm_make_closure(lambda220,scm_vector7(__boolean,__null_question,member,__car,filter,__cdr,__cons));
set_union = scm_make_closure(lambda221,scm_vector2(append,filter));
set_union_star = scm_make_closure(lambda224,scm_vector6(__boolean,__null_question,set_union,__car,set_union_star,__cdr));
variable_form_question = scm_make_closure(lambda225,scm_vector1(__symbol_question));
lambda_form_question = scm_make_closure(lambda236,scm_vector9(__boolean,list_question,__num_eq,length,equal_question,__car,cadr,all,variable_form_question));
lambda_star_form_question = scm_make_closure(lambda249,scm_vector10(__boolean,list_question,__num_eq,length,equal_question,__car,cadr,all,variable_form_question,caddr));
application_form_question = scm_make_closure(lambda250,scm_vector1(list_question));
traverse = scm_make_closure(lambda274,scm_vector16(__boolean,__string_question,__char_question,__number_question,__boolean_question,list_question,__num_eq,length,equal_question,__car,cadr,variable_form_question,lambda_form_question,caddr,application_form_question,__error));
make_cell = scm_make_closure(lambda275,scm_vector1(__cons));
set_cell_bang = scm_make_closure(lambda276,scm_vector1(__set_cdr));
cell_value = scm_make_closure(lambda277,scm_vector1(__cdr));
make_collector = scm_make_closure(lambda285,scm_vector8(__cons,cell_value,__boolean,__null_question,set_cell_bang,__cdr,__set_cdr,make_cell));
member = scm_make_closure(lambda292,scm_vector6(__boolean,__null_question,equal_question,__car,member,__cdr));
symbol_add = scm_make_closure(lambda296,scm_vector6(__boolean,member,cell_value,symbol_table,set_cell_bang,__cons));
add_all_symbols = scm_make_closure(lambda301,scm_vector6(__boolean,__symbol_question,symbol_add,__pair_question,add_all_symbols,__car));
generate_symbol = scm_make_closure(lambda307,scm_vector7(y_combinator_1,__boolean,symbol_add,__add,__string_to_symbol,__string_append,__number_to_string));
hoist = scm_make_closure(lambda319,scm_vector5(traverse,__cons,generate_symbol,hoist,map));
test_hoist = scm_make_closure(lambda324,scm_vector7(display,__newline,for_each,__car,hoist,__cdr,make_collector));
moo = scm_make_closure(lambda325,scm_vector2(test_hoist,__cons));

symbol_table = scm_invoke_closure2(make_cell,scmalloc((scm){ .t = scm_type_null }));

equal_question->v.cons.cdr = scm_vector14(__boolean,__procedure_question,__number_question,__num_eq,__boolean_question,not,__symbol_question,__string_question,__eq_question,__null_question,__pair_question,equal_question,__car,__cdr);
member->v.cons.cdr = scm_vector6(__boolean,__null_question,equal_question,__car,member,__cdr);
tostring->v.cons.cdr = scm_vector21(__boolean,__string_question,__char_question,__char_to_string,__boolean_question,__procedure_question,__number_question,__number_to_string,__symbol_question,__symbol_to_string,__null_question,list_question,foldl,__string_append,append,map,tostring,__cons,__pair_question,__car,__cdr);
display->v.cons.cdr = scm_vector2(__put_string,tostring);
print->v.cons.cdr = scm_vector2(__newline,display);
not->v.cons.cdr = scm_vector1(__boolean);
make_cell->v.cons.cdr = scm_vector1(__cons);
set_cell_bang->v.cons.cdr = scm_vector1(__set_cdr);
cell_value->v.cons.cdr = scm_vector1(__cdr);
list__gtstring->v.cons.cdr = scm_vector3(foldr,__string_append,__char_to_string);
length->v.cons.cdr = scm_vector5(__boolean,__null_question,__add,length,__cdr);
list_question->v.cons.cdr = scm_vector5(__boolean,__null_question,__pair_question,list_question,__cdr);
append->v.cons.cdr = scm_vector6(__boolean,__null_question,__cons,__car,append,__cdr);
foldl->v.cons.cdr = scm_vector5(__boolean,__null_question,foldl,__car,__cdr);
foldr->v.cons.cdr = scm_vector5(__boolean,__null_question,__car,foldr,__cdr);
map->v.cons.cdr = scm_vector6(__boolean,__null_question,__cons,__car,map,__cdr);
for_each->v.cons.cdr = scm_vector5(__boolean,__null_question,for_each,__cdr,__car);
caar->v.cons.cdr = scm_vector1(__car);
cadr->v.cons.cdr = scm_vector2(__car,__cdr);
cdar->v.cons.cdr = scm_vector2(__cdr,__car);
cddr->v.cons.cdr = scm_vector1(__cdr);
caaar->v.cons.cdr = scm_vector1(__car);
caadr->v.cons.cdr = scm_vector2(__car,__cdr);
cadar->v.cons.cdr = scm_vector2(__car,__cdr);
caddr->v.cons.cdr = scm_vector2(__car,__cdr);
cdraar->v.cons.cdr = scm_vector2(__cdr,__car);
cdadr->v.cons.cdr = scm_vector2(__cdr,__car);
cddar->v.cons.cdr = scm_vector2(__cdr,__car);
cdddr->v.cons.cdr = scm_vector1(__cdr);
caaaar->v.cons.cdr = scm_vector1(__car);
caaadr->v.cons.cdr = scm_vector2(__car,__cdr);
caadar->v.cons.cdr = scm_vector2(__car,__cdr);
caaddr->v.cons.cdr = scm_vector2(__car,__cdr);
cadaar->v.cons.cdr = scm_vector2(__car,__cdr);
cadadr->v.cons.cdr = scm_vector2(__car,__cdr);
caddar->v.cons.cdr = scm_vector2(__car,__cdr);
cadddr->v.cons.cdr = scm_vector2(__car,__cdr);
cdaaar->v.cons.cdr = scm_vector2(__cdr,__car);
cdaadr->v.cons.cdr = scm_vector2(__cdr,__car);
cdadar->v.cons.cdr = scm_vector2(__cdr,__car);
cdaddr->v.cons.cdr = scm_vector2(__cdr,__car);
cddaar->v.cons.cdr = scm_vector2(__cdr,__car);
cddadr->v.cons.cdr = scm_vector2(__cdr,__car);
cdddar->v.cons.cdr = scm_vector2(__cdr,__car);
cddddr->v.cons.cdr = scm_vector1(__cdr);
y_combinator_1->v.cons.cdr = scm_vector0();
y_combinator_2->v.cons.cdr = scm_vector0();
y_combinator_3->v.cons.cdr = scm_vector0();
y_combinator_4->v.cons.cdr = scm_vector0();
y_combinator_5->v.cons.cdr = scm_vector0();
y_combinator_6->v.cons.cdr = scm_vector0();
all->v.cons.cdr = scm_vector5(__boolean,__null_question,__car,all,__cdr);
any->v.cons.cdr = scm_vector5(__boolean,__null_question,__car,any,__cdr);
fold->v.cons.cdr = scm_vector5(__boolean,__null_question,__car,fold,__cdr);
list_index_star->v.cons.cdr = scm_vector7(__boolean,__null_question,equal_question,__car,list_index_star,__add,__cdr);
list_index->v.cons.cdr = scm_vector1(list_index_star);
set_remove_element->v.cons.cdr = scm_vector7(__boolean,__null_question,equal_question,__car,set_remove_element,__cdr,__cons);
set_remove->v.cons.cdr = scm_vector6(__boolean,__null_question,set_remove,set_remove_element,__car,__cdr);
set_intersect->v.cons.cdr = scm_vector7(__boolean,__null_question,member,__car,__cons,set_intersect,__cdr);
filter->v.cons.cdr = scm_vector7(__boolean,__null_question,member,__car,filter,__cdr,__cons);
set_union->v.cons.cdr = scm_vector2(append,filter);
set_union_star->v.cons.cdr = scm_vector6(__boolean,__null_question,set_union,__car,set_union_star,__cdr);
variable_form_question->v.cons.cdr = scm_vector1(__symbol_question);
lambda_form_question->v.cons.cdr = scm_vector9(__boolean,list_question,__num_eq,length,equal_question,__car,cadr,all,variable_form_question);
lambda_star_form_question->v.cons.cdr = scm_vector10(__boolean,list_question,__num_eq,length,equal_question,__car,cadr,all,variable_form_question,caddr);
application_form_question->v.cons.cdr = scm_vector1(list_question);
traverse->v.cons.cdr = scm_vector16(__boolean,__string_question,__char_question,__number_question,__boolean_question,list_question,__num_eq,length,equal_question,__car,cadr,variable_form_question,lambda_form_question,caddr,application_form_question,__error);
make_cell->v.cons.cdr = scm_vector1(__cons);
set_cell_bang->v.cons.cdr = scm_vector1(__set_cdr);
cell_value->v.cons.cdr = scm_vector1(__cdr);
make_collector->v.cons.cdr = scm_vector8(__cons,cell_value,__boolean,__null_question,set_cell_bang,__cdr,__set_cdr,make_cell);
member->v.cons.cdr = scm_vector6(__boolean,__null_question,equal_question,__car,member,__cdr);
symbol_add->v.cons.cdr = scm_vector6(__boolean,member,cell_value,symbol_table,set_cell_bang,__cons);
add_all_symbols->v.cons.cdr = scm_vector6(__boolean,__symbol_question,symbol_add,__pair_question,add_all_symbols,__car);
generate_symbol->v.cons.cdr = scm_vector7(y_combinator_1,__boolean,symbol_add,__add,__string_to_symbol,__string_append,__number_to_string);
hoist->v.cons.cdr = scm_vector5(traverse,__cons,generate_symbol,hoist,map);
test_hoist->v.cons.cdr = scm_vector7(display,__newline,for_each,__car,hoist,__cdr,make_collector);
moo->v.cons.cdr = scm_vector2(test_hoist,__cons);

  scm_invoke_closure1(moo);
}
