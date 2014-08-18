TEST = c.2.out \
       closure-conversion.2.out \
       collector.2.out \
       desugar.2.out \
       gensym.2.out \
       hoist.2.out \
       list.2.out \
       set.2.out \
       traverse.2.out

all: $(TEST)
	echo ALL TESTS PASSED

%.2.out: %.scm
	echo $<
	sh parser.sh $<

clean:
	rm -f *.out
