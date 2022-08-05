#include <stdio.h>
#include <stdlib.h>


void print(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
} 

void merge(int arr[], int left, int middle, int right)
{
    int i, j, k, left_subarray[10], right_subarray[10], left_size, right_size;
    left_size = middle - left + 1;
    right_size = right - middle;
   

    for (i = 0; i < left_size; i++)
        left_subarray[i] = arr[left + i];
    for (j = 0; j < right_size; j++)
        right_subarray[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < left_size && j < right_size) {
        if (left_subarray[i] <= right_subarray[j]) {
            arr[k] = left_subarray[i];
            i++;
        }
        else {
            arr[k] = right_subarray[j];
            j++;
        }
        k++;
    }

     while (i < left_size) {
         arr[k] = left_subarray[i];
         i++;
         k++;
     }
     while (j < right_size) {
         arr[k] = right_subarray[j];
         j++;
         k++;
     }
     
}

void mergeSort(int arr[], int left, int right)
{

  if (left < right) {
        int middle = (left + right) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
    
}

int kucuktur[5], eleman = 0;
int main()
{
    int arr[] = { 8, 5, 9, 4, 2, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int array_kucuk[4];
    int array_size = sizeof(array_kucuk) / sizeof(array_kucuk[0]);

    for (int i = 0; i < arr_size; i++) {
        eleman = 0;
        printf("%d' den kucuk: ", arr[i]);
        int a = 0;
        for (int j = i+1; j < arr_size; j++) {
            if (arr[i] > arr[j]) {
                eleman++;
                kucuktur[i] = eleman;
                array_kucuk[a] = arr[j];
                a++;
            } 
        }
        print(array_kucuk, eleman);
    }
    mergeSort(kucuktur, 0, arr_size - 1);

    printf("\nSorted array B is: "); //4,2,3,1,0 
    print(kucuktur, arr_size);
    printf("\n");
    return 0;
}