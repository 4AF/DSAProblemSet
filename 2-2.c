#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 1024//队列的最大容量
typedef int datatype ;
typedef struct queue{
    datatype data[MAXSIZE];//队员的存储空间
    int rear,front;//队头队尾指针
}SeQueue;

//置空队
void InitQueue(SeQueue* q)
{
    q->front=q->rear=0;
}

//入队
int EnQueue(SeQueue* q,datatype x)
{
    if(q->rear==MAXSIZE-1)
    {
        printf("队满");
        return 0;
    }
    else
    {
        q->data[q->rear]=x;
        q->rear=q->rear+1;
        
        return 1;
    }
}

//出队
int DeQueue(SeQueue* q,datatype* x)
{
    if(q->rear==q->front)
    {
        printf("队空");
        return 0;
    }
    else
    {
        *x=q->data[q->front];
        q->front=q->front+1;;
        
        return 1;
    }
}

//读队头元素
int Front_Queue(SeQueue* q,datatype* x)
{
    if(q->rear==q->front)
    {
        printf("队空");
        return -1;
    }
    else{
        *x=q->data[q->front];
        return 1;
    }
}
int Empty(SeQueue* q)
{
    if(q->front==q->rear)
        return 1;
    else 
        return 0;
}
//杨辉三角实现函数
void yanghui(int n){
    SeQueue Q;
    int i,s,e,k;
    if(n==1) {
	printf("%d\n",1);
	return;}
    if(n>=100) {
	printf("队列已满\n");
	return;}
    //初始化队列，同时将三角的第二行作为起始行，向下推导
    InitQueue(&Q);
    EnQueue(&Q,0);
    EnQueue(&Q,1);
    EnQueue(&Q,1);
    k=1;
    while(k<n-1){
        //每往下一行，其第一个数字都需往左移动 1 个占位
        // 0 作为转行符，入队列
        EnQueue(&Q,0);
        do{
            //队头元素出队列
            DeQueue(&Q,&s);
            //取新的队头元素
            Front_Queue(&Q,&e);
            //如果所取元素非 0，则输出，否则做转行操作
            EnQueue(&Q,s+e);
        }while(e!=0);//一旦 e 值为 0，即做转行操作，退出循环，开始新一行的排列
        k++;
    }
    //出循环后，队列中还存有下一行的数据
    DeQueue(&Q,&e);
    while(!Empty(&Q)){
        DeQueue(&Q,&e);
        printf("%d ",e);
    }
}
int main(){
	int N;
	scanf("%d",&N);
    yanghui(N);
    return 0;
}
