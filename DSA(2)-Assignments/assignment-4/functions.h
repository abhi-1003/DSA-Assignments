#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int * arr;
    int size;
}heap;
heap * createheap();
void maxheap(int arr[], int n, int i);
void sortAndPrint(heap*h);
void creationOfHeap(heap* h, char* file_name);
void insert(heap * h, int val);
int extractheap(heap* h);
void heapSort(int arr[], int n);

