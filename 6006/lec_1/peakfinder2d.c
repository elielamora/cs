/**
        Eliel Zamora
        6.006 Intro to Algorithms
        Peak finding in 2d
        * Not completed
*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initRand();
int randomNumber();
void displayMatrix(int ** M, int n, int m);
void visualizeArray(int * array, int size);
void createRandomArray(int size);
int findPeakN(int * array, int size);
int findPeakLgN(int * array, int size, int l, int r);
int ** A; // matrix

int main(int argc, char ** argv){
        //init
        initRand();
        int n = 8;
        int m = 8;
        if(argc == 2){
                sscanf(argv[1],"%i", &size);
        }else if(argc > 2){
                printf("too many args\n");
        }
        printf("the size of the array is %i \n\n", size);
        createRandomArray(size); 
        displayArray(A, size);
        printf("%i is a peak found by O(n)\n",findPeakN(A, size));
        printf("%i is a peak found by O(lg(n))\n",
                findPeakLgN(A, size, 0, size));
        // lastly
        free(A);
}
void initRand(){
        srand(time(NULL));
}
int randomNumber(){
        return rand();
}
void displayMatrix(int * array, int size){
        int i;
        for(i = 0; i < size; i++) {
                printf("%i ",array[i]);
        }
        printf("\n");
}
void createRandomMatrix(int row, int col){
        int i = size;
        A = malloc(size * sizeof (int));
        if(A == NULL) exit(1);
        while(i > 0){
                A[--i] = randomNumber() % 10; // only select one digit
        }
}
int findPeakGreedy(int * array, int size){
        //assert that size is greater than 2
        int i;
        for(i = 1; i < size-1; i++){
                if(array[i-1] < array[i] && array[i+1] < array[i]){
                        return i;
                }
        }
}
//TODO remove size as it is redundant
int findPeakNLgM(int * array, int size, int l, int r){
        int mid;
        mid = (int) ((l+r)/2);
        if(array[mid] < array[mid-1]){
                return findPeakLgN(array, size, l, mid);
        }else if(array[mid] < array[mid+1]){
                return findPeakLgN(array, size, mid+1, r);
        }else{
                return mid;
        }
        
}

