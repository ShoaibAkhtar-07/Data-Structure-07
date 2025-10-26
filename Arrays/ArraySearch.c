#include<stdio.h>

int LinearSearch(int arr[],int size,int element){
    for(int i = 0; i < size; i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}



int main()
{
    int arr[50] = {3,21,43,233,34,87,75,69,77,11,99,60,40,55};
    int size = (sizeof(arr)/sizeof(int));
    int element = 69;
    int searchInd = LinearSearch(arr,size,element);
    printf("The element %d was found at index %d\n",element, searchInd);
    return 0;
}