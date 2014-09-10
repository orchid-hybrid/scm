lessons learned
===============

* we need GC to bootstrap, otherwise it tries to use up >8GB
* stack allocated variables are considered live, we can't use C's stack because the GC needs to move all these pointers - we have to build our own stack and have it as part of the GC root node
* we need TCO to remove stack more frames so that GC can collect more
* SET! mutation is difficult to implement directly, seems to require desugaring into mutable cells
* from the code size breakdown: emitting c is the most complex and ugly part - split this into simpler units
* second to that is desugaring, this was a hack to get around implementing a macro system

