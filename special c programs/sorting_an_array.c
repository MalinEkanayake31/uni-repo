#include<stdio.h>

int main(){
    int arr[10];
    for(int i=0;i<10;i++){
        printf("enter a number ");
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<10;i++){
        printf("%d  ",arr[i]);
    }
}
