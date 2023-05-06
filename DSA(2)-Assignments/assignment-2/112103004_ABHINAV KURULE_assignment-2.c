#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "functions.h"
int main()
{
    bst x;
	init_bst(&x, 10);

	insert(&x, 8);
	insert(&x, 5);
	insert(&x, 10);
	insert(&x, 3);
	insert(&x, 7);
	insert(&x, 9);
	insert(&x, 11);
	printf("height of the tree is: %d\n",height(&x));
	printf("total number of leaf node: %d\n", leafNodes(&x));
	
    if(isComplete(x))
    {
        printf("Tree is Complete\n");
    }
    else
    {
        printf("Tree is not Complete\n");
    }
	levelOrderTraversal(&x);
    // printf("Inorder:- ");
	// inorder_traverse(x, 0);
    // printf("\n");
    // printf("Preorder:- ");
	// preorder_traverse(x, 0);
    // printf("\n");
    // printf("Postorder:- ");
	// postorder_traverse(x, 0);
	// printf("\n");
}