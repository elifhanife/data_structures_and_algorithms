#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

int hash[SIZE] = { NULL };

void insert(int key) {

	int index, flag = 0, hash_key, hash2_key;

	hash_key = key % SIZE;
	hash2_key = 5 - (key % 5);

	for (int i = 0; i < SIZE; i++) {

		index = (hash_key + i * hash2_key) % SIZE;

		if (hash[index] == NULL) {
			hash[index] = key;
			break;
		}
		else {
			printf("Cakisma-%d!--> %d at index: %d\n", i+1, key, index);
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

	int arr[7] = { 701,145,217,19,13,749 };

	for (int i = 0; i < SIZE; i++) {

		if (arr[i] != NULL) {
			printf("\nSTEP %d: %d\n", i + 1, arr[i]);
			insert(arr[i]);
			print();
		}
		else {
			printf("\nSTEP %d: SON DURUM\n", i + 1);
			print();
		}
	}

}