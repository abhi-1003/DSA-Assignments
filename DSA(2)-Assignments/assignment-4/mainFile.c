#include<stdio.h>
#include<stdlib.h>
#include"functions.h"
#include<string.h>
//main function only calls function to create heap, sort and print it
int main(){
    heap* h = createheap();
    creationOfHeap(h,"file.txt");
    sortAndPrint(h);
    free(h->arr);
    free(h);
}