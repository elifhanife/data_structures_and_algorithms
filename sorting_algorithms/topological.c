#include<stdio.h>
//#include<conio.h>
#include<time.h>

int main() {

    clock_t start_t, end_t;

    int i, j, k, n=6, indeg[10], visited[10], vertex = 0;
    int a[6][6] = { {0,1,1,1,0,0}, {1,0,0,0,1,1}, {1,0,0,0,0,1}, {1,0,0,0,0,0}, {0,1,0,0,0,0}, {0,1,1,0,0,0} };

    start_t = clock();

    for (i = 0; i < n; i++) {
        indeg[i] = 0;
        visited[i] = 0;
        for (j = 0; j < n; j++) {
            indeg[i] = indeg[i] + a[j][i]; //sutun gezerek dereceleri hesapliyor.
        }
    }
    printf("The topological order is: ");

    while (vertex < n) {

        for (k = 0; k < n; k++) {

            if ((indeg[k] == 0) && (visited[k] == 0)) {//in-degree=0 ve gezilmediyse sort a ekle.
                printf("%d ", (k + 1));
                visited[k] = 1;//gezildi olarak isaretle.
            }
            for (i = 0; i < n; i++) {
                if (a[i][k] == 1) {//sort a eklediginin komsulariyla bagini kopart.
                    indeg[k]--;
                }
            }
        }
        vertex++;//bir sonraki vertex e gec.
    }   

    end_t = clock();
    printf("\nTime (s): %f\n", (double)(end_t-start_t) / CLOCKS_PER_SEC);

    return 0;
}