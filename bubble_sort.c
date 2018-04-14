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
#define NUM_EXPERIMENTS 50

int debug = 0; // print switch
uint swap_count = 0; // keep track of swaps
uint comp_count = 0; // keep track of swaps
double execution_time = 0;
void sort(int array[]);
void swap(int *first, int *second);
void print_array(int array[]);
void run_experiment(int type);

void sort(int A[]){

    int count = ARRAY_SIZE - 1; // number of pairs to be compared aka len
    int sflag = 1; // swap flag (bool)

    while(sflag == 1){
        sflag = 0;
        for (int j = 0; j <= (count-1); j++){
            if (A[j + 1] < A[j] ){
                comp_count++; // track comparison
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
    
    swap_count++; // count swaps

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

void run_experiment(int type){
    int A[ARRAY_SIZE];
    clock_t start, finish;

    // Make a random array
    switch(type){
        case 1: // random

            srand(time(NULL));
            
            for(int i = 0; i < ARRAY_SIZE; ++i){
                A[i] = rand() % (ARRAY_SIZE*10) + 1; // Random number between 0 and 1000?
            }

            break;

        case 2: // ordered

            for(int i = 0; i < ARRAY_SIZE; ++i){
                A[i] = i + 1; // Sequence of numbers
            }

            break;
        
        case 3: // reverse-ordered

            for(int i = 0; i < ARRAY_SIZE; ++i){
                A[i] = ARRAY_SIZE - i; // Sequence of numbers
            }

            break;

        
    }
    
    if(debug){
        printf("Initial array: \n");
        print_array(A);
        printf("\n");
    }
    
    // Start the clock
    start = clock();

    sort(A); // Sort the array

    // Stop the clock
    finish = clock();

    execution_time = execution_time + ((double)(finish - start)) / CLOCKS_PER_SEC;

    if(debug){
        printf("Final array: \n");
        print_array(A);
    }
    
    if(check_array(A)){
        printf("Successful sorting!\n");
    } else {
        printf("Failed to sort.\n");
    }
}

int main(int argc, char *argv[]) {
    double average;
    int counter = NUM_EXPERIMENTS;
    int type = 1;
    char *p;

    if(argc != 1){
        type = strtol(argv[1], &p, 10); // takes CL input and converts to string
        if(type > 3){
            printf("Command line argument too big.\n\n./bs <type> is the syntax.\n\n");
            exit(0);
        }
    }

    for (int experiments = 0; experiments < NUM_EXPERIMENTS; experiments++){

        if(debug){
            printf("Experiment %d..", experiments);
            counter++;
        }

        run_experiment(type);
        
    }   
    
    average = execution_time / NUM_EXPERIMENTS; // gives us average execution time

    printf("Average execution time after %d trials: %f seconds\n", counter, average);
    printf("Swaps: %d\n", swap_count/NUM_EXPERIMENTS);
    printf("Comps: %d\n", comp_count/NUM_EXPERIMENTS);

}