#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void Display(int *Arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", Arr[i]);
    }
    printf("\n");
}

int maximum(int *Arr, int size)
{
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

void CountSort(int *Arr, int size)
{
    int max = maximum(Arr, size);
    int *count = (int *)malloc((max + 1) * sizeof(int));
    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        count[Arr[i]] = count[Arr[i]] + 1;
    }
    int i = 0;
    int j = 0;
    while (i <= max)
    {
        if (count[i] > 0)
        {
            Arr[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int Arr[] = {2, 1, 3, 8, 5, 7, 9, 10};
    int size = sizeof(Arr) / sizeof(Arr[0]);
    Display(Arr, size);
    CountSort(Arr, size);
    Display(Arr, size);
    return 0;
}