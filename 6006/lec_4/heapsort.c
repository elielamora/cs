/**
        Eliel Amora
        6.006 Intro to Algorithms
        Header describing:
                - Priority Queue ADT
                - Heap functions
                - Heapsort

              0
           1     2
         3  4  5   6

        0 1 2 3 4 5 6

*/

#include "heap.h"
#include "cs_helper.h"
#include <stdio.h>
#include <stdlib.h>




int main (int argc, char ** argv){
        initRand();
        int size = 20;
        if(argc == 2){
                sscanf(argv[1],"%i", &size);
                if (200 < size || size < 2){
                        size = 20;
                        printf("size arg  given was outside of range\n");
                }
        }
        int * array = NULL;
        createRandomArray(&array, size);
        printf("unsorted array: \n\n");
        visualizeArray(array, size);
        Heap heap = buildMaxHeap(array, size);
        printf("unsorted heap: \n\n");
        visualizeArray(heap.heap, heap.size);
        sort(heap);
        printf("\nsorted array: \n\n");
        visualizeArray(heap.heap, heap.size);
        free(array);
}
