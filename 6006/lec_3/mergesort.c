/***
        Eliel Amora
        6.006
        Insertion Sort

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
void merge(int * array, int l, int mid, int r){
        int n = mid-l;
        int m = r-mid;
        int i, j, k;
        //printf("n: %i   m: %i\n", n, m);
        int * a = (int *) malloc((n+1) * sizeof(int));
        int * b = (int *) malloc((m+1) * sizeof(int));
        if(a == NULL || b == NULL) exit(1);
        //init the array a
        for(i = l; i < mid; i++){
                a[i-l] = array[i];
        }
        a[n] = INT_MAX;// sentinel so other half is always smaller.
        for(j = mid; j < r; j++){
                b[(j-mid)] = array[j];
        }
        b[m] = INT_MAX;// sentinel same idea as above
        //printf("debug merge\n\n");
        //visualizeArray(a, n+m+2);
        //merge
        i = 0;
        j = 0;
        for(k = l; k < r; k++){
                //printf("i: %i j: %i k: %i\n", i, j, k);
                if(a[i] < b[j]){
                        array[k] = a[i++];
                }else {
                        array[k] = b[j++];
                }
                //printf("press enter\n");
                //c = getc(stdin);
        }
        free(a);
        free(b);
}
void mergeSort(int * array, int l, int r){
        int mid = (int) ((l+r)/2);
        if(l==mid){
                //merge(array, l, mid, r);
                return;
        }
        //printf("l: %i r: %i \n", l, r);
        mergeSort(array, l, mid);
        mergeSort(array, mid, r);
        merge(array, l, mid, r);
}

int main(int argc, char ** argv){
        initRand();
        int size = 12;
        if(argc == 2){
                //printf("argc == 2");
                sscanf(argv[1],"%i", &size);
        }
        createRandomArray(&A,size);
        printf("unsorted array: \n\n");
        visualizeArray(A, size);
        //displayArray(A, size);
        mergeSort(A, 0, size);
        printf("\nsorted array: \n\n");
        //displayArray(A, size);
        visualizeArray(A, size);
        free(A);
}
