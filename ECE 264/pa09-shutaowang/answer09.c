#include "answer09.h"

bool isCircular(const node_t * head)
{
	const node_t *fast_p = head;
	const node_t *slow_p = head;
	while(fast_p != NULL){
		fast_p = fast_p -> next;
		if(fast_p != NULL && fast_p -> next != NULL){
			fast_p = fast_p -> next;
		}
		else{
			return false;
		}
		slow_p = slow_p -> next;
		if(fast_p == slow_p){
			return true;
		}
	}
return false;
}
