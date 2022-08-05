#include <stdio.h>
#include <stdlib.h>


struct Node {
	int data;
	struct Node* next;
};

struct Node* min;
struct Node* temp;

struct Node* head = NULL;
struct Node* second = NULL;
struct Node* third = NULL;


struct Node* find_min(struct Node* head) {

	while (temp->next != NULL) {

		if (temp->next->data < temp->data) {
			min = temp->next;
			temp->next = min->next;
			min->next = temp;
		}
		temp = temp->next;
		find_min(temp);
	}
	return min;
}

void print_list(struct Node* head) {
	while (head != NULL) {

		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int main() {


	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

	head->data = 7;
	head->next = second;

	second->data = 1;
	second->next = third;

	third->data = 9;
	third->next = NULL;

	printf("Baslangictaki liste: ");
	print_list(head);

	temp = head;
	head = find_min(temp);

	printf("Son liste: ");
	print_list(head);
}