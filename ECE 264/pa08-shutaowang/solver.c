#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "solver.h"
#include "path.h"

char * solveMaze(Maze * m) {
	char * retval = malloc(sizeof(char) * ((m->width * m->height) + 1));

	MazePos mp = {.xpos = m->start.xpos, .ypos = m->start.ypos};
	if (!depthFirstSolve(m, mp, retval, 0)) {
		fprintf(stderr, "No solution found!\n");
	} else {
		printf("Solution found: %s\n", retval);
	}
	
	return retval;
}

bool depthFirstSolve(Maze * m, MazePos curpos, char * path, int step) {

	MazePos mNorth = {.xpos = curpos.xpos, .ypos = (curpos.ypos) - 1};
	MazePos mSouth = {.xpos = curpos.xpos, .ypos = (curpos.ypos) + 1};
	MazePos mWest = {.xpos = (curpos.xpos) - 1, .ypos = curpos.ypos};
	MazePos mEast = {.xpos = (curpos.xpos) + 1, .ypos = curpos.ypos};
	
	//is the exit,return true, add thie square as last path,don't forget add path[n]='\0'
	if((curpos.xpos == m->end.xpos) && (curpos.ypos == m->end.ypos)){
		path[step] = '\0';
		return true;
	}
	
	//base case:
	//out of  bounds, return false
	if(((curpos.ypos > (m->height-1)) || (curpos.ypos < 0)) || ((curpos.xpos > (m->width-1)) || (curpos.xpos < 0))){
		return false;
	}
	
	//a wall return false
	if(m -> maze[curpos.ypos][curpos.xpos].type == WALL){
		return false;
	}
	
	//been visited ,return false
	if (m -> maze[curpos.ypos][curpos.xpos].visited == true){
		return false;
	}
	
	//make visited palces TRUE
	m -> maze[curpos.ypos][curpos.xpos].visited = true;

	//reursive case:
	//make the paht one step longer, and recursively call four more times
	//return value: if return true add current square to the solution path,return ture
	//if return false , move on to the next recursive call
	if(depthFirstSolve(m, mNorth, path, step+1) == true){
		path[step] = NORTH;
		return true;
	}
	else if((depthFirstSolve(m, mSouth, path, step+1)) == true){
		path[step] = SOUTH;
		return true;
	}
	else if((depthFirstSolve(m, mWest, path, step+1)) == true){
		path[step] = WEST;
		return true;
	}
	else if((depthFirstSolve(m, mEast, path, step+1)) == true){
		path[step] = EAST;
		return true;
	}


	return false;
}
