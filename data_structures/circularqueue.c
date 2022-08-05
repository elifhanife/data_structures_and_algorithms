#include <stdio.h>
#define MAX_SIZE 10

int n=10, front = -1, rear = -1, A[MAX_SIZE];

void enqueue(int x) {

	if (front == -1 && rear == -1) { //queue is empty
		front = 0;
		rear = 0;
	}

    else if ((rear + 1) % n == front) { //queue is full
		return;
	}

	else {
		rear = (rear + 1) % n;
	}
	A[rear] = x;
}

void dequeue() {

	if (front == -1 && rear == -1) {//queue is empty
		return;
	}
	else if (front == rear) { //queue is full
		front = -1;
		rear = -1;
	}
	else {
		front = (front + 1) % n;
	}
}

void print() {

		printf("QUEUE: ");

		for (int i = front; i <= rear; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
}

int main() {

     enqueue(7); print();
	 enqueue(3); print();
	 enqueue(1); print();
	 enqueue(9); print();
	 enqueue(10); print();
	 enqueue(4); print();
	 enqueue(6); print();
	 enqueue(2); print();
	 enqueue(15); print();
	 enqueue(18); print();
	 dequeue(); print();
	 dequeue(); print();
	
	 printf("%d\n", rear);
	 printf("%d", front);

}