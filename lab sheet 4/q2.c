#include<stdio.h>
#include<stdlib.h>

int main(){
    int* integers=NULL;
    int size=0;
    int index=0;
    int capacity=1;
    int input;

    integers=(int*)malloc(capacity*sizeof(int));

    if(integers==NULL){
        printf("memory allocation failed.\n");
        return 0;
    }

    printf("Input integers : \n");

    while (1)
    {
        scanf("%d",&input);

        if(input==-1){
            break;
        }

        if(index == capacity){
            capacity*=2;
            int* temp = (int*)realloc(integers, capacity * sizeof(int));
            if (temp == NULL) {
                printf("Memory reallocation failed.\n");
                free(integers);
                return 1;
            }
            integers = temp;
        }

        integers[index++] = input;
    }
    printf("Entered integers in reverse order:\n");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d ",integers[i]);
    }
    printf("\n");

    free(integers);

    return 0;
}