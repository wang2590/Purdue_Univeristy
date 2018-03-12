
//Linked list node
typedef struct Node {
	float fl;
	struct Node * next;
} Node;


//Structure to hold head pointer of linked list
typedef struct list {
	Node * head;
} list;

float calcNum(float, float, char); //calculation function

void push(list * d,float); //the push the number on to the stack
float pop(list * d);  //pop the number off the stack

//void freeNode(list * d);


//Allocate and initialize an empty Path linked list
//PathLL * buildPaths();

//Remove all nodes from a linked list, deallocate the PathLL structure
//void freePaths(PathLL * p);

//Allocate a new PathNode with path as its data, r:wq
//return the address
//PathNode * buildNode(char * path);

//Deallocate a pathNode
//void freeNode(PathNode * p);

//bool addNode(PathLL * paths, char * path);

/*Remove a node from the list with the specified path

  return true if the node exists and is removed, false otherwise
*/
//bool removeNode(PathLL * paths, char * path);



