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

//�鲢����
//�ϲ�
void Merge(Sqlist *L,KeyType temp[],int low,int mid,int high){
    //�����������һ��δ�����Ԫ��
    int l_pos=low;
    //����Ұ������һ��δ�����Ԫ��
    int h_pos=mid+1;
    //��ʱ����Ԫ�ص��±�
    int pos=low;
    //�ϲ�
    while(l_pos<=mid&&h_pos<=high)
    {
        if(L->r[l_pos].key<L->r[h_pos].key)//�������Ԫ�ظ�С
            temp[pos++]=L->r[l_pos++].key;
        else//�Ұ�����Ԫ�ظ�С
            temp[pos++]=L->r[h_pos++].key;
    }
    //�ϲ��������ʣ���Ԫ��
    while(l_pos<=mid)
        temp[pos++]=L->r[l_pos++].key;
    //�ϲ��������ʣ���Ԫ��
    while(h_pos<=high)
        temp[pos++]=L->r[h_pos++].key;
    //����ʱ�����кϲ����Ԫ�ظ��ƻ�ԭ��������
    while(low<=high){
        L->r[low].key=temp[low];
        low++;
    }
}
//����
void MSort(Sqlist *L,KeyType temp[],int low,int high){
    //���ֻ��һ��Ԫ�أ���ô�Ͳ���Ҫ��������
    //ֻ��һ��Ԫ�ص����򣬱����������ģ�ֻ��Ҫ���鲢����
    if(low<high){
        //���м��
        int mid=(low+high+1)/2;
        //�ݹ黮���������
        MSort(L,temp,low,mid-1);
        //�ݹ黮���Ұ�����
        MSort(L,temp,mid,high);
        //�ϲ��Ѿ�����Ĳ���
        Merge(L,temp,low,mid-1,high);
    }
}
//�鲢�������
void MergeSort(Sqlist *L,int n){
    //����һ����������
    KeyType temp[n+1];
    MSort(L,temp,1,n);
}
//���ַ���ת��Ϊ����
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
