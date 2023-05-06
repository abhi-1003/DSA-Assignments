#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
typedef struct bst
{
	int *tree; 
	int size;  
}bst;
void init_bst(bst *t, int n);
void insert(bst *t, int x);
void inorder_traverse(bst t, int p);
void preorder_traverse(bst t, int p);
void postorder_traverse(bst t, int p);
int isComplete(bst t);
int power(int n);
int height(bst *t);
int leafNodes(bst* t);
void levelOrderTraversal(bst *t);
