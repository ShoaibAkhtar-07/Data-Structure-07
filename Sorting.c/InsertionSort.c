#include <stdio.h>

void Display(int *Arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", Arr[i]);
    }
    printf("\n");
}

void insertionsort(int *Arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = Arr[i];
        int j = i - 1;
        while (Arr[j] > temp && j >= 0)
        {
            Arr[j + 1] = Arr[j];
            j--;
        }
        Arr[j + 1] = temp;
    }
}

int main()
{
    int Arr[] = {2, 13, 19, 12, 7, 98, 65};
    int size = sizeof(Arr) / sizeof(int);
    Display(Arr, size);
    insertionsort(Arr,size);
    Display(Arr, size);
    return 0;
}