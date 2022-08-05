#include <stdio.h>
#define MAX_SIZE 10

void readUpTri(int upper[], int n) {

	int i, j, k;
	if (n * (n + 1) / 2 > MAX_SIZE) {
		printf("\ninvalid array size\n");
		exit(-1);
	}
	else {
		for (i = 0; i < n; i++) {
			k = i * n - i * (i - 1) / 2 - i;
			for (j = 0; j<n; j++) {
				if (j >= i)
					scanf_s("%d", &upper[k + j]);
			}
		}
	}
}

int getUpTri(int i, int j, int n) {

	if (i < 0 || j < 0 || i >= n || j >= n) {
		return -2;
	}
	else if (j >= i) {
		return i * n - i * (i - 1) / 2 - i + j;
	}
	else {
		return -1;
	}
}

int main() {

	int n, upper[MAX_SIZE], i;

	printf("n: ");
	scanf_s("%d", &n);

	readUpTri(upper, n);

	printf("\n---------ARRAY--------\n");
	for (i = 0; i < n*(n+1)/2; i++) {
		printf("%d ", upper[i]);
	}

	i = getUpTri(0, 0, n);

	if (i == -2) {
		printf("invalid index");
		//exit(-2);
	}
	else if (i == -1) {
		printf("access the lower triangle");
		//exit(-1);
	}
	else {
		printf("position: %d\tvalue: %d", i, upper[i]);
	}

}