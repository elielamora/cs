/**
        Eliel Amora
        6.006 Intro to Algorithms
        Peak finding in a 1d array

*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initRand();
int randomNumber();
void displayArray(int * array, int size);
void visualizeArray(int * array, int size);
void createRandomArray(int size);
int findPeakN(int * array, int size);
int findPeakLgN(int * array, int size, int l, int r);
int * A;

int main(int argc, char ** argv){
        //init
        initRand();
        int size = 10;
        if(argc == 2){
                sscanf(argv[1],"%i", &size);
        }else if(argc > 2){
                printf("too many args\n");
        }
        printf("the size of the array is %i \n\n", size);
        createRandomArray(size);
        //displayArray(A, size);
        visualizeArray(A, size);
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
void createRandomArray(int size){
        int i = size;
        A = malloc(size * sizeof (int));
        if(A == NULL) exit(1);
        while(i > 0){
                A[--i] = randomNumber() % 10; // only select one digit
        }
}
int findPeakN(int * array, int size){
        //assert that size is greater than 2
        int i;
        for(i = 1; i < size-1; i++){
                if(array[i-1] < array[i] && array[i+1] < array[i]){
                        return i;
                }
        }
}
//TODO remove size as it is redundant
int findPeakLgN(int * array, int size, int l, int r){
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
