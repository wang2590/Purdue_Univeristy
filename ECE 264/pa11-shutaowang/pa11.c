#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

int main (int argc, char ** argv) {
	if (argc != 2) {
		fprintf(stderr, "Incorrect number of arguments.\n");
		fprintf(stderr, "Usage: ./pa11 <input file>\n");		
		return EXIT_FAILURE;
	}

	float result = 0; //store the result of your calculation here.
	char str[256];//temporary scaned variable
	float num;//store the numbers
	char calc;//store the "+,-,*,/"
	float popBack;//the pop back float value

	list * head = malloc(sizeof(list));
	head -> head = NULL;	

	FILE * fptr = fopen(argv[1],"r");
	if(fptr == NULL){
		fprintf(stderr,"fopen fail\n");
		return EXIT_FAILURE;
	}
	
	
	while(!feof(fptr)){
		int ret = fscanf(fptr,"%s", str);
		if(ret != EOF){
			//the scaned str is a operator " +,-,*,/ "
			if( (atof(str) == 0) && (strlen(str) == 1) && (str[0] != '0') ){
				calc = str[0];
				if((head -> head == NULL) || (head -> head -> next ==NULL)){
					return EXIT_FAILURE;
				}
				//pop the two numbers for calculation
				float num1 = pop(head);
				float num2 = pop(head);
	
				//calculation call
				popBack = calcNum(num1, num2, calc);

				//push the pop back value on to the stack
				push(head,popBack);	
			}
			else{
				num = (float)atof(str);
				
				//push the float number on stack 
				push(head, num);
				
			} 
		}
	}

	//check if there none or more than one node return failure
	if((head -> head -> next != NULL) || (head -> head == NULL) ){
		return EXIT_FAILURE; 
	}
			
	result = head -> head -> fl;  //print out the last outcome
	printf("%f\n", result);

	//free all the node and list
	if(head -> head != NULL)
	{
		Node * gg = head-> head;
		Node * next;
		while(gg != NULL){
			next = gg -> next;
			if(gg == NULL){
				break;
			}
			free(gg);
			gg = next;
		}
	}
	free(head);

/*	while(head -> head != NULL){
	head -> head = head ->head -> next;
	free();
	free(head);
	}
*/
	fclose(fptr);

	return EXIT_SUCCESS;
}

float calcNum(float val2,float val1, char calc){
	float num;
	if(calc == '+'){
		num = val1 + val2;
	}
	else if(calc == '-'){
		num = val1 - val2;
	}
	else if (calc == '*'){
		num = val1 * val2;
	}
	else if (calc == '/'){
		num = val1 / val2;
	}
return num;
}

void push(list * d,float n){
	Node * newNode = malloc(sizeof(Node));
	newNode -> fl = n;
	newNode -> next = d -> head;
	d -> head = newNode;
//	free(newNode);
}

float pop(list * d){
	float popNum = d -> head -> fl;
	Node * popNode = d -> head;
	popNode = popNode -> next;
	free(d->head);
	d -> head = popNode;
	return popNum;
}	


