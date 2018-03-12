CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFFLAG = -pg
GCC = gcc $(CFLAGS) $(COVFLAGS)
all:pa12

pa12:pa12.o scanner.o tree.o expressionTree.o 
	$(GCC) pa12.o -o pa12
pa12.o: pa12.c expressionTree.h scanner.h tree.h
	$(GCC) -c pa12.c -o pa12.o
scanner.o: scanner.c scanner.h
	$(GCC) -c scanner.c -o scanner.o
tree.o: tree.c tree.h
	$(GCC) -c tree.c -o tree.o
expressionTree.o: expressionTree.c expressionTree.h tree.h
	$(GCC) -c expressionTree.c -o expressionTree.o
test: clean pa12 
	./pa12 inputs/test1 case1 
	./pa12 inputs/test2 case2
	./pa12 inputs/test3 case3
	./pa12 inputs/test4 case4

memory:
		valgrind --leak-check=full --show-reachable=yes ./pa12 inputs/test1 case1 
		valgrind --leak-check=full --show-reachable=yes ./pa12 inputs/test2 case2
		valgrind --leak-check=full --show-reachable=yes ./pa12 inputs/test3 case3
		valgrind --leak-check=full --show-reachable=yes ./pa12 inputs/test4 case4

clean:
		/bin/rm -f *.o
		/bin/rm -f *.gcno gmon.out *gcov
		/bin/rm -f *.gcda
		/bin/rm -f pa12 pa12.prof


































