#include "linkedlist.h"
#include "answer09.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * * argv)
{

	//THIS IS JUST SAMPLE CODE FOR TESTING. YOU WILL HAVE TO BUILD YOUR OWN
	//TEST CASES
	
	//Build one or more linked lists here
	node_t *head = NULL;
	int i;
	for(i = 0; i < 2; i++){
		insert(&head, i, 50 + i);
	}
	printlist(head);
	node_t *temp = head;
	temp = temp -> next;
	temp -> next = head;	
	//Check to see if the lists you have built are circular
	bool result = isCircular(head);
	printf("\n%d\n", result);
	/* More testing ... */

}
