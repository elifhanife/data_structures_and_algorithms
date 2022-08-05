#include <stdio.h>
#define MAX_SIZE 101

int stc[MAX_SIZE], top = -1;

void push(int x) {

	if (top == MAX_SIZE - 1) {
		printf("\nNo more elements\n"); //stack is full
		exit(-1);
	}
	else {
		stc[++top] = x;
	}
}

void pop() {
	
	if (top == -1) { //stack is empty
		printf("\nStack is empty");
		exit(-1);
	}
	else {
		top--;
	}
}

int Top() {
	return stc[top];
}

void IsEmpty() {

	if (top == -1) { //stack is empty
		printf("true");
	}
	else {
		printf("false");
	}
}

void print() {

	printf("STACK: ");
	for (int i = 0; i <= top; i++) {
		printf("%d ", stc[i]);
	}
	printf("\n");
}


int main() {

	//IsEmpty();
	//pop(); print();
	push(2); print();
	push(5); print();
	push(10); print();
	printf("Top= %d\n ", Top()); print();
	pop(); print();
	printf("Top= %d\n ", Top()); print();
	IsEmpty();

}


