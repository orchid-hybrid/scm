#!/bin/sh
csi ../../../utility/list.scm ../../parser.scm -e "(map pretty-print (scm-parse-file \"$1\"))" > $1.1.out
csi ../../../utility/list.scm ../../parser.scm -e "(map pretty-print (scm-parse-file \"$1.1.out\"))" > $1.2.out
diff $1.1.out $1.2.out
