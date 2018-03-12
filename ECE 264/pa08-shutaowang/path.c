#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"

#ifndef READPATH_OFF
char * readPath(char * pathFilename)
{
	FILE *fp = fopen(pathFilename, "r");
	if(fp == NULL)
	{
		return NULL;
	}
	char *path_string;
	int path_len = 0;
	while(fgetc(fp) != EOF)
	{
		path_len++;
	}
	path_string = (char*)malloc(sizeof(char) * (path_len + 1));
	fseek(fp,0,SEEK_SET);
	if(fread(path_string, 1, path_len, fp))
	{
		fclose(fp);
		path_string[path_len] = '\0';
		return path_string;
	}
	else
	{
		fclose(fp);
		return '\0';
	}

}
#endif //#ifndef READPATH_OFF

#ifndef CHECKPATH_OFF
bool checkPath(Maze * m, char * path) 
{
	int index = 0;
	int s_x = (m -> start).xpos;
	int s_y = (m -> start).ypos;
	int e_x = (m -> end).xpos;
	int e_y = (m -> end).ypos;
	int b_x = m -> width - 1;
	int b_y = m -> height - 1;
	int length_str = 0;
	length_str = strlen(path);
	int i = 0;

	while(i < length_str)
	{
		if(m -> maze[s_y][s_x].visited == true)
		{
			if(s_y == e_y && s_x == e_x)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		m -> maze[s_y][s_x].visited = true;
		i++;
		if((m -> maze[s_y][s_x]).type == WALL)
		{
			return false;
		}
		else
		{
			if(path[index] == NORTH)
			{
				s_y--;
				if((s_y > b_y) || (s_y < 0))
				{
					return false;
				}
				else
				{
					index++;
				}
			}
			else if(path[index] == SOUTH)
			{
				s_y++;
				if((s_y > b_y) || (s_y < 0))
				{
					return false;
				}
				else
				{
					index++;
				}
			}
			else if(path[index] == EAST)
			{
				s_x++;
				if((s_x > b_x) || (s_x < 0))
				{
					return false;
				}
				else
				{
					index++;
				}
			}
			else if(path[index] == WEST)
			{
				s_x--;
				if((s_x > b_x) || (s_x < 0))
				{
					return false;
				}
				else
				{
					index++;
				}
			}
		}
	}
	if((s_x == e_x) && (s_y == e_y))
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif //#ifndef CHECKPATH_OFF

