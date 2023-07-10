#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 1024//���е��������
typedef int datatype ;
typedef struct queue{
    datatype data[MAXSIZE];//��Ա�Ĵ洢�ռ�
    int rear,front;//��ͷ��βָ��
}SeQueue;

//�ÿն�
void InitQueue(SeQueue* q)
{
    q->front=q->rear=0;
}

//���
int EnQueue(SeQueue* q,datatype x)
{
    if(q->rear==MAXSIZE-1)
    {
        printf("����");
        return 0;
    }
    else
    {
        q->data[q->rear]=x;
        q->rear=q->rear+1;
        
        return 1;
    }
}

//����
int DeQueue(SeQueue* q,datatype* x)
{
    if(q->rear==q->front)
    {
        printf("�ӿ�");
        return 0;
    }
    else
    {
        *x=q->data[q->front];
        q->front=q->front+1;;
        
        return 1;
    }
}

//����ͷԪ��
int Front_Queue(SeQueue* q,datatype* x)
{
    if(q->rear==q->front)
    {
        printf("�ӿ�");
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
//�������ʵ�ֺ���
void yanghui(int n){
    SeQueue Q;
    int i,s,e,k;
    if(n==1) {
	printf("%d\n",1);
	return;}
    if(n>=100) {
	printf("��������\n");
	return;}
    //��ʼ�����У�ͬʱ�����ǵĵڶ�����Ϊ��ʼ�У������Ƶ�
    InitQueue(&Q);
    EnQueue(&Q,0);
    EnQueue(&Q,1);
    EnQueue(&Q,1);
    k=1;
    while(k<n-1){
        //ÿ����һ�У����һ�����ֶ��������ƶ� 1 ��ռλ
        // 0 ��Ϊת�з��������
        EnQueue(&Q,0);
        do{
            //��ͷԪ�س�����
            DeQueue(&Q,&s);
            //ȡ�µĶ�ͷԪ��
            Front_Queue(&Q,&e);
            //�����ȡԪ�ط� 0���������������ת�в���
            EnQueue(&Q,s+e);
        }while(e!=0);//һ�� e ֵΪ 0������ת�в������˳�ѭ������ʼ��һ�е�����
        k++;
    }
    //��ѭ���󣬶����л�������һ�е�����
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
