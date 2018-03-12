#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

#ifndef BUILDTREE_OFF
TreeNode * buildExpressionTree(Scanner * s) {

	Token next = nextToken(s);

	if(next.type == '@'){
		TreeNode * retval = buildTreeNode(next);
		return retval;
	}


	if(next.type == '('){
		TreeNode * tree1 = buildExpressionTree(s);

		Token op = nextToken(s);

		TreeNode * tree2 = buildExpressionTree(s);

		TreeNode * retval = buildTreeNode(op);
		retval->left = tree1;
		retval->right = tree2;
		
		Token rightParen = nextToken(s);
		if(rightParen.type != ')'){
			fprintf(stderr, "Invailde Input!");
		}
		return retval;
	}
	
	fprintf(stderr, "Invalid Input");
	return NULL;
	
}
#endif

#ifndef POSTFIX_OFF
void makePostFix(TreeNode * t, FILE * fptr) {
	
	if(t -> left == NULL){
		if (t -> t.type == '@'){
			fprintf(fptr,"%f ",t -> t.value);
		}
		else if(t -> t.type == '+'){
			fprintf(fptr,"+ ");
		}
		else if(t -> t.type == '-'){
			fprintf(fptr,"- ");
		}
		else if(t -> t.type == '*'){
			fprintf(fptr,"* ");
		}
		else if(t -> t.type == '/'){
			fprintf(fptr,"/ ");
		}
	}

	if(t -> left != NULL){
		makePostFix(t -> left,fptr);
		makePostFix(t -> right,fptr);	
		/*switch (t -> t.type){
                      	case T_VAL: fprintf(fptr,"%f",t -> t.value);break;
                        case T_ADD: fprintf(fptr,'+');break;
                        case T_SUB: fprintf(fptr,'-');break;
                        case T_MUL: fprintf(fptr,'*');break;
                        case T_DIV: fprintf(fptr,'/');break;
               	}*/
		if (t -> t.type == '@'){
                         fprintf(fptr,"%f ",t -> t.value);
                 }
                 else if(t -> t.type == '+'){
                         fprintf(fptr,"+ ");
                 }
                 else if(t -> t.type == '-'){
                         fprintf(fptr,"- ");
                 }
                 else if(t -> t.type == '*'){
                         fprintf(fptr,"* ");
                 }
                 else if(t -> t.type == '/'){
                         fprintf(fptr,"/ ");
                 }
	
	}
}
#endif
