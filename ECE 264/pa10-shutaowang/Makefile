CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFFLAG = -pg
GCC = gcc $(CFLAGS) $(COVFLAGS)
all:pa10

pa10:pa10.o maze.o path.o solver.o mazehelper.o list.o
	$(GCC) pa10.o maze.o path.o solver.o list.o mazehelper.o -o pa10
pa10.o: pa10.c maze.h path.h solver.h 
	$(GCC) -c pa10.c -o pa10.o
maze.o: maze.c maze.h 
	$(GCC) -c maze.c -o maze.o
path.o:path.c path.h
	$(GCC) -c path.c -o path.o
solver.o:solver.c solver.h path.h list.h
	$(GCC) -c solver.c -o solver.o
list.o:list.c list.h
	$(GCC) -c list.c -o list.o

mazehelper.o:mazehelper.c mazehelper.h
	$(GCC) -c mazehelper.c -o mazehelper.o
	
test: clean pa10 
#	./pa10 inputs/maze1 paths1 
#	./pa10 inputs/maze2 paths2
	./pa10 inputs/maze3 paths3
#	./pa07 inputs/maze2 inputs/path2-bad1
#	./pa07 inputs/maze2 inputs/path2
#	./pa07 inputs/maze3 inputs/path3
#	./pa07 inputs/maze3 inputs/path3-bad1
#	./pa07 inputs/maze4 inputs/path4
#	./pa07 inputs/maze4 inputs/path4-bad1
#	./pa07 inputs/maze5 inputs/path5

memory:
#		valgrind --leak-check=full ./pa10 inputs/maze1 paths1
#		valgrind --leak-check=full ./pa10 inputs/maze2 paths2
		valgrind --leak-check=full ./pa10 inputs/maze3 paths3
#		valgrind --leak-check=full ./pa07 inputs/maze2 inputs/path2-bad1
#		valgrind --leak-check=full ./pa07 inputs/maze2 inputs/path2
#		valgrind --leak-check=full ./pa07 inputs/maze3 inputs/path3
#		valgrind --leak-check=full ./pa07 inputs/maze3 inputs/path3-bad1
#		valgrind --leak-check=full ./pa07 inputs/maze4 inputs/path4
#		valgrind --leak-check=full ./pa07 inputs/maze4 inputs/path4-bad1
#		valgrind --leak-check=full ./pa07 inputs/maze5 inputs/path5

clean:
		/bin/rm -f *.o
		/bin/rm -f *.gcno gmon.out *gcov
		/bin/rm -f *.gcda
		/bin/rm -f pa10 pa10.prof
