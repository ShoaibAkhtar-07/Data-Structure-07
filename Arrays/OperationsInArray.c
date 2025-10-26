#include<stdio.h>

// Function for Traversal of Array
void travesal(int arr[],int size){
    for(int i = 0; i<size; i++){
        printf("%d  ",arr[i]);
    }
}

//Function for Insertion
int insertion(int arr[],int capacity, int size, int index, int element){
    if(size >= capacity ||index < 0 || index > size){
        return -1;
    }
    else{
        for(int i = size - 1; i >= index; i--){
            arr[i+1] = arr[i];
        }
        arr[index] = element;
        return 1;
    }
}

// Function for Deletion 
int deletion(int arr[],int size, int index){
    if(index < 0 || index >= size){
        return -1;
    }
    else{
        for (int i = index; i < size-1 ; i++){
            arr[i] = arr[i+1];
        }
        return 1;
    }
}

int main()
{
    int arr[50] = {1,2,3,4,5,6};
    int size = 6, capacity = 50;
    printf("Before INSERTION\n");
    travesal(arr,size);
    printf("\n");

    int result = insertion(arr,capacity,size,3,9);
    if(result == 1){
        size ++;
        printf("After INSERTION\n");
        travesal(arr,size);
        printf("\nInsertion successfully done!\n");
    }
    else{
        printf(" error! occured insertion not successful\n");
    };

    printf("\n--Deletion--\n");
    deletion(arr,size,0);
    size--;
    travesal(arr,size);
    return 0;
}