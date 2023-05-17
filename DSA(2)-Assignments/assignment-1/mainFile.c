#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "btbst.h"

int average(int arr[], int n){
    int avg = 0;
    for(int i = 0; i<n; i++){
        avg+=arr[i];
    }
    avg = avg/n;
    return avg;
}

void comparison(char *filename, int totalNodes, int upper) {
    
    //Opening the file and generating BT and BST from data
	int nums = totalNodes/10;
	FILE *fp1 = fopen(filename, "r");
    BST bst1 = generateBST(totalNodes, fp1);
    FILE *fp2 = fopen(filename, "r");
    BT bt1 = generateBT(totalNodes, fp2);
    
    //initialising an array to store no. of comparisons
    int *BSTnums = (int *)malloc(sizeof(int) * nums);
    int *BTnums = (int *)malloc(sizeof(int) * nums);

    //generating random numbers to check their presence in the generated tree
    srand(time(0));
    for(int i = 0; i < nums; i++){
            int randNum = (rand() % (upper + 1));

            int temp1 = searchBST(bst1, randNum);
            int temp2 = searchBT(bt1, randNum, 0);

            BSTnums[i] = temp1;
            BTnums[i] = temp2;
    }
    // Finding the average of all elements in the two arrays and storing it in a file.
    int avgBST = average(BSTnums,nums), avgBT = average(BTnums,nums);
    //printing data
    printf("Comparisons for file with %d numbers in BST: %d\n",totalNodes,avgBST);
    printf("Comparisons for file with %d numbers in BT: %d\n",totalNodes,avgBT);

    //freeing all the dynamically allocated structures
    freeTree(bst1);
    freeTree(bt1);
    free(BSTnums);
	free(BTnums);
}

int main(){
    comparison("File1.txt",1000,2000);
    comparison("File2.txt",10000,15000);
    comparison("File3.txt",100000,200000);
    return 0;
}
