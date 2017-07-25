/***
        Eliel Zamora
        6.006
        Insertion Sort

*/

#include <stdio.h>
#include <stdlib.h>

// Main Array
int * A;


void swap(int * a, int * b){
        int temp = *a;
        *a = *b;
        *b = temp;
}
void xorSwap (int *x, int *y) { // cool trick
     if (x != y) {
         *x ^= *y;
         *y ^= *x;
         *x ^= *y;
     }
}
void initRand(){
        srand(time(NULL));
}
int randomNumber(){
        return rand();
}
void displayArray(int * array, int size){
        int i;
        for(i = 0; i < size; i++) {
                printf("%i ",array[i]);
        }
        printf("\n");
}
void visualizeArray(int * array, int size){
        int i = 0;
        int j;
        while(i < size){
                printf("%*i ",5, i);
                printf("*");// add another * for clarity
                for(j = 0; j < array[i]; j++){
                        printf("*");
                }
                printf("\n");
                i++;
        }
}
void createRandomArray(int ** array,int size){
        int i = size;
        *array = (int *) malloc(size * sizeof (int));
        if(*array == NULL) exit(1);
        while(i > 0){
                (*array)[--i] = randomNumber() % 10; // only select one digit
        }
}
void insert(int * array, int last){
        //last is unsorted insert until sorted
        int j = last;
        while(j > 0) {
                if(array[j] < array[j-1]){
                        swap(&array[j], &array[j-1]);
                }
                j--;
        }
        //can optimize for O(nlgn) comparisons and O(n^2) swaps
        //by using binary search to find spot when where to swap to
        //saves in comparisons when they are costly
}
void insertionSort(int * array, int size){
        int i = 0;
        while(i < size){
                insert(array, ++i);
        }
}

int main(int argc, char ** argv){
        initRand();
        int size = 40;
        createRandomArray(&A,size);
        printf("unsorted array: \n\n");
        visualizeArray(A, size);
        insertionSort(A, size);
        printf("\nsorted array: \n\n");
        visualizeArray(A, size);  
        
        
        free(A);
}