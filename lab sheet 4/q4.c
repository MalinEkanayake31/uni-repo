#include<stdio.h>
#include<stdlib.h>

void* concatArrays(void *arr1, int size1, void *arr2, int size2) {
    if (size1 <= 0 && size2 <= 0) {
        return NULL;
    }

    int *result = (int *)malloc((size1 + size2) * sizeof(int));
    if (result == NULL) {
        return NULL;
    }

    int *ptr = result;

    for (int i = 0; i < size1; i++) {
        *ptr++ = *((int *)arr1 + i);
    }

    for (int i = 0; i < size2; i++) {
        *ptr++ = *((int *)arr2 + i);
    }

    return result;
}

int main(){
    int* arr1=NULL;
    int* arr2=NULL;
    int size1,size2;

    printf("Enter the number of elements you want to add for array 1 : \n");
    scanf("%d",&size1);

    arr1=(int*)malloc(size1*sizeof(int));
    if(arr1==NULL){
        printf("memory allocation failed.\n");
        return 0;
    }

    printf("Enter elements for array 1 :\n");
    for(int i=0;i<size1;i++){
        scanf("%d",&arr1[i]);
    }

    printf("Enter the number of elements you want to add for array 2 : \n");
    scanf("%d",&size2);

    arr2=(int*)malloc(size2*sizeof(int));
    if(arr2==NULL){
        printf("memory allocation failed.\n");
        free(arr1);
        return 1;
    }

    printf("Enter elements for array 2 :\n");
    for(int i=0;i<size2;i++){
        scanf("%d",&arr2[i]);
    }

    void *concatenatedArray = concatArrays(arr1, size1, arr2, size2);

    if (concatenatedArray != NULL) {
        int totalSize = size1 + size2;
        printf("Concatenated array: ");
        for (int i = 0; i < totalSize; i++) {
            printf("%d ", *((int *)concatenatedArray + i));
        }
        printf("\n");

        free(concatenatedArray);
    } else {
        printf("Failed to concatenate arrays. Memory allocation failed.\n");
    }

    free(arr1);
    free(arr2);

    return 0;
}