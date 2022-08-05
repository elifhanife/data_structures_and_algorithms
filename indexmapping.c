// verilen dizide pozitif ve negatif sayilari bulan program.

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define bool int
#define true (1)
#define false (0)
#define MAX 10


bool has[MAX + 1][2];


bool search(int x) {

	if (x >= 0) { //x positifse
		if (has[x][0] == 1) { //x pozitif sutunda varsa
			return true;
		}
		else { //x pozitif sutunda yoksa
			return false;
		}
	}

	//x negatifse mutlak degerini al ve 2.sutunda var mi bak.
	x = abs(x);
	if (has[x][1] == 1) {
		return true;
	}
	return false;
}

void insert(int a[], int n) {

	for (int i = 0; i < n; i++) {
		if (a[i] >= 0) { //sayi pozitifse ilk sutuna ekle.
			has[a[i]][0] = 1;
		}
		else {
			has[abs(a[i])][1] = 1; //negatifse mutlak degerini 2.sutuna ekle.
		}
	}

}


int main() {

	int a[] = { -1, 9,-5,-8,-5,-2 };
	int n = sizeof(a) / sizeof(a[0]);
	
	insert(a, n);
	
	int x = -5;
	
	if (search(x) == true) {
		printf("\nValue is presented!\n");
	}
	else {
		printf("\nValue is NOT presented!\n");
	}

	return 0;
}