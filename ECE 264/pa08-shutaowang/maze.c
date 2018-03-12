#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

#ifndef READMAZE_OFF
Maze * readMaze(char * mazeFilename) {

	FILE *fp = fopen(mazeFilename,"r");
	
	if(fp == NULL)
	{
		return NULL;
	}

	Maze *maze1 = malloc(sizeof(Maze));

	fscanf(fp, "%d %d\n", &(maze1 -> height), &(maze1->width));	
	maze1 -> maze = malloc(sizeof(MazeSquare *) * ((maze1 -> height)));	
	for (int i = 0; i < (maze1 -> height); i++)
	{
		maze1 -> maze[i] = malloc(sizeof(MazeSquare) * (maze1 -> width));
		for (int j = 0; j < (maze1 -> width); j++)
		{
			char temp;
			fscanf(fp,"%c\n", &temp);
			
			if(temp == '#')
			{
				(maze1 -> maze[i][j]).type = WALL;
			}
			else if(temp == '.')
			{
				(maze1 -> maze[i][j]).type = SPACE;
			}
			else if(temp == 's')
			{
				(maze1 -> maze[i][j]).type = START;
				(maze1 -> start).xpos = j;
				(maze1 -> start).ypos = i;
			}
			else if(temp == 'e')
			{
				(maze1 -> maze[i][j]).type = END;
				(maze1 -> end).xpos = j;
				(maze1 -> end).ypos = i;
			}
			maze1 -> maze[i][j].visited = false;
		}
	}

	fclose(fp);
	return (maze1);	

}
#endif //#ifndef READMAZE_OFF

#ifndef FREEMAZE_OFF
void freeMaze(Maze * m) {

	for(int i=0; i < (m -> height); i++)
	{
		free(m -> maze[i]);
	}
	free(m -> maze);

}
#endif //#ifndef FREEMAZE_OFF
