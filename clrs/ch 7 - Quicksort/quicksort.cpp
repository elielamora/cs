#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>

using namespace std;

inline void swap (int * array, int a, int b){
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

/**
returns the index of the pivot element after the partition
*/

int partition(int * array, int l, int r, int randomize = 0){
    // init vars
    int p = r - 1; // index of the pivot element
    int pivot = array[p];
    int i = l - 1; // index of last elem. < array[p]
    int j = l; // index where i < a < j, array[p] < array[a]
    int c; // temp var to hold value being examined
    // if randomized quicksort is enabled...
    if (randomize){
        int random = (rand() % (r - l)) + l;
        assert(random < r && l <= random);
        swap(array, random, p); // swap pivot and random elem.
    }
    while(j < p){
        c = array[j];
        if (c <= pivot){
            i++;
            swap(array, i, j);
        }
        j++;
    }
    swap(array, i + 1, p);
    return i+1;
}

/**
array is an int array
l is the index of the of the first element to quicksort from
r is the index + 1 of the final index of the array to apply quicksort from
*/
void quicksort(int * array, int l, int r){
    if (l < r){
        int p = partition(array, l, r);
        quicksort(array, l, p + 1);
        quicksort(array, p - 1, r);
    }
}


/// HELPER FUNCTIONS

void printArray(int * array, int n){
    cout << "printing array @" << array;
    for (int i = 0; i < n; i++){
        cout << i << " " << array[i] << "\n";
    }
}


/// TESTS

int testPartition(int * array, int l, int r, int p){
    assert(l <= p && p <= r && l <= r);
    int pivot = array[p];
    int next;
    // elements left of pivot must be less than or equal to
    for (int i = l + 1; i < p; i++){
        next = array[i];
        if (pivot < next)
            return 0;
    }
    // elements right of pivot must be larger
    for (int i = p+1; i < r; i++){
        next = array[i];
        if (next <= pivot)
            return 0;
    }
    return 1;
}

int testSorted(int * array, int l, int r){
    int prev = array[l];
    int next;
    for (int i = l + 1; i < r; i++){
        next = array[i];
        if (next < prev){
            return 0;
        }
    }
    return 1;
}

string testMessage(int boolean){
    return boolean? "Passed!": "FAILED!!! :( ";
}

/**
 *
 *  Main Function
 *
 */
 int main(int argc , char ** argv){
     srand();
     cout << "Quick, quicksort program.\n";
     int length = 10;
     int array[length] = {7, 5, 9, 4, 0, 3, 6, 1, 2, 8};
     cout << "test sorted: ";
         << testMessage(testSorted(array, 0, length)) << "\n";
     printArray(array, length);
     cout << "testing swaping function at index, 0 and 3"
         << "\n";
     swap(array, 0, 3);
     printArray(array, length);
     return 0;
 }
