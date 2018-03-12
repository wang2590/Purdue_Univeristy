FLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFFLAG = -pg
GCC = gcc $(FLAGS) $(COVFLAGES) $(PROFFLAG)
OBJS = bmp.o filter.o pa13.o 

all: pa13

pa13: $(OBJS)
	$(GCC) $(OBJS) -o pa13

pa13.o: pa13.c bmp.h filter.h
	$(GCC) -c pa13.c

bmp.o: bmp.c bmp.h
	$(GCC) -c bmp.c

filter.o: filter.c filter.h
	$(GCC) -c filter.c

test: pa13
	-./pa13 test.bmp case1.bmp

memory: pa13
	valgrind --tool=memcheck --leak-check=full ./pa13 test.bmp sharpen.filter case1.bmp

clean: pa13
	/bin/rm -f *.o
	/bin/rm -f testgen
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa13 pa13.prof

