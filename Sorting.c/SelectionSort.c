#include <stdio.h>

void Display(int *Arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", Arr[i]);
    }
    printf("\n");
}

void SelectionSort(int *Arr, int size)
{
    int indexofmin, temp;
    for (int i = 0; i < size - 1; i++)
    {
        indexofmin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (Arr[j] < Arr[indexofmin])
            {
                indexofmin = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[indexofmin];
        Arr[indexofmin] = temp;
    }
}

int main()
{
    int Arr[] = {1, 3, 564, 653, 24, 85, 82};
    int size = sizeof(Arr) / sizeof(int);
    printf("--Before SELECTION Sorting---\n");
    Display(Arr, size);
    printf("--AFTER SELECTION Sorting---\n");
    SelectionSort(Arr, size);
    Display(Arr, size);
    return 0;
}