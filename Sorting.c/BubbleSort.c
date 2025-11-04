#include <stdio.h>
void printArray(int *Arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", Arr[i]);
    }
    printf("\n");
}

void BubbleSort(int *Arr, int size)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < size - 1; i++)
    {
        printf("passes count : %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
     int Arr[] = {7, 24, 2, 6, 45, 88, 43};
    // int Arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(Arr) / sizeof(int);
    printf("----Before Sorting----\n");
    printArray(Arr, size);
    printf("---After Sorting---\n");
    BubbleSort(Arr, size);
    printArray(Arr, size);
    return 0;
}