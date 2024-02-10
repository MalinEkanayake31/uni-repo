#include<stdio.h>
#include<stdlib.h>

void* removeDuplicates(void* arr, int* size) {
    int* input = (int*)arr;
    int newSize = 0;

    for (int i = 0; i < *size; i++) {
        int j;
        for (j = 0; j < newSize; j++) {
            if (input[i] == input[j]) {
                break;
            }
        }
        if (j == newSize) {
            input[newSize++] = input[i];
        }
    }

    *size = newSize;
    return input;
}

int main(){
    int* arr;
    int size;

    printf("Enter the number of integers to input : \n");
    scanf("%d",&size);

    arr=(int*)malloc(size*sizeof(int));
    if(arr==NULL){
        printf("memory allocation failed.\n");
        return 0;
    }

    printf("Enter %d integers :\n",size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    void* result = removeDuplicates(arr,&size);

    printf("Array after removing duplicates: ");
    for (int i=0;i<size;i++) {
        printf("%d ",*((int*)result+i));
    }
    printf("\n");

    free(result);
}