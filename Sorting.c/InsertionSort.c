#include<stdio.h>

void Display(int *Arr,int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d  ",Arr[i]);
    }
}

void insertionsort(int *Arr,int size){
    for (int i = 1; i < size - 1; i++)
    {
        
    }
    
}

int main()
{
    int Arr[] = {2,13,19,12,7,98,65};
    int size = sizeof(Arr)/sizeof(int);
    Display(Arr,size);
    return 0;
}