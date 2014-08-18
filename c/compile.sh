#!/bin/sh
csi ../utility/* ../parser/parser.scm ../desugar/desugar.scm ../closure-conversion/closure-conversion.scm ../hoist/hoist.scm ../c/c.scm -e "(test-c (desugar (car (scm-parse-file \"$1\"))))" > $1.c
