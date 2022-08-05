#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

int hash[SIZE] = { NULL };

void insert(int key) {

	int index, flag = 0, hash_key;

	hash_key = key % SIZE;

	for (int i = 0; i < SIZE; i++) {

		index = (hash_key + i*i) % SIZE;

		if (hash[index] == NULL) {
			hash[index] = key;
			break;
		}

		if (i == SIZE) {
			printf("\nCANNOT BE INSERTED\n");
		}
	}
}

void search(int key) {

	int index, i, flag = 0, hash_key;
	hash_key = key % SIZE;

	for (int i = 0; i < SIZE; i++) {

		index = (hash_key + i*i) % SIZE;

		if (hash[index] == key) {
			printf("value is found at index %d", index);
			break;
		}

		if (i == SIZE) {
			printf("\nvalue is not found\n");
		}
	}
}


void print() {

	printf("INDEX\tVALUE\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d\t", i);
		printf("%d\n", hash[i]);
	}

}

int main() {

	int arr[7] = { 50,700,76,85,92,73,101 };

	for (int i = 0; i < SIZE; i++) {
		printf("\nSTEP %d: %d\n\n", i + 1, arr[i]);
		insert(arr[i]);
		print();
	}

	//print();


}