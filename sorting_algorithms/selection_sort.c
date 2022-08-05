#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int temp = 0, min_index = 0;
clock_t start_t, end_t;

void print_array(int arr[], int arr_size) {
	for (int i = 0; i < arr_size; i++) {
		printf("%d ", arr[i]);
	}
}

void recur_selection(int arr[],int arr_size,int i) {

	//int i = 0;
	min_index = i;
	for (int j = i + 1; j < arr_size; j++) {
		if (arr[j] < arr[min_index]) {
			min_index = j;
		}
	}
	temp = arr[i];
	arr[i] = arr[min_index];
	arr[min_index] = temp;

	printf("SWAP: ");
	print_array(arr, arr_size);
	printf("\n");

	if (++i < arr_size) {
		recur_selection(arr,arr_size,i);
	}

}

void iter_selection(int arr[], int arr_size) {

	for (int i = 0; i < arr_size - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < arr_size; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
		
		printf("SWAP: ");
		print_array(arr, arr_size);
		printf("\n");
	}

}


int main() {

   //srand(time(NULL)); //for different numbers
	
	int arr[20],temp_arr[20];
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	int temp_arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("SIRASIZ: ");
	for (int i = 0; i < 20; i++) {
		arr[i] = rand() % 101;
		printf("%d ", arr[i]);
	}
	printf("\n");


	start_t = clock();
	iter_selection(arr, arr_size);
	end_t = clock();
	printf("\n");
	printf("ITER SURE (s): %f\n",(double)(end_t-start_t)/CLOCKS_PER_SEC);
	printf("\n");

	printf("SIRASIZ: ");
	for (int i = 0; i < 20; i++) {
		temp_arr[i] = rand() % 101;
		printf("%d ", temp_arr[i]);
	}
	printf("\n");

	start_t = clock();
	recur_selection(temp_arr, temp_arr_size, 0);
	end_t = clock();
	printf("\n");
	printf("RECUR SURE (s): %f\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);

}