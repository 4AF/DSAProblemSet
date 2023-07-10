#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


#define MAX 100
#define MaxWeight 32767


void Dijkstra(int edge[5][5], int n)
{
    int dist[5]; 
    int visited[5]; 
    int i, j;
    for (i = 0;i < n;i++) {
        visited[i] = 0; 
        if (edge[0][i] == -1) {
            dist[i] = MaxWeight;
        }
        else {
            dist[i] = edge[0][i];
        }
    }
    visited[0] = 1; 

    for (i = 0;i < n - 1;i++) { 
        int min = MaxWeight; 
        int minID = 0; 
        for (j = 0;j < n;j++) { 
            if (dist[j] < min && visited[j] == 0) { 
                min = dist[j];
                minID = j;
            }
        }
        visited[minID] = 1; 

        for (j = 0;j < n;j++) {
            if (edge[minID][j] == -1) {
                edge[minID][j] = MaxWeight;
            }
            if (dist[minID] + edge[minID][j] < dist[j]) {
                dist[j] = dist[minID] + edge[minID][j];
            }
        }
    }
    for (i = 0;i < n;i++) {
        printf("%d ", dist[i]);
    }
}

void Test2()
{
    int n = 5;
    int i, j;
    int edge[5][5];
    for (i = 0;i < n;i++) {
        for (j = 0;j < n;j++) {
            scanf("%d", &edge[i][j]);
        }
    }
    Dijkstra(edge, n);
}


int main()
{
    Test2();
    return 0;
}
