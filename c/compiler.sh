#!/bin/sh
csi ../utility/* ../parser/parser.scm ../desugar/desugar.scm ../closure-conversion/closure-conversion.scm ../hoist/hoist.scm ../c/c.scm -e "(compile-c-definitions (map desugar (scm-parse-file \"$1\")))" > $1.c
