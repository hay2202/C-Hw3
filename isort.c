#include <stdio.h>

#define N 50

void shift_element(int *arr, int i){
    int temp=0;
    while(i > 0){
        temp = *(arr+(i-1));
        *(arr+i)=temp;
        i--;
    }
}


void insertion_sort(int *arr, int len){
    for(int i=1; i<len ; i++){
        int j = i-1;
        int temp = *(arr+i);
        int count=0;

        while(temp < *(arr+j) && j>=0){
            count++;
            j--;
        }
        shift_element(arr+(j+1),count);
        *(arr+(j+1)) = temp;
    }
}


int main(){
    int arr [N];

    printf("insert 50 integers:\n");
    for (size_t i = 0; i < N ; i++)
    {
        scanf("%d", (arr+i));
    }

    insertion_sort(arr,N);
    for (size_t i = 0; i < N ; i++)
    {
        printf("%d,",*(arr+i));
    }
    return 0;
}

