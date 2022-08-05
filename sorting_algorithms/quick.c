#include <stdio.h>

void print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right,int n)
{
    int pivot = arr[right]; //en sagdaki pivot secildi.
    int i = (left - 1); //en soldaki elemani -1. indexten baslat.

    for (int j = left; j <= right - 1; j++) //pivottan oncekileri dolanarak buyuk/kucuk olarak ayir.
    {
        if (arr[j] < pivot) //pivottan kucukse sola ekle
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
        //print(arr, n); printf("\n");
    }
    swap(&arr[i + 1], &arr[right]); //en son pivotu uygun yere koy.
    //print(arr, n); printf("\n");
    return (i + 1); //pivotun yeni indexini dondur.
}

void quickSort(int arr[], int left, int right, int n)
{
    if (left < right)
    {
        int part_index = partition(arr, left, right, n);
        quickSort(arr, left, part_index - 1, n); //pivottan kücük olanlari sirala
        quickSort(arr, part_index + 1, right, n); //pivottan büyük olanlari sirala
    }
}

int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1, n);
    printf("Sorted array using quick sort: ");
    print(arr, n); printf("\n");

    return 0;
}