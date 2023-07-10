#include<stdio.h>

#define MAXSIZE 20//���¼������20��
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

void ShellInsert(Sqlist *L,int dk){
    int i,j;
    for(i=dk+1;i<=L->length;i++){
        if(L->r[i].key<L->r[i-dk].key){
            L->r[0]=L->r[i];
            for(j=i-dk;j>0&&(L->r[0].key<L->r[j].key);j=j-dk) L->r[j+dk]=L->r[j];
            L->r[j+dk]=L->r[0];
        }
    }
}
void ShellSort(Sqlist *L,int dlta[],int t){
    //����������dlta[0..t-1]��˳���L��ϣ������
    int k,i;
    for(k=0;k<t;k++){
        ShellInsert(L,dlta[k]);//һ������Ϊdlta[k]�Ĳ�������
        for(i=1;i<13;i++)
            printf("%d ",L->r[i].key);
        printf("\n");
        }
}

void main(){
    Sqlist L;
    int dlta[3]={3,2,1};
    //3 35 13 15 20 5 9 14 6 37 59 64
    L.r[1].key=3;L.r[2].key=35;L.r[3].key=13;L.r[4].key=15;L.r[5].key=20;L.r[6].key=5;
    L.r[7].key=9;L.r[8].key=14;L.r[9].key=6;L.r[10].key=37;L.r[11].key=59;L.r[12].key=64;
    L.length=12;
    ShellSort(&L,dlta,3);
}
