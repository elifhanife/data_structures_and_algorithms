#include <stdio.h>
#define v1 8
#define v2 8
#define MAX 10

char vertex1[v1] = { 'a','b','c','d','g','h','i','j'};
char vertex2[v2] = { '1','2','3','4','5','6','7','8'};


int isIsomorphic(int matris1[v1][v1],int matris2[v2][v2]) {

	int degree1[v1] = { NULL }, degree2[v2] = { NULL };
	char adj1[v1][v1] = { NULL }, adj2[v2][v2] = { NULL };
	int i = 0, e1 = 0, e2 = 0;

	if (v1 == v2) {//eger vertex sayilari esitse izomorfik olabilirler.
		
		for (int i = 0; i < v1; i++) { //her vertex icin derece hesaplamasi yapiliyor.
			for (int j = 0; j < v1; j++) {
				if (matris1[i][j] == 1) {
					degree1[i] += 1; //bir vertexin toplam derecesi.
					adj1[i][j] = vertex1[j]; //bir vertex in komsulari olan vertexler.
				}
				if (matris2[i][j] == 1) {
					degree2[i] += 1;
					adj2[i][j] = vertex2[j];
				}
			}
			printf("%c 's degree: %d", vertex1[i], degree1[i]);//derecesi hesaplanan vertexler ekrana yazdiriliyor.
			printf(", adjacents: ");
			for (int k = 0; k < v1; k++) {
				if (adj1[i][k] != NULL) {
					printf("%c ", adj1[i][k]); //vertexlerin komsulari ekrana yazdiriliyor.
				}
			}
			printf("\t%c 's degree: %d", vertex2[i], degree2[i]); //diger matrise ait derece ve komsu vertex bilgileri de ekrana yazd�r�l�yor.
			printf(", adjacents: ");
			for (int k = 0; k < v1; k++) {
				if (adj2[i][k] != NULL)
					printf("%c ", adj2[i][k]);
			}
			printf("\n");
		}

		while (i < v1) {
			e1 += degree1[i]; //vertexlerin dereceleri toplaniyor. Dereceler toplaminin yarisi ile kenar sayisi bulunacak.
			e2 += degree2[i];
			i++;
		}
		e1 = e1 / 2; //kenar sayisi vertexlerin toplam derecesinin yarisi kadardir.
		e2 = e2 / 2;
		
		if (e1 == e2) {//eger kenar sayilari da esitse izomorfik olabilirler.
			for (int i = 0; i < v1; i++) {
				for (int j = 0; j < v1; j++) {
					if (degree1[i] == degree2[j]) {//eger esit dereceye sahip vertexler varsa izomorfiklerdir.
						return 1;
					}
					else {
						return 0;
					}
				}
			}
		}
		else {
			return 0;
		}
	}

	return 0;
}

int main() {

	int M1[v1][v1] = { {0,0,0,0,1,1,1,0},
					   {0,0,0,0,1,1,0,1},
					   {0,0,0,0,1,0,1,1},
					   {0,0,0,0,0,1,1,1},
					   {1,1,1,0,0,0,0,0},
					   {1,1,0,1,0,0,0,0},
					   {1,0,1,1,0,0,0,0},
					   {0,1,1,1,0,0,0,0},
					 };

	int M2[v2][v2] = { {0,1,0,1,1,0,0,0},
					   {1,0,1,0,0,1,0,0},
					   {0,1,0,1,0,0,1,0},
					   {1,0,1,0,0,0,0,1},
					   {1,0,0,0,0,1,0,1},
					   {0,1,0,0,1,0,1,0},
					   {0,0,1,0,0,1,0,1},
					   {0,0,0,1,1,0,1,0},
	                 };

	int output = isIsomorphic(M1, M2);

	if (output == 1) {
		printf("\nGraflar izomorfiktir.\n");
	}
	else {
		printf("\nGraflar izomorfik degildir.\n");
	}

	return 0; 
}