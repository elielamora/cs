#include "heap.h"
#include "cs_helper.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int parentIndex(int i){
        return (i-1)/2;
}
int leftIndex(int i){
	return (i*2) + 1;
}
int rightIndex(int i){
        return (i+1) * 2;
}

int * getParent(Heap heap, int i){
        int parent = parentIndex(i);
        if (parent < 0 || heap.size <= parent)
                return NULL;
        return &((heap.heap)[parent]);
}
int * getLeft(Heap heap, int i){
        int left = leftIndex(i);
        if (left < 0 || heap.size <= left)
                return NULL;
        return &((heap.heap)[left]);
}
int * getRight(Heap heap, int i){
        int right = rightIndex(i);
        if (right < 0 || heap.size <= right)
                return NULL;
        return &((heap.heap)[right]);
}
int * getSelf(Heap heap, int i){
        if (i < 0 || heap.size <= i){
                return NULL;
        }
        return &((heap.heap)[i]);
}

void maxHeapify (Heap heap, int i){
        if (i < 0 || heap.size <= i)
                return;
        int * left = getLeft(heap, i);
        int * right = getRight(heap, i);
        int * self = getSelf(heap, i);
        if (!self){return;}
        if (left && right){// has right and left
                if (*self <= *left && *right <= *left){
                        //printf("swap i")
                        swap(self, left);
                        maxHeapify(heap, leftIndex(i));
                }else if(*self <= *right && *left <= *right){
                        swap(self, right);
                        maxHeapify(heap, rightIndex(i));
                }
        }else if (!left && right){ // has right but not left
                if(*self <= *right){
                        swap(self, right);
                        maxHeapify(heap, rightIndex(i));
                }
        }else if (left && !right){ // has left but not right
                if(*self <= *left){
                        swap(self, left);
                        maxHeapify(heap, leftIndex(i));
                }
        }
}
Heap buildMaxHeap(int * heap, int size){
        Heap h = {.heap = heap, .size = size};
        for(int i = h.size/2; 0 <= i ; i--){
                maxHeapify(h, i);
        }
        return h;
}

int assertMaxHeapProperty(Heap heap){
        for(int i = 0; i < heap.size; i++){
                int * left = getLeft(heap, i);
                int * right = getRight(heap, i);
                int * self = getSelf(heap, i);
                // printf("i: %i \n", i);
                // printf("self: %i, l: %i, r: %i \n",
                //         self ? *self : -1,
                //         left ? *left : -1,
                //         right? *right: -1);
                if (left){
                        if(*self < *left){
                                return 0;
                        }
                }
                if (right){
                        if(*self < *right){
                                return 0;
                        }
                }
        }
        return 1;
}

int assertSorted(int * a, int size){
        int i;
        int temp = INT_MIN;
        for (i = 0; i < size; i++){
                if (a[i] < temp){
                        return 0;
                }
        }
        return 1;
}

void sort(Heap heap){
        int i = heap.size;
        while (heap.size - 1){
                //printf("step  %i\n", heap.size - 1);
                //visualizeArray(heap.heap, i);
                int * top = getSelf(heap, 0);
                int * end = getSelf(heap, heap.size - 1);
                swap(top, end);
                heap.size--;
                maxHeapify(heap, 0);
        }
        heap.size = i;
}
