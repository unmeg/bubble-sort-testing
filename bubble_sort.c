#include <stdio.h>

// Better Bubble Sort

/*
*
* Sorts array A[0 .. n-1] by improved bubble sort
* Input: Array A[0 ... n-1] of orderable elements
* Output: Array A[0 ... n-1] sorted in ascending order
*
*/


#define ARRAY_SIZE 10
void swap(int *first, int *second);

void sort(int array[], int size){

    int count = n - 1; // number of pairs to be compared aka len
    int sflag = 1; // swap flag (bool)

    while(sflag == 1){
        sflag = 0;
        for (int j = 0; j < (count-1); j++){
            if (A[j + 1] < A[j] ){

                sflag = 1;
            }
        }
    count--;    
    }

}

for (int i = 0; i < arraySize; i++) {
    for (int j = 0; j < (arraySize - 1); j++) {
      if (array[j] > array[j + 1]) {
        /*********** This line was changed ***********/
        swap(&array[j+1], &array[j]); // You were earlier swapping ith and jth entries.
        /*********************************************/
      }
    }
  }
  //Print out sorted
