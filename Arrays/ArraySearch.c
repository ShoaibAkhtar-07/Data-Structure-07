#include<stdio.h>

int LinearSearch(int arr[],int size,int element){
    for(int i = 0; i < size; i++){
        if(arr[i]==element){ 
            return i;
        }
    }
    return -1;
}

int BinarySearch(int arr[],int size,int element){
    int low, mid, high;
    low = 0;
    high = size - 1;
    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid] < element){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}


int main()
{
    int arr[] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150};
    int size = (sizeof(arr)/sizeof(int));
    int element = 120;
    // int searchInd = LinearSearch(arr,size,element);
    // printf("The element %d was found at index %d\n",element, searchInd);
    
    int searchInd = BinarySearch(arr,size,element);
    printf("The element %d was found at index %d\n",element, searchInd);
    return 0;
}