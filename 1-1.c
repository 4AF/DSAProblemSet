#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

//����˳���
typedef struct list{
    char *data;//�洢�ռ��ַ
    int length;//��ǰ����
    int listsize;//��ǰ����Ĵ洢����
}List;

#define LIST_INIT_SIZE 100//���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10//���Ա�洢�ռ�ķ�������
#define LEN sizeof(List)
//��ʼ��˳���
void InitList(List *l)
{
    
    l->data=(char*)malloc(LIST_INIT_SIZE*sizeof(char));//����һ���յ�˳���
    if(!l->data)
    {
        printf("��ʼ��ʧ��");
        exit(0);
    }
    l->length=0;//�ձ�ĳ��ȳ�ʼ��Ϊ0
    l->listsize=LIST_INIT_SIZE;//��ʼ�洢����
}

//����˳���
void Create(List *l)
{
    char temp[LIST_INIT_SIZE];
    gets(temp);
    InitList(l);
    
    int i=0;
    
    l->length=i;
}

//��������
void PrintList(List *l)
{
    for(int i=0;i<l->length;i++)
        printf("%c",(l->data[i]));
}

void Delete(List *l,int p)//ɾ��ָ��λ������
{
    l->length-=1;
	for(int i=p;i<l->length;i++)
		l->data[i]=l->data[i+1];
}


int main()
{
    List *list=(List*)malloc(LEN);
    char temp[LIST_INIT_SIZE];
    int i=0;
    InitList(list);//��ʼ��˳���
    //printf("���� ");
    gets(temp);//���ո�Ҳ��Ϊ�ַ�����
    while(temp[i]!='\0')
    {
        list->data[i]=temp[i];
        i++;
        list->length=i;
    }
    for(int i=0;i<list->length;i++)
	{
		if(list->data[i]=='x')
		{
			Delete(list,i);
			i--;
			Delete(list,i);
			i--;
		}
	}
    //printf("��� ");
    PrintList(list);
    return 0;
}
