scm
===

The SCM compiler asked us to sacrife a child when we attempted to bootstrap it.

![](https://i.imgur.com/6tQKqCJ.jpg)

We pressed on but it said "STOP" "STOP".

![](https://i.imgur.com/i1vvgPV.jpg)

R.I.P. SCM


lessons learned
===============

* we need GC to bootstrap, otherwise it tries to use up >8GB
* stack allocated variables are considered live, we can't use C's stack because the GC needs to move all these pointers - we have to build our own stack and have it as part of the GC root node
* we need TCO to remove stack more frames so that GC can collect more
* SET! mutation is difficult to implement directly, seems to require desugaring into mutable cells
* from the code size breakdown: emitting c is the most complex and ugly part - split this into simpler units
* second to that is desugaring, this was a hack to get around implementing a macro system


      210   594  6649 parser/parser.scm
      250   760  6406 desugar/desugar.scm
       74   248  2587 cps/cps.scm
      147   537  5097 lambda-lifting/lambda-lifting.scm
       59   193  2229 closure-conversion/closure-conversion.scm
       22    54   659 hoist/hoist.scm
      400  1125 14646 c/c.scm
    
      215   793  5727 prelude/prelude.scm
    
       13    35   385 utility/collector.scm
       33   135   985 utility/gensym.scm
       41   116   805 utility/list.scm
       33   122  1014 utility/set.scm
       81   242  2304 utility/traverse.scm
