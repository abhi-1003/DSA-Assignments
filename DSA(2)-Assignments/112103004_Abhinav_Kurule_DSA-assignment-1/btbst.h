#include <stdio.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *left;
	struct TreeNode * right;
} TreeNode;
typedef TreeNode *BT, *BST;
TreeNode* generateBT(int totalTreeNodes, FILE *fp);
TreeNode* generateBST(int totalTreeNodes, FILE *fp);
void initBST(BST *t);
int insertBST(BST *t, int key);
int searchBST(BST t, int key);

void initBT(BT *t);
int insertBT(BT *t, int key);
int searchBT(BT t, int key, int found);
void freeTree(TreeNode *t);
