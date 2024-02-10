#include<stdio.h>
#include<stdlib.h>

int main(){
    // Declaration and initialization of variables
    int* integers=NULL; // Pointer to integers initialized as NULL
    int size=0; // Current size of the array
    int index=0; // Index to track the position of the last input element
    int capacity=1; // Capacity of the dynamically allocated array
    int input; // Variable to store user input

    // Memory allocation for the initial array of capacity 1
    integers=(int*)malloc(capacity*sizeof(int));

    // Checking if memory allocation was successful
    if(integers==NULL){
        printf("Memory allocation failed.\n");
        return 0; // Exiting the program
    }

    // Prompting the user to input integers
    printf("Input integers : \n");

    // Loop to input integers until -1 is entered
    while (1)
    {
        scanf("%d",&input);

        if(input==-1){
            break; // Exiting the loop if -1 is entered
        }

        // If the index reaches the capacity, double the capacity by reallocating memory
        if(index == capacity){
            capacity*=2;
            int* temp = (int*)realloc(integers, capacity * sizeof(int));
            if (temp == NULL) {
                printf("Memory reallocation failed.\n");
                free(integers); // Freeing previously allocated memory
                return 1; // Exiting the program
            }
            integers = temp; // Reassigning the pointer to the newly allocated memory
        }

        integers[index++] = input; // Storing the input integer at the current index
    }

    // Printing the entered integers in reverse order
    printf("Entered integers in reverse order:\n");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d ",integers[i]);
    }
    printf("\n");

    free(integers); // Freeing dynamically allocated memory

    return 0; // Exiting the program
}

