#include "cs_helper.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int * a, int * b){
        int temp = *a;
        *a = *b;
        *b = temp;
}
void initRand(){
        srand(time(NULL));
}
int randomNumber(){
        return rand();
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
void createRandomArray(int ** array, int size){
        int i = size;
        *array = (int *) malloc(size * sizeof (int));
        if(*array == NULL) exit(1);
        while(i > 0){
                (*array)[--i] = randomNumber() % 10; // only select one digit
        }
}
