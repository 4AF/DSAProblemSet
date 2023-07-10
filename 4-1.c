#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


int visited[1000];

void DFS(char* vertices, int edge[9][9], int n, int v)
{
    printf("%c", vertices[v]); 
    visited[v] = 1; 
    int i = 0; 
    for (i = 0;i < n;i++) { 
        if (visited[i] == 0 && edge[v][i] == 1) { 
            DFS(vertices, edge, n, i); 
        }
    }
}


void DFSTraverse(char* vertices, int edge[9][9], int n)
{
    int i = 0;
    for (i = 0;i < n;i++) {
        visited[i] = 0;
    }
    int v = 0;
    for (v = 0;v < n;v++) {
        if (!visited[v]) {
            DFS(vertices, edge, n, v);
        }
    }

}





typedef struct QueueNode {
    int data;
    struct QueueNode* next;
}QueueNode;

typedef struct Queue {
    QueueNode* first;
    QueueNode* last;
}Queue;

void QueueInit(Queue* pq)
{
    assert(pq);
    pq->first = NULL;
    pq->last = NULL;
}

bool QueueEmpty(Queue* pq)
{
    assert(pq);
    return pq->first == NULL;
}

void QueuePush(Queue* pq, int x)
{
    assert(pq);
    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
    newnode->data = x;
    newnode->next = NULL;

    if (QueueEmpty(pq)) {
        pq->first = pq->last = newnode;
    }
    else {
        pq->last->next = newnode;
        pq->last = newnode;
    }
}

void QueuePop(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    QueueNode* next = pq->first->next;
    free(pq->first);
    pq->first = next;
}

QueueNode* QueueFirst(Queue* pq)
{
    assert(pq);
    return pq->first;
}

void QueueDestroy(Queue* pq)
{
    assert(pq);
    QueueNode* cur = pq->first;
    while (cur) {
        QueueNode* next = cur->next;
        free(cur);
        cur = next;
    }
}


void BFSTraverse(char* vertices, int edge[9][9], int n)
{
    int i = 0;
    for (i = 0;i < n;i++) {
        visited[i] = 0;
    }
    Queue q;
    QueueInit(&q);
    int v = 0; //作为当前元素的下标，也就是行
    i = 0; //作为列
    QueuePush(&q, 0);
    visited[0] = 1;
    while (!QueueEmpty(&q)) {
        for (i = 0;i < n;i++) {
            if (visited[i] == 0 && edge[v][i] == 1) {
                QueuePush(&q, i);
                visited[i] = 1;
            }
        }
        printf("%c", vertices[QueueFirst(&q)->data]);
        v = (QueueFirst(&q))->data;
        QueuePop(&q);
    }


    QueueDestroy(&q);
}


int main()
{
    int n = 9;
    int i, j;
    char vertices[9] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
    int edge[9][9];
    for (i = 0;i < n;i++) {
        for (j = 0;j < n;j++) {
            scanf("%d", &edge[i][j]);
        }
    }
    DFSTraverse(vertices, edge, n);
    printf("\n");
    BFSTraverse(vertices, edge, n);
    return 0;
}
