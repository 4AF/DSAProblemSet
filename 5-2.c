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

//归并排序
//合并
void Merge(Sqlist *L,KeyType temp[],int low,int mid,int high){
    //标记左半区域第一个未排序的元素
    int l_pos=low;
    //标记右半区域第一个未排序的元素
    int h_pos=mid+1;
    //临时数组元素的下标
    int pos=low;
    //合并
    while(l_pos<=mid&&h_pos<=high)
    {
        if(L->r[l_pos].key<L->r[h_pos].key)//左半区域元素更小
            temp[pos++]=L->r[l_pos++].key;
        else//右半区域元素更小
            temp[pos++]=L->r[h_pos++].key;
    }
    //合并左半区域剩余的元素
    while(l_pos<=mid)
        temp[pos++]=L->r[l_pos++].key;
    //合并左半区域剩余的元素
    while(h_pos<=high)
        temp[pos++]=L->r[h_pos++].key;
    //把临时数组中合并后的元素复制回原来的数组
    while(low<=high){
        L->r[low].key=temp[low];
        low++;
    }
}
//划分
void MSort(Sqlist *L,KeyType temp[],int low,int high){
    //如果只有一个元素，那么就不需要继续划分
    //只有一个元素的区域，本身就是有序的，只需要被归并即可
    if(low<high){
        //找中间点
        int mid=(low+high+1)/2;
        //递归划分左半区域
        MSort(L,temp,low,mid-1);
        //递归划分右半区域
        MSort(L,temp,mid,high);
        //合并已经排序的部分
        Merge(L,temp,low,mid-1,high);
    }
}
//归并排序入口
void MergeSort(Sqlist *L,int n){
    //分配一个辅助数组
    KeyType temp[n+1];
    MSort(L,temp,1,n);
}
//将字符串转化为数组
int StringToInt(SString *s){
    if(s->length==1){
        return (s->data[0]-'0');
    }
    else{
		return ((s->data[0]-'0')*10+s->data[1]-'0');
    }
}
void print(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
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
    int arr1[12] = { 3,13,35,15,5,20,9,6,14,37,59,64 };
    int arr2[12] = { 3,13,35,5,15,20,6,9,14,37,59,64 };
    int arr3[12] = { 3,5,13,15,20,35,6,9,14,37,59,64 };
    print(arr1,12);
    print(arr2,12);
    print(arr3,12);
    MergeSort(&L,L.length);
    for(i=1;i<=L.length;i++) printf("%d ",L.r[i].key);
    printf("\n");
}
