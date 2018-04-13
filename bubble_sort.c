#include <stdio.h>
#include <stdlib.h> // for rand
#include <time.h> // for time

// Better Bubble Sort

/*
*
* Sorts array A[0 .. n-1] by improved bubble sort
* Input: Array A[0 ... n-1] of orderable elements
* Output: Array A[0 ... n-1] sorted in ascending order
*
*/


#define ARRAY_SIZE 1000

int debug = 0; // print switch
clock_t start, finish;
double execution_time;

void sort(int array[]);
void swap(int *first, int *second);
void print_array(int array[]);

void sort(int A[]){

    int count = ARRAY_SIZE - 1; // number of pairs to be compared aka len
    int sflag = 1; // swap flag (bool)

    while(sflag == 1){
        sflag = 0;
        for (int j = 0; j <= (count-1); j++){
            if (A[j + 1] < A[j] ){
                swap(&A[j], &A[j+1]);

                if(debug==1){
                    printf("%d swapped with %d\n", A[j], A[j+1]);
                    print_array(A);
                }
                
                sflag = 1;
            }
        }
    count--;    
    }

}

void swap(int *first, int *second) {
    int temp;

    temp = *first;
    *first = *second;  
    *second = temp;  

}

void print_array(int array[]){
    printf("[ ");
    for(int i = 0; i < ARRAY_SIZE; ++i){
        printf("%d ", array[i]);
    }
    printf("]\n");
}

int check_array(int array[]){
   
    for (int i = 0; i < ARRAY_SIZE-1; i++){
        if (array[i] > array[i+1]){
            if(debug){
                printf("%d is greater than %d\n", array[i], array[i+1]);
            }
            return 0; // not sorted
        }

    }

    return 1; // sorted
}

int main() {
    int A[ARRAY_SIZE];

    // Start the clock
    start = clock();

    // Make a random array
    srand(time(NULL));
    for(int i = 0; i < ARRAY_SIZE; ++i){
        A[i] = rand() % (ARRAY_SIZE*10) + 1; // Random number between 0 and 1000?
    }

    printf("Initial array: \n");
    print_array(A);
    printf("\n");

    sort(A); // Sort the array

    printf("Final array: \n");

    print_array(A);

    if(check_array(A)){
        printf("Successful sorting!\n");
    } else {
        printf("Fail.\n");
    }

    // Stop the clock
    finish = clock();

    execution_time = ((double)(finish - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", execution_time);
}