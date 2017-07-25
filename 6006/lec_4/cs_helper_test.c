#include "cs_helper.h"
#include <stdio.h>

int main(int argc, char ** argv){
        printf("unit test for cs_helper\n");
        printf("testing: swap(int *, int *)\n");
        int a = 5;
        int b = 8;
        printf("before swap: a = %i, b = %i\n", a, b);
        swap(&a, &b);
        printf("after swap: a = %i, b = %i\n", a, b);
        printf("testing: initRand and randomNumber\n");
        initRand();
        for(int i = 0; i < 5; i++){
                printf("randomNumber = %i\n", randomNumber());
        }
        printf("testing: visualizeArray and createRandomArray\n");
        int * array;
        createRandomArray(&array, 25);
        visualizeArray(array, 25);

        return 0;
}
