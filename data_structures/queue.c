#include <stdio.h>
#define SIZE 10
#define true 1
#define false 0

typedef struct {
	int value;
}element;

element queue[SIZE];
//stc[] is an array created to implement of stack
//value is an element user wants to add
//bool_value is the value of the function enqueue's returns
int i,front = -1, rear = -1, value, bool_value, top = -1, stc[SIZE];

void push(int x) {

	if (top == SIZE - 1) {
		printf("\nNo more elements\n"); //stack is full
		return;
	}
	else {
		stc[++top] = x;
	}
}

int pop() {

	if (top == -1) { //stack is empty
		printf("\nStack is empty");
		return;
	}
	/*else {
		top--;
	}*/
	return stc[--top];
}

void print() {//print stack

	printf("STACK: ");
	for (i = 0; i <= top; i++) {
		printf("%d ", stc[i]);
	}
	printf("\n");
}


void print_queue() {

	if (front == -1 && rear == -1) { //there are no elements in the queue
		printf("\nThe queue is empty!\n\n");
	}
	else {
		printf("QUEUE: ");
		for (i = front; i <= rear; i++) {
			printf("%d ", queue[i].value);
		}
		printf("\n");
	}

}

int enqueue(int value) {

	if (rear == SIZE - 1) { //there is no more space to add in the queue
		return 0;
	}
	else if (rear == -1 && front == -1) {
		front = 0;
		rear = 0;
	}
	else {
		rear++;
	}
	queue[rear].value = value;
	return 1;
}

int dequeue() {

	if (rear == -1 && front == -1) { //there are no elements to remove from the queue
		return;
	}
	/*else {
		front++;
	}*/
	return queue[front++].value;
}

void Options(int number) {

	switch (number) {
	case 0: //print all elements in the queue
		print_queue();
		break;
	case 1: //add an element into the queue
		printf("Enter the value to add: "); 
		scanf("%d", &value);
		for (i = front; i <= rear; i++) {
			if (value < queue[i].value) { 
				push(dequeue()); 
				//print(); //print stack
			}
		};
		bool_value = enqueue(value);
		for (i = 0; i <= top; i++) {
			enqueue(pop());
		};
		break;
	case 2: //remove element from the queue
		dequeue();
		break;
	case 3: //exit directly
		return;
		break;
	default:
		printf("INVALID OPTION\n");
		break;
	}
}


int main() {

	int number;
	do {
		printf("OPTION:"); 
		scanf("%d", &number);
		Options(number);
		if (number == 1) {
			if (bool_value == true) {
				printf("The element has been successfully added!\n\n");
			}
			else if (bool_value == false) {
				printf("The element adding is failed!\n\n");
			}
		}
	} while (number != 3);

	return 0;
}
