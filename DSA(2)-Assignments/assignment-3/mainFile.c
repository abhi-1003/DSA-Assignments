#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
int main() {
    AVLTree tree;
    initAVL(&tree);
    char* studentNames[] = {"Abhinav", "Amit", "Baviskar", "Thakeray", "swarnim", "MSD","Snehasish", "Gaurish", "Deshpande","Virat","stoinis","ABD","kylian","messi","KDB"};
    int numNames = sizeof(studentNames) / sizeof(studentNames[0]);

    for (int i = 0; i < numNames; i++) {
        tree.root = insertNode(&tree, tree.root, studentNames[i]);
    }
    // traverseInorder(tree.root);
    // printf("\n");
    int k = 1;
    while (k)
    {
        printf("\n1 to Traverse, 2 to insert, 3 to remove, 4 to destroy, Press Any other number to Stop:\n");
        int i;
        scanf("%d",&i);
        switch (i)
        {
        case 1:
            traverseInorder(tree.root);
            break;
        case 2:
            printf("\nEnter name to be inserted:");
            char name[50];
            scanf("%s",name);
            insertNode(&tree,tree.root,name);
            break;
        case 3:
            printf("\nEnter name to be removed:");
            char name1[50];
            scanf("%s",name1);
            removeNode(&tree,tree.root,name1);
            break;
        case 4:
            destroyTree(tree.root);
            break;
        default:
            k = 0;
            printf("\nThank YOU!! Ending the loop!\n");
            break;
        }
    }
    return 0;
}

