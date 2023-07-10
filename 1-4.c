#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    char NO;
    int Num;
    struct node *next;
} Lnode,*LinkList;

LinkList H;

LinkList Creat_LinkList()
{
    LinkList L=NULL;
    Lnode *s,*r=NULL;
    char x;
    int y;
    char temp[50];//设元素的类型为char
    gets(temp);
    for(int i=0;temp[i]!='\0';)
    {
        while(temp[i]==' ') i++;
        x=temp[i];
        i=i+2;
        y=temp[i]-48;
        i=i+2;
        s=malloc(sizeof(Lnode));
        s->NO=x;
        s->Num=y;
        if(L==NULL) L=s;//第一个结点的处理
        else r->next=s;//其他结点的处理
        r=s;//r指向新的尾结点
    }
    if(r!=NULL) r->next=NULL;//对于非空表，最后结点的指针域放空指针
    LinkList h=malloc(sizeof(Lnode));
    h->next=L;
    return h;
}

void print(LinkList p)
{
    p=p->next;
    printf("%c %d",p->NO,p->Num);
    p=p->next;
    while(p->next!=NULL)
    {
        printf(", %c %d",p->NO,p->Num);
        p=p->next;
    }
    printf(", %c %d",p->NO,p->Num);
    printf(";",p->NO,p->Num);
}

void update(LinkList L,LinkList Lin)
{
    LinkList p,q;
    p=L; 
	while (Lin->next!=NULL )
    {
		q=Lin->next; 
		while (p->next!=NULL&&((p->next->NO)<(q->NO))) 
            {p=p->next;}
		if(p->next==NULL) 
        { 
            p->next=q; 
            free(Lin); 
            return; 
        }
        Lin->next=q->next; 
     	if (p->next->NO==q->NO)
         { 
             p->next->Num+=q->Num; 
        }  
     	else 
        { 
            q->next=p->next; 
            p->next=q;
            p=q;
            }
	}
	free(Lin);
	return;
}

int main()
{
    LinkList L,Lin;
    L=Creat_LinkList();
    Lin=Creat_LinkList();
    update(L,Lin);
    print(L);
    return 0;
}