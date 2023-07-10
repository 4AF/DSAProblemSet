#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 64//设记录不超过20个
typedef int KeyType;//设置关键字为整型量
typedef char InfoType;
typedef struct{
    KeyType key;
    InfoType otherinfo;//其他数据项
}RedType;//Record Type

typedef struct{
    RedType r[MAXSIZE+1];//r[0]一般作哨兵或缓冲区
    int length;//顺序表的长度
}Sqlist;

typedef struct SString{
    char data[MAXSIZE];
    int length;
}SString;

//快速排序
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
void QSort(Sqlist *L,int low,int high){//对顺序表L 快速排序
    int pivotloc,i;
    if(low<high){//长度大于1
        pivotloc=Partition(L,low,high);
        if(low!=pivotloc)
        {for(i=1;i<=L->length;i++) printf("%d ",L->r[i].key);
        printf("\n");}
        //将L.r[low..high]一分为二，pivotloc为枢轴元素排好序的位置
        QSort(L,low,pivotloc-1);//对低子表递归排序
        QSort(L,pivotloc+1,high);//对高子表递归排序
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
