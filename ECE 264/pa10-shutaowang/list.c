#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

/** INTERFACE FUNCTIONS **/

PathLL * buildPaths() {
	PathLL * retval = malloc(sizeof(PathLL));
	retval->head = NULL;
	return retval;
}

void freePaths(PathLL * p) {
	freeNode(p -> head);
	free(p);
}

PathNode * buildNode(char * path) {
	PathNode * retval = malloc(sizeof(PathNode));
	retval -> path = malloc(strlen(path) + 1);
	retval -> next = NULL;
	strcpy(retval -> path,path);
	return retval;
	
	//WARNING: don't forget to use strcpy to copy path into the
	//new node. Don't just set them equal, otherwise if the input path changes
	//the node will have the wrong path.
}

void freeNode(PathNode * p) {
	if(p == NULL){
		return;
	}
	if(p -> next == NULL){
		free(p->path);
		free(p);
		return;
	}
	if(p -> next != NULL){
		freeNode(p->next);
		free(p->path);
		free(p);
		return;
	}
}
bool addNode(PathLL * paths, char * path) {
	//insert a new list
	//keep sorted{ 1. shorter paths, 2. fewer turns come first, 3. alphabetic order}
	//return ture if succeess
	//return false if trying to add ia exist linked list
	PathNode ** add	= &(paths -> head);
	
	if(containsNode(paths,path) == true){
		return false;
	}
	
	int i;
	int j;
	int k;

	while((*add) != NULL){
		
		if(strlen(path) < strlen((*add) -> path)){
			PathNode *temp = *add;
			*add = buildNode(path);
			(*add) -> next = temp;
			return true;
		}
		if(strlen(path) == strlen((*add)->path)){
		j = 0;
		k = 0;
		for(i = 0; i < strlen(path) - 1; i++){
			if(path[i] != path[i+1]){
				j++;
			}
			}
		for(i = 0; i < strlen(path) - 1; i++){
			if((*add) -> path[i] != (*add) -> path[i+1]){
				k++;
			}
			}	
		if(j < k){
			PathNode *temp = *add;
			*add = buildNode(path);
			(*add) -> next = temp;
			return true;
		}
		
		if(j == k && strcmp(path,(*add) -> path) < 0){
			PathNode *temp = *add;
			*add = buildNode(path);
			(*add) -> next = temp;
			return true;
		}
		}
		add = &((*add) -> next);
		
		}

	*add = buildNode(path);
	(*add)->next = NULL;
		
	return true;
}

bool removeNode(PathLL * paths, char * path) {
	
  //return true if remove succeeds
  //return false if trying to remove a list not int the in the linked list
	PathNode ** node = &(paths -> head);
	if(containsNode(paths,path) == false){
		return false;
	}
	while(strcmp((*node)->path,path) !=0){
		node = &(*node)->next;
	}
	
	PathNode * temp = *node;
	*node = (*node) -> next;
	free(temp -> path);
	free(temp);
	return true;
}
bool containsNode(PathLL * paths, char * path) {
	//checks if a path is in the linked list
	PathNode * way = paths -> head;
	
	while(way != NULL)
	{
		if(!strcmp(way -> path, path)){
			return true;
		}
	way = way -> next;
	}
	return false;	
}

void printPaths(PathLL * paths, FILE * fptr) {
	PathNode * curr = paths->head;
	int i = 0;
	while (curr != NULL) {
		fprintf(fptr, "Path %2d: %s\n", i, curr->path);
		i++;
		curr = curr->next;
	}
}
