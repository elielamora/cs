/**
        Eliel Amora
        6.006 Intro to Algorithms
        Header describing:
                - Priority Queue ADT
                - Heap functions
                - Heapsort

*/

#ifndef EAHEAP_H
#define EAHEAP_H

typedef struct Heap
{
        int * heap;
        int size;
} Heap;


void maxHeapify (Heap heap, int i);
void minHeapify (Heap heap, int i);
int indexInHeap (Heap heap, int i);
Heap buildMaxHeap (int * heap, int size);
Heap buildMinHeap (int * heap, int size);
int parentIndex(int i);
int leftIndex(int i);
int rightIndex(int i);
int increaseKey(Heap heap, int i, int s);
int decreaseKey(Heap heap, int i, int s);
int * getParent(Heap heap, int i);
int * getLeft(Heap heap, int i);
int * getRight(Heap heap, int i);
int * getSelf(Heap heap, int i);
int assertMaxHeapProperty(Heap heap);
int assertMinHeapProperty(Heap heap);
int assertSorted(int * a, int size);
void sort(Heap heap); // turns heap into sorted int array

extern const struct EAHeap EAHeap;

#endif /** EAHEAP_H */
