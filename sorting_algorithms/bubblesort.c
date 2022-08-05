#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {

	int arr[] = { -2,45,0,11,-9 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	int temp = 0;

	for (int step = 0; step < arr_size - 1; step++) {
		for (int i = 0; i < arr_size-(step+1); i++) {
			if (arr[i] > arr[i + 1]) {// < yaparsam azalan sirali(descending) siralar.
				//swap
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}

	printf("ARTAN SIRALI: ");
	for (int i = 0; i < arr_size; i++) {
		printf("%d ", arr[i]);
	}

}