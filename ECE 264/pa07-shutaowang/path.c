#include <stdio.h>
#include <stdlib.h>
#include "path.h"
#include "maze.h"
#include <string.h>

#ifndef READPATH_OFF
char * readPath(char * pathFilename) {
	//reads a proposed solution from an inputs file
	FILE *file = fopen (pathFilename,"r");
	if(file == NULL){return false;}
	int num = 0;
	while((fgetc(file) != EOF))
	{
		num++;
	}
	num++;

	fclose(file);

	FILE *file1 = fopen(pathFilename,"r");
	if(file1 == NULL) return false;
	char * string = malloc(sizeof(char) * num+1);
	for (int i = 0; !feof(file1); i++) {
		char c = fgetc(file1);
		string[i] = c;
	}
	string[num-1] = '\0';  
	//printf("%s\n",string);
	fclose(file1); 
	return string;

}
#endif //#ifndef READPATH_OFF

#ifndef CHECKPATH_OFF
bool checkPath(Maze * m, char * path) {

	//creat a cursor starts at the starting position of the maze;value 's'
	int s_xpos = m -> start.xpos;
	int s_ypos = m -> start.ypos;
	int e_xpos = m -> end.xpos;	
	int e_ypos = m -> end.ypos;
	
//printf("startx : %d starty : %d\n", s_xpos, s_ypos);
	int w = m->width;
	int h = m->height;
	int i = 0;
	while(i < strlen(path)){
//	printf("i : %d\n", i);
	
//		if (m-> maze[s_ypos][s_xpos].visited != false) return false;
	//check ever move out of the boundaries of the maze
		if(((s_ypos > w-1) || (s_ypos < 0)) || ((s_xpos > h-1) || (s_xpos < 0))){return false;}

//		m->maze[s_ypos][s_xpos].visited = true;
		//(h - s_ypos - 1)
		//check ever move into a square in a wall
	//	else if(m -> maze[h - s_xpos - 1 ][s_ypos].type == '#')	{return false;}

		//check ever move to a suqare already visited
	//	else if(m -> maze[h - s_xpos - 1][s_ypos].visited == true) {return false;}
//printf("xpos : %d ypos : %d\n", s_xpos, s_ypos);
		//make all the visited places true
//		m -> maze[s_ypos][s_xpos].visited = true;
		//check ever move out of the boundaries of the maze
	//	if(((s_xpos >= w) || (s_xpos < 0)) || ((s_ypos >= h) || (s_ypos < 0))){return false;}
		//(h - s_ypos - 1)
		//check ever move into a square in a wall
	//	else if(m -> maze[h - s_ypos - 1 ][s_xpos].type == '#')	{return false;}

		//check ever move to a suqare already visited
	//	else if(m -> maze[h - s_ypos - 1][s_xpos].visited == true) {return false;}
		if(((s_ypos > w-1) || (s_ypos < 0)) || ((s_xpos > h-1) || (s_xpos < 0))){return false;}

		if(path[i] == NORTH){s_xpos--;}
		else if(path[i] == SOUTH){s_xpos++;}
		else if(path[i] == EAST){s_ypos++;}
		else if(path[i] == WEST){s_ypos--;}
		
		i++;
	}

	//if passed return success
	if((s_xpos == e_xpos) && (s_ypos == e_ypos))  {return true;}
	return false;
}
#endif //#ifndef CHECKPATH_OFF
