#include<stdlib.h>
#include<stdlib.h>
#include "functions.h"


void init_bst(bst *t, int n) 
{
	int i;
	t->tree = (int *)malloc(sizeof(int) * n);
	t->size = n;
	for (i = 0; i < n; i++)
    {
        t->tree[i] = INT_MIN;
    } 
	return;   //t3843d
}

void insert(bst *t, int x) 
{
	int i = 0;
	if (t->tree[0] == INT_MIN)
	{
		t->tree[0] = x;
		return;
	}
	while (i < t->size && t->tree[i] != INT_MIN)
	{
		if (t->tree[i] == x)
        { 
			return;
        }
		if (t->tree[i] < x)
        { 
			i = 2 * i + 2;
        }
		else
        {
			i = 2 * i + 1;
        }
	}
	if (i < t->size)
    {
		t->tree[i] = x;
    }
	return;
}

void inorder_traverse(bst t, int p)
{
	if (p< t.size && t.tree[p] != INT_MIN)
	{
		inorder_traverse(t, 2 * p + 1); 
		printf("%d ", t.tree[p]);		  
		inorder_traverse(t, 2 * p + 2); 
	}
	return;
}
void preorder_traverse(bst t, int p)
{
    if (p< t.size && t.tree[p] != INT_MIN)
	{
        printf("%d ", t.tree[p]);
		preorder_traverse(t, 2 * p + 1); 		  
		preorder_traverse(t, 2 * p + 2); 
	}
	return;  
}

void postorder_traverse(bst t, int p)
{
    if (p< t.size && t.tree[p] != INT_MIN)
	{
		postorder_traverse(t, 2 * p + 1); 		  
		postorder_traverse(t, 2 * p + 2);
        printf("%d ", t.tree[p]);
	}
	return;  
}

int isComplete(bst t)
{
	int i;
	int x = 1;
	for (i = 0; i < t.size - 1; i++)
	{
		if (t.tree[i] == INT_MIN && t.tree[i + 1] != INT_MIN)
		{
			x = 0;
			break;
		}
	}
	return x;
}
int power(int n){
	if(!n){
		return 1;
	}
	return 2*power(n-1);
}
int height(bst *t){
    int heights = -1;
	int i = 0;
	int k = 1;
	while(k){
		k=0;
		int z = i;
		while(i < z + power(heights+1) && i < t->size){
			if(t->tree[i]!=INT_MIN){
				k++;
			}
			i++;
		}
		if(k==0){
			break;
		}
		heights++;
	}
	return heights;
}
int leafNodes(bst* t){
	int count = 0;
	for (int i = 0; i < t->size; i++)
	{
		if(t->tree[2*i+1]!=INT_MIN && 2*i+1 < t->size || t->tree[2*i+2]!=INT_MIN && 2*i+2 < t->size){
			count+=0;
		}
		else if(t->tree[i]!=INT_MIN){
			count++;
		}
	}
	return count;	
}
void levelOrderTraversal(bst *t){
	int heights = -1;
	int i = 0;
	int k = 1;
	while(k){
		k=0;
		int z = i;
		while(i < z + power(heights+1) && i < t->size){
			if(t->tree[i]!=INT_MIN){
				printf("%d ",t->tree[i]);
				k++;
			}
			else{
				printf("-1");
			}
			i++;
		}
		printf("\n");
		if(k==0){
			break;
		}
		heights++;
	}
}