#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


#define MAX 100
#define MaxWeight 32767

//第三题
void Prim(int edge[6][6], int n)
{
    int sum = 0; 
    int lowcost[6]; 
    int i, j; 
    lowcost[0] = 0;
    for (i = 0;i < n;i++) {
        if (edge[0][i] == -1) {
            lowcost[i] = MaxWeight; 
        }
        else {
            lowcost[i] = edge[0][i]; 
        }
    }


    for (i = 0;i < n - 1;i++) { 
        int min = MaxWeight; 
        int minID = 0; 

        for (j = 0;j < n;j++) { 
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                minID = j;
            }
        }
        lowcost[minID] = 0; 
        sum += min;

        for (j = 0;j < n;j++) {
            if (lowcost[j] != 0 && edge[minID][j] < lowcost[j] && edge[minID][j] != -1) {
                lowcost[j] = edge[minID][j];
            }
        }
    }
    printf("%d", sum);
}

void Test3()
{
    int n = 6;
    int i, j;
    int edge[6][6];
    for (i = 0;i < n;i++) {
        for (j = 0;j < n;j++) {
            scanf("%d", &edge[i][j]);
        }
    }
    Prim(edge, n);
}

int main()
{
    Test3();
    return 0;
}
