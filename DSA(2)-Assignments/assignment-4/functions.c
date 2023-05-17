#include<stdlib.h>
#include<stdio.h>
#include"functions.h"
//this file contains basic functions of heap and two additional functions: creationOfHeap and sortAndPrint
void swap(int *a,int*b){
    int temp= *a;
    *a=*b;
    *b=temp;
}
heap * createheap(){
    heap* h = (heap*) malloc(sizeof(heap));
    h->arr = NULL;
    h->size = 0;
    return h;
}
// function to heapify a subtree rooted with node i which is an index in arr[]
void maxheap(int arr[], int n, int i) {
    int large = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[large]) {
        large = l;
    }
    if (r < n && arr[r] > arr[large]) {
        large = r;
    }
    if (large != i) {
        swap(&arr[i], &arr[large]);
        maxheap(arr, n, large);
    }
}
void insert(heap * h, int value){
    h->arr=(int*)realloc(h->arr, (h->size+1)*sizeof(int));
    int i = h->size++;
    h->arr[i]= value;
    while(i != 0 && h->arr[(i-1)/2] < h->arr[i]){
        swap(&(h->arr[i]), &(h->arr[(i-1)/2]));
        i = (i-1)/2;
    }
}
// function to extract the maximum element from the heap
int extractheap(heap* h){
    if (h->size == 0) {
        printf("Heap Underflow!!\n");
        return -1;
    }
    int max = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    maxheap(h->arr, h->size, 0);
    h->arr=(int*)realloc(h->arr, h->size*sizeof(int));
    return max;
}

void heapSort(int arr[], int n) {
    // building heap
    for(int i=(n-2)/2;i>=0 ;i--){
        maxheap(arr,n,i);
    }
    //creating a max heap
    for (int i = n-1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        maxheap(arr, i, 0);
    }
}

void creationOfHeap(heap* h, char* file_name){
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Cannot Open The file\n");
        return;
    }
    int num;
    for (int i = 0; i < 1000 && fscanf(fp, "%d", &num) == 1; i++) {
        insert(h, num);
    }
    fclose(fp);
    return;
}
void sortAndPrint(heap*h){
    int n = h->size;
    int* arr = (int*) malloc(n * sizeof(int));
    //printing the heap in descending order
    printf("Printing the Numbers in Descending Order:\n");
    for (int i = 0; i < n; i++){
        arr[i] = extractheap(h);
        printf("%d ",arr[i]);
        if(i%10==0 && i!=0){
            printf("\n");
        }
    }
    printf("\n");
    printf("\n");
    //printing the heap in ascending order
    printf("Printing the Numbers in Ascending order:\n");
    heapSort(arr, n);
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]); 
        if(i%10==0 && i!=0){
            printf("\n");
        } 
    }   
    printf("\n");
    free(arr);
    return;
}