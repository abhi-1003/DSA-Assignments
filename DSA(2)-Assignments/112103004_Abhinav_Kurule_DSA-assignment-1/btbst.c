#include "btbst.h"
#include <stdlib.h>
#include <time.h>

// BST Functions:
void initBST(BST *t){
	*t = NULL;
	return;
}
int insertBST(BST *t, int key) {
    if (!(*t)) {
        TreeNode *newTreeNode = (TreeNode*)malloc(sizeof(TreeNode));
        if (!newTreeNode) {
            return 0;
        }
        newTreeNode->data = key;
        newTreeNode->left = NULL;
        newTreeNode->right = NULL;
        *t = newTreeNode;
        return 1;
    }
    if ((*t)->data == key) {
        return 0;
    }
    if (key < (*t)->data) {
        return insertBST(&((*t)->left), key);
    }
    else {
        return insertBST(&((*t)->right), key);
    }
}
TreeNode* generateBST(int totalTreeNodes, FILE *fp){
	int num;
	BST t;
	initBST(&t);
	int count = 0;

	if(fp == NULL){
		printf("Error opening the file\n");
		return NULL;
	}
	while((count != totalTreeNodes) && (fscanf(fp, "%d\n", &num) != EOF)){
		count += insertBST(&t, num);
	}	
	return t;	
}


int searchBST(BST t, int key) {
    if (!t) {
        return 0;
    }
    if (t->data == key) {
        return 1;
    }
    if (t->data < key) {
        return 1 + searchBST(t->right, key);
    } else {
        return 1 + searchBST(t->left, key);
    }
}


//BT Functions:
void initBT(BT *t){
	*t = NULL;
	return;
}
int insertBT(BT *t, int key){
	TreeNode *newTreeNode = (TreeNode *)malloc(sizeof(TreeNode));
	if(!newTreeNode){
		return 0;
	}
	newTreeNode->data = key;
	newTreeNode->left = NULL;
	newTreeNode->right = NULL;
	if(!(*t)){
		*t = newTreeNode;
		return 1;
	}
	TreeNode *p = *t;
	TreeNode *q = NULL;
	int randNum;
	srand(time(0));
        while(p){
		randNum = rand() % 1000;

		if(randNum % 2 == 0){
			q = p;
			p = p->right;
		}
		else{
			q = p;
			p = p->left;
		}
	}
	if(randNum % 2 == 0){
		q->right = newTreeNode;
	}
	else{
		q->left = newTreeNode;
	}
	return 1;
}


TreeNode* generateBT(int totalTreeNodes, FILE *fp){
	int num;
	BT t;
	initBT(&t);
	int count = 0;

	if(fp == NULL){
		printf("Error opening the file!\n");
		return NULL;
	}
	while((count != totalTreeNodes) && (fscanf(fp, "%d\n", &num) != EOF)){
		count += insertBT(&t, num);
	}
	
	return t;
}


int searchBT(BST t, int key, int found) {
    if (!t || found) {
        return 0;
    }

    int count = 0;
    count += searchBT(t->left, key, found);

    if (t->data == key) {
        count++;
        found = 1;
        return count;
    } else {
        count++;
    }

    count += searchBT(t->right, key, found);

    return count;
}


// Function to free the tree:
void freeTree(TreeNode *t){
    if(!t){
        return;
    }
    freeTree(t->left);
    freeTree(t->right);
    free(t);
}
