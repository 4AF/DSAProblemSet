#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 64//���¼������20��
typedef int KeyType;//���ùؼ���Ϊ������
typedef char InfoType;
typedef struct{
    KeyType key;
    InfoType otherinfo;//����������
}RedType;//Record Type

typedef struct{
    RedType r[MAXSIZE+1];//r[0]һ�����ڱ��򻺳���
    int length;//˳���ĳ���
}Sqlist;

typedef struct SString{
    char data[MAXSIZE];
    int length;
}SString;

//��������
int Partition(Sqlist *L,int low,int high){
    L->r[0]=L->r[low];
    int pivotkey=L->r[low].key;
    while(low<high){
        while(low<high&&L->r[high].key>=pivotkey)--high;
        L->r[low]=L->r[high];
        while(low<high&&L->r[low].key<=pivotkey) ++low;
        L->r[high]=L->r[low];
    }
    L->r[low]=L->r[0];
    return low;
}
void QSort(Sqlist *L,int low,int high){//��˳���L ��������
    int pivotloc,i;
    if(low<high){//���ȴ���1
        pivotloc=Partition(L,low,high);
        if(low!=pivotloc)
        {for(i=1;i<=L->length;i++) printf("%d ",L->r[i].key);
        printf("\n");}
        //��L.r[low..high]һ��Ϊ����pivotlocΪ����Ԫ���ź����λ��
        QSort(L,low,pivotloc-1);//�Ե��ӱ�ݹ�����
        QSort(L,pivotloc+1,high);//�Ը��ӱ�ݹ�����
    }
}

int StringToInt(SString *s){
    if(s->length==1){
        return (s->data[0]-'0');
    }
    else{
		return ((s->data[0]-'0')*10+s->data[1]-'0');
    }
}
void main(){
    Sqlist L;
    L.length=0;
    char temp[MAXSIZE];
    int i=0;
    SString t;
    t.length=0;
    gets(temp);
    while(temp[i]!='\0'){
        while(temp[i]!=' '&&temp[i]!='\0'){
            t.data[t.length]=temp[i++];
            t.length++;
        }
        if(temp[i]!='\0') i++;
        L.r[++L.length].key=StringToInt(&t);
        t.length=0;
    }
    for(i=1;i<=L.length;i++) printf("%d ",L.r[i].key);
    printf("\n");
    QSort(&L,1,L.length);
    
}
