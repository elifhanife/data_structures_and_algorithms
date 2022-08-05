#include<stdio.h>
#include <time.h>

clock_t start_t, end_t;

//A=0,B=1,C=2..F=5
int a[6][6] = { {0,1,1,1,0,0}, {1,0,0,0,1,1}, {1,0,0,0,0,1}, {1,0,0,0,0,0}, {0,1,0,0,0,0}, {0,1,1,0,0,0} };
int queue[10], visited[10], n, front = -1, rear = -1;

void bfs(int vertex)
{
    int i;
    for (i = 0; i < n; i++)                   
    {
        if (a[vertex][i] != 0 && visited[i] == 0) 
        {
            rear++;
            queue[rear] = i;                  
            visited[i] = 1;      
            printf("%d ", i);
        }
    }
    front++;              

    if (front++ <= rear)                         
        bfs(queue[front]);                 
}

int main()
{

    start_t = clock();
    int vertex=0, i, j; 
    n = 6;
    for (i = 0; i < n; i++)               
    {
        visited[i] = 0;
    }

    //enqueue starting vertex
    front = rear = 0;
    queue[rear] = vertex; 

    printf("BFS: ");
    visited[vertex] = 1;                                    
    printf("%d ", vertex);

    bfs(vertex);
    end_t = clock();

    printf("\nSure: %f\n", (double)(end_t-start_t) / CLOCKS_PER_SEC);

    return 0;
}
