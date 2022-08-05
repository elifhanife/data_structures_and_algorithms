#include <stdio.h>
#include <time.h>

//{'2',1,2,5,'5',5,'2',1} listesindeki elemanlarin kac kez tekrar ettigini bulup ekrana yazdiran kod.

clock_t clock(void);

struct Node {
	int data;
	struct Node* next;
};

int char2 = 0, int1 = 0, int2 = 0, int5 = 0, char5 = 0;

void print_tekrar() {
	printf(" %d adet '2'\n ", char2);
	printf("%d adet 1\n ", int1);
	printf("%d adet 2\n ", int2);
	printf("%d adet 5\n ", int5);
	printf("%d adet '5'\n ", char5);
}


void rec_again(struct Node* temp) {//recursive sekilde tekrar sayisini bulma

	int char2 = 0, int1 = 0, int2 = 0, int5 = 0, char5 = 0;

	while (temp != NULL) {
		if (temp->data == '2') {
			char2++;
		}
		else if (temp->data == '5') {
			char5++;
		}
		else if (temp->data == 1) {
			int1++;
		}
		else if (temp->data == 2) {
			int2++;
		}
		else if (temp->data == 5) {
			int5++;
		}
		temp = temp->next;
		rec_again(temp);
	}
		//print_tekrar();
}



void again(struct Node* temp) {//iterative sekilde tekrar sayisini bulma.

	while (temp != NULL) {

		if (temp->data == '2') {
			char2++;
		}
		else if (temp->data == '5') {
			char5++;
		}
		else if (temp->data == 1) {
			int1++;
		}
		else if (temp->data == 2) {
			int2++;
		}
		else if (temp->data == 5) {
			int5++;
		}

		temp = temp->next;
	}

	print_tekrar();
}


int main() {

	clock_t start_t,end_t;
	int id;

	struct Node* temp = NULL;

	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	struct Node* fourth = NULL;
	struct Node* fifth = NULL;
	struct Node* sixth = NULL;
	struct Node* seventh = NULL;
	struct Node* eighth = NULL;

	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	fourth = (struct Node*)malloc(sizeof(struct Node));
	fifth = (struct Node*)malloc(sizeof(struct Node));
	sixth = (struct Node*)malloc(sizeof(struct Node));
	seventh = (struct Node*)malloc(sizeof(struct Node));
	eighth = (struct Node*)malloc(sizeof(struct Node));

	head->data = '2';
	head->next = second;

	second->data = 1;
	second->next = third;

	third->data = 2;
	third->next = fourth;

	fourth->data = 5;
	fourth->next = fifth;

	fifth->data = '5';
	fifth->next = sixth;

	sixth->data = 5 ;
	sixth->next = seventh;

	seventh->data = '2';
	seventh->next = eighth;

	eighth->data = 1;
	eighth->next = NULL;

	temp = head;
	
	start_t = clock();
	again(temp);
	end_t = clock();
	printf("iterative islem suresi: %f\n",(double)(end_t-start_t));

	start_t = clock();
	rec_again(temp);
	print_tekrar();
	end_t = clock();
	printf("recursive islem suresi: %f\n", (double)(end_t - start_t));



}