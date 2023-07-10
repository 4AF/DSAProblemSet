#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

//定义顺序表
typedef struct list{
    char *data;//存储空间基址
    int length;//当前长度
    int listsize;//当前分配的存储容量
}List;

#define LIST_INIT_SIZE 100//线性表存储空间的初始分配量
#define LISTINCREMENT 10//线性表存储空间的分配增量
#define LEN sizeof(List)
//初始化顺序表
void InitList(List *l)
{
    
    l->data=(char*)malloc(LIST_INIT_SIZE*sizeof(char));//构造一个空的顺序表
    if(!l->data)
    {
        printf("初始化失败");
        exit(0);
    }
    l->length=0;//空表的长度初始化为0
    l->listsize=LIST_INIT_SIZE;//初始存储容量
}

//建立顺序表
void Create(List *l)
{
    char temp[LIST_INIT_SIZE];
    gets(temp);
    InitList(l);
    
    int i=0;
    
    l->length=i;
}

//遍历操作
void PrintList(List *l)
{
    for(int i=0;i<l->length;i++)
        printf("%c",(l->data[i]));
}

void Delete(List *l,int p)//删除指定位的数据
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
    InitList(list);//初始化顺序表
    //printf("输入 ");
    gets(temp);//将空格也作为字符输入
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
    //printf("输出 ");
    PrintList(list);
    return 0;
}
