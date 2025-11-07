#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void Display(int *Arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", Arr[i]);
    }
    printf("\n");
}

int maximum(int *Arr,int size){
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (max < Arr[i])
        {
            max = Arr[i];
        }
        
    }
    return max;
    
}

void CountSort(int *Arr,int size){

}

int main()
{
    int Arr[] =  {2,1,3,8,5,7,9,10};
    
    return 0;
}