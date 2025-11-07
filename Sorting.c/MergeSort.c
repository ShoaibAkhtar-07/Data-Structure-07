#include <stdio.h>

void Display(int *Arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", Arr[i]);
    }
    printf("\n");
}

void Merge(int *A, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[20];
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            k++;
            i++;
        }
        else
        {
            B[k] = A[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void MergeSort(int *Arr, int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high)
    {
        MergeSort(Arr, low, mid);
        MergeSort(Arr, mid + 1, high);
        Merge(Arr, low, mid, high);
    }
}

int main()
{
    int A[] = {2, 16, 41, 52, 141, 131, 22};
    int size = sizeof(A) / sizeof(int);
    Display(A, size);
    MergeSort(A, 0, size - 1);
    Display(A, size);
    return 0;
}