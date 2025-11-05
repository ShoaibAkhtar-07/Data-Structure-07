#include <stdio.h>

void Display(int *Arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", Arr[i]);
    }
    printf("\n");
}

int partition(int *Arr, int lb, int ub)
{
    int temp;
    int pivot = Arr[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (Arr[start] <= pivot)
        {
            start++;
        }
        while (Arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            temp = Arr[start];
            Arr[start] = Arr[end];
            Arr[end] = temp;
        }
    }
    temp = Arr[lb];
    Arr[lb] = Arr[end];
    Arr[end] = temp;
    return end;
}

void QuickSort(int *Arr, int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(Arr, lb, ub);
        QuickSort(Arr, lb, loc - 1);
        QuickSort(Arr, loc + 1, ub);
    }
}

int main()
{
    int Arr[] = {12, 32, 41, 52, 3, 24, 52, 8};
    int lowerBond = 0;
    int upperBond = (sizeof(Arr) / sizeof(int)) - 1;

    printf("-----Before QUICK Sorting------\n");
    Display(Arr, upperBond + 1);

    QuickSort(Arr, lowerBond, upperBond);

    printf("-----After Quick Sorting---\n");
    Display(Arr, upperBond + 1);
    return 0;
}