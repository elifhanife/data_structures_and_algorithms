#include <stdio.h>
#define MAX_SIZE 10

void readMatrix(int alt[],int n) {

	int i, j, k;

	if (n*(n + 1) / 2 > MAX_SIZE) {  //check the array size
		printf("INVALID ARRAY SIZE!");
		exit(-1);
	}
	else { //assign the values to array
		for (i = 0; i <= n-1; i++) {
			 k = (i+1)*i/ 2;
			for (j = 0; j <= i; j++) {
				scanf_s("%d", &alt[k+j]);
			}
		}
	}
}

int getMatrix(int i,int j,int n) {//get the position of given index in array

	if (i<0 || j<0 || i>=n || j>=n) {
		return -2;
	}
	else if (i>=j) {
		return (i + 1) * i / 2 + j; //return the position
	}
	else {
		return -1;
	}
}

int main() {

	int a,n,alt[MAX_SIZE];
	printf("n:  ");
    scanf_s("%d", &n); //size of matrix
	readMatrix(alt, n); //read values of triangular matrix

	printf("----------Array-------\n");
	for (int i = 0; i <= n * (n + 1) / 2-1; i++) { //write the triangular matrix
		printf("%d",alt[i]);
	}

	a = getMatrix(1,1, n);//get the position of the given index

	if (a == -2) { //outside of array
		printf("\ninvalid index\n");
	}
	else if (a == -1) { //value is zero
		printf("\noutside of the triangular\n");
	}
	else { //write the position of index
		printf("\nthe position in array: %d  value: %d",a,alt[a]);
	}
}