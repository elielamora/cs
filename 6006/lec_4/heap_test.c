#include "heap.h"
#include "cs_helper.h"
#include <stdio.h>
#include <stdlib.h>

/**
 0  1  2  3  4  5  6  7  8  9
{2, 5, 6, 8, 9, 4, 3, 0, 1, 7};

                 2
       5                   6
   8       9             4   3
0   1    7

MaxHeapify (0)

0  1  2  3  4  5  6  7  8  9
{6, 5, 4, 8, 9, 2, 3, 0, 1, 7};

                2->6
      5                   6->2->4
  8       9             4->4->2   3
0   1    7




*/
int main(int argc, char ** argv){
        printf("unit testing heap.c\n");
        int array[10] = {2, 5, 6, 8, 9, 4, 3, 0, 1, 7};
        int size = 10;
        printf("original array\n");
        visualizeArray(array, size);
        printf("testing: Heap makeHeap(int * array, int size)\n");
        Heap heap = buildMaxHeap(array, size);
        visualizeArray(heap.heap, heap.size);
        int i = assertMaxHeapProperty(heap);
        if (i){
                printf("heap is a max heap\n");
        }else{
                printf("heap is not a max heap\n");
                exit(1);
        }
        printf("testing: sort\n");
        sort(heap);
        visualizeArray(heap.heap, heap.size);
        return 0;
}
