#include<stdio.h>
#include<stdlib.h>

typedef struct Node{//建立循环链表
    int pwd;
    struct DuLNode *next;
}Node,*LinkList;

#define LEN sizeof(Node)
#define Step 3//定义步长

Node* InitLink(int n)//建立有n个元素的循环链表
{
    int i;
    Node *head=NULL,*p=NULL;
    head=(Node*)malloc(LEN);
    head->pwd=1;
    head->next=NULL;
    p=head;
    for(i=2;i<=n;i++)
    {
        Node *body=(Node*)malloc(LEN);
        body->pwd=i;
        body->next=NULL;
        p->next=body;
        p=body;
    }
    p->next=head;//首位相连
    return head;
}

void PrintLink(Node *head)
{
    Node *r=head;
    do{
        printf("%d ",r->pwd);
        r=r->next;
    }while(r!=head);
}

void Josephus(Node *head,int n,int m)
{
    Node *pre=NULL;
    Node *p=head;
    for(int i=0;i<n-2;i++)//执行n次
    {
        for(int j=1;j<m;j++)//数m-1个人
        {
            pre=p;
            p=p->next;
        }
        pre->next=p->next;
        p=pre->next;
    }
    for(int i=0;i<2;i++)
    {
        for(int j=1;j<m;j++)//数m-1个人
        {
            pre=p;
            p=p->next;
        }
        printf("%d ",p->pwd);
        pre->next=p->next;
        p=pre->next;
    }
}

int main()
{
    int n,m=Step;
    Node *head;
    scanf("%d",&n);
    InitLink(n);
    head=InitLink(n);
    Josephus(head,n,m);
    return 0;
}