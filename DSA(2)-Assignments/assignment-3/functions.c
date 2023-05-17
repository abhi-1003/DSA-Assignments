#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void initAVL(AVLTree* tree) {
    tree->root = NULL;
}

int getHeight(AVLNode* node) {
    if (node == NULL)
        return 0;

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

AVLNode* createNode(char* name) {
    AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
    if (newNode != NULL) {
        newNode->balance_factor = 0;
        strncpy(newNode->student_name, name, 49);
        newNode->student_name[49] = '\0';
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = NULL;
    }
    return newNode;
}

AVLNode* performRRRotation(AVLNode* node) {
    AVLNode* pivot = node->right;
    node->right = pivot->left;

    if (pivot->left != NULL)
        pivot->left->parent = node;

    pivot->parent = node->parent;

    if (node->parent != NULL) {
        if (node->parent->left == node)
            node->parent->left = pivot;
        else
            node->parent->right = pivot;
    }

    pivot->left = node;
    node->parent = pivot;

    // Update balance factors
    node->balance_factor = getHeight(node->right) - getHeight(node->left);
    pivot->balance_factor = getHeight(pivot->right) - getHeight(pivot->left);

    return pivot;
}

AVLNode* performLLRotation(AVLNode* node) {
    AVLNode* pivot = node->left;
    node->left = pivot->right;

    if (pivot->right != NULL)
        pivot->right->parent = node;

    pivot->parent = node->parent;

    if (node->parent != NULL) {
        if (node->parent->left == node)
            node->parent->left = pivot;
        else
            node->parent->right = pivot;
    }

    pivot->right = node;
    node->parent = pivot;

    // Update balance factors
    node->balance_factor = getHeight(node->right) - getHeight(node->left);
    pivot->balance_factor = getHeight(pivot->right) - getHeight(pivot->left);

    return pivot;
}

AVLNode* performRLRotation(AVLNode* node) {
    node->right = performLLRotation(node->right);
    return performRRRotation(node);
}

AVLNode* performLRRotation(AVLNode* node) {
    node->left = performRRRotation(node->left);
    return performLLRotation(node);
}

AVLNode* insertNode(AVLTree* tree, AVLNode* node, char* name) {
    if (node == NULL)
        return createNode(name);

    if (strcmp(name, node->student_name) < 0) {
        node->left = insertNode(tree, node->left, name);
        node->left->parent = node;
    } else if (strcmp(name, node->student_name) > 0) {
        node->right = insertNode(tree, node->right, name);
        node->right->parent = node;
    } else {
       return node;
    }

    node->balance_factor = getHeight(node->right) - getHeight(node->left);

    if (node->balance_factor == 2) {
        if (node->right->balance_factor == -1)
            node->right = performLLRotation(node->right);
        return performRRRotation(node);
    } else if (node->balance_factor == -2) {
        if (node->left->balance_factor == 1)
            node->left = performRRRotation(node->left);
        return performLLRotation(node);
    }

    return node;
}

AVLNode* findMinNode(AVLNode* node) {
    if (node == NULL)
        return NULL;
    AVLNode* current = node;
    while (current->left != NULL)
        current = current->left;

    return current;
}

AVLNode* removeNode(AVLTree* tree, AVLNode* node, char* name) {
    if (node == NULL)
        return NULL;
    if (strcmp(name, node->student_name) < 0)
        node->left = removeNode(tree, node->left, name);
    else if (strcmp(name, node->student_name) > 0)
        node->right = removeNode(tree, node->right, name);
    else {
        if (node->left == NULL || node->right == NULL) {
            AVLNode* temp = node->left ? node->left : node->right;

            if (temp == NULL) {
                temp = node;
                node = NULL;
            } else {
                *node = *temp;
                free(temp);
            }
        } else {
            AVLNode* temp = findMinNode(node->right);
            strncpy(node->student_name, temp->student_name, 49);
            node->student_name[49] = '\0';
            node->right = removeNode(tree, node->right, temp->student_name);
        }
    }

    if (node == NULL)
        return node;

    node->balance_factor = getHeight(node->right) - getHeight(node->left);

    if (node->balance_factor == 2) {
        if (node->right->balance_factor == -1)
            node->right = performLLRotation(node->right);
        return performRRRotation(node);
    } else if (node->balance_factor == -2) {
        if (node->left->balance_factor == 1)
            node->left = performRRRotation(node->left);
        return performLLRotation(node);
    }

    return node;
}

void traverseInorder(AVLNode* node) {
    if (node != NULL) {
        traverseInorder(node->left);
        printf("Name: %s, Parent: %s, Balance Factor: %d\n", node->student_name,
        (node->parent != NULL ? node->parent->student_name : "NULL"), node->balance_factor);
        traverseInorder(node->right);
    }
}

void destroyTree(AVLNode* node) {
    if (node != NULL) {
        destroyTree(node->left);
        destroyTree(node->right);
        free(node);
    }
}

