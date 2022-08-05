#include <stdio.h>
#define N 5

char nesneler[N] = { 'A','B','C','D','E' };

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int knapsack(int K, int value[N], int weight[N], int n) {

	int maxValue = 0, include = 0, not_include = 0, total_weight=0, total_value=0;
	int secilenler[N];

	if (n == 0 || K == 0) { //Eger ekleyecek nesne veya cantada yer kalmadiysa 0 dondur.
		return 0;
	}

	 if (weight[n-1] > K) { //nesnenin agirligi cantadan fazlaysa ekleyemeyiz.
		return knapsack(K, value, weight, n - 1); //diger nesneleri eklemeyi deneyelim
	 }

	//Nesne cantaya eklendiginde ya da eklenmediginde elde edilen max degeri dondur.
	include = value[n-1] + knapsack(K - weight[n-1], value, weight, n - 1);
	not_include = knapsack(K, value, weight, n - 1);
	maxValue = max(include, not_include);
	return maxValue;
}


int main() {

	int K = 0; //cantanin kapasitesi
	int W[N], V[N]; //Nesnelerin agirliklarinin ve degerlerinin tutuldugu diziler.

	printf("Cantanin kapasitesi (K): "); scanf_s("%d", &K);

	if (K >= N && K <= N * N) {
		printf("---Nesnelerin V (deger) ve W (agirlik) bilgilerini giriniz: ---\n");
		
		for (int i = 0; i < N; i++) {
			int temp_v = 0;
			printf(" %c => V: ", nesneler[i]); scanf_s("%d", &temp_v);
			if (temp_v >= 1 && temp_v <= N * N) {
				V[i] = temp_v;

				int temp_w = 0;
				printf("      W: "); scanf_s("%d", &temp_w);
				if (temp_w >= 1 && temp_w <= K) {
					W[i] = temp_w;
					printf("\n");
				}
				else {
					printf("Agirlik [1,%d] araliginda olmali!!\n",K);
					return 0;
				}
			}
			else {
				printf("Deger [1,25] araliginda olmali!!\n");
				return 0;
			}
		}
	}
	else {
		printf("Kapasite [5,25] arasinda olmalidir!!\n");
	}


	printf("Max deger: %d ",knapsack(K, V, W, N));

}