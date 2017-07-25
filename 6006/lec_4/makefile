heapsort: cs_helper.c heap.c heapsort.c
	clang -std=c99 heapsort.c cs_helper.c heap.c -o bin/heapsort

cs_helper_test: cs_helper_test.c cs_helper.c
	clang -std=c99 cs_helper_test.c cs_helper.c -o bin/cs_helper_test

heap_test: heap_test.c heap.c cs_helper.c
	clang -std=c99 heap_test.c heap.c cs_helper.c -o bin/heap_test
