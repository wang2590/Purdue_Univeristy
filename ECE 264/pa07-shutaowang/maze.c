#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

#ifndef READMAZE_OFF
Maze * readMaze(char * mazeFilename) {
	Maze * maze1 = malloc(sizeof(Maze));

	//reads in the maze data from an inputs file
	FILE *file = fopen(mazeFilename,"r");
	fscanf(file,"%d %d\n",&(maze1 -> height), &(maze1 -> width));
	char old;
	//allocate the array of rows
	//allocate an array of floats
	maze1 -> maze = malloc((maze1 -> height) * sizeof(MazeSquare*));

	for (int i = 0;i < (maze1 -> height); i++){
		maze1 -> maze[i] = malloc((maze1 -> width) * sizeof(MazeSquare));

		for(int j = 0;j < (maze1 -> width);j++){

			fscanf(file,"%c\n",&old);
			if(old == '.')  {((*maze1).maze[i][j]).type = WALL;}
			if(old == '#')  {((*maze1).maze[i][j]).type = SPACE;}
			if(old == 's')  {((*maze1).maze[i][j]).type = START;
				(*maze1).start.xpos = i;
				(*maze1).start.ypos = j;}
			if(old == 'e')  {
				((*maze1).maze[i][j]).type = END;
				(*maze1).end.xpos = i;
				(*maze1).end.ypos = j;}
		}
	}
	fclose(file);
	return(maze1);
}
#endif //#ifndef READMAZE_OFF

#ifndef FREEMAZE_OFF
void freeMaze(Maze * m) {
	//1. Free each of the "rows" of the maze
	for (int i = 0; i < (m -> height); i++){
		free(m -> maze[i]);
	}
	//2. Free the "spine" of the array
	free(m -> maze);
}
#endif //#ifndef FREEMAZE_OFF
