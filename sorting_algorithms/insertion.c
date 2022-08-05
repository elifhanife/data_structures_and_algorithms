#include <stdio.h>
#include <time.h>

clock_t start_t1, end_t1, start_t2, end_t2, start_t3, end_t3;

void print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertionSort(int arr[], int n)
{
    int i, key, j, counter=1;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {//key den oncekilere bak, key i uygun yere koy.
            arr[j + 1] = arr[j];
            j = j - 1;
            counter++;
        }
        arr[j + 1] = key;
        counter++;
        //printf("Step-%d: ", i); print(arr, n);
    }
    printf("\nNumber of steps: %d ", counter); printf("\n");
}

int main()
{
    int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int arr2[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int arr3[] = { 3, 7, 5, 10, 1, 9, 6, 2, 8, 4 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    start_t1 = clock();
    printf("1-Sorted array using insertion sort: ");
    insertionSort(arr1, n1);
    print(arr1, n1);
    end_t1 = clock();

    printf("Time(s) for Dizi1 array: %f\n", (double)(end_t1 - start_t1) / CLOCKS_PER_SEC);

    start_t2 = clock();
    printf("\n2-Sorted array using insertion sort: ");
    insertionSort(arr2, n2);
    print(arr2, n2);
    end_t2 = clock();

    printf("Time(s) for Dizi2 array: %f\n", (double)(end_t2 - start_t2) / CLOCKS_PER_SEC);

    start_t3 = clock();
    printf("\n3-Sorted array using insertion sort: ");
    insertionSort(arr3, n3);
    print(arr3, n3);
    end_t3 = clock();

    printf("Time(s) for Dizi3 array: %f\n", (double)(end_t3 - start_t3) / CLOCKS_PER_SEC);
    
    return 0;
}