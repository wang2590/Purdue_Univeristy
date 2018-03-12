#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "path.h"
#include "solver.h"

int main(int argc, char ** argv) {
	if (argc != 3) {
		fprintf(stderr, "Wrong number of command line args\n");
		fprintf(stderr, "Usage: ./pa07 mazeFile pathFile\n");
		return EXIT_FAILURE;
	}
	
	Maze * m = readMaze(argv[1]);
	
	if (m == NULL) {
		return EXIT_FAILURE;
	}
	
//	char * path = readPath(argv[2]);
/*	if (path == NULL) {
		freeMaze(m);
		free(m);
		return EXIT_FAILURE;
	}*/
	
	char* solve = solveMaze(m);

/*	if (checkPath(m, solve)) {
		printf("Success! Path:%s \n",solve);
	} else {
		printf("Failure!\n");
	}
*/	

	freeMaze(m);
	free(m);
	free(solve);
	
	return EXIT_SUCCESS;
}
