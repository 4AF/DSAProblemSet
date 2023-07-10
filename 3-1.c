#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//二叉树的顺序存储表示
#define MAXSIZE 100
#define TElemType char
typedef TElemType SqBiTree[MAXSIZE];


void Pre(SqBiTree t,int i){
    if(t[i]!='0'&&i<strlen(t)) {
        printf("%c",t[i]);
        Pre(t,2*i);
        Pre(t,2*i+1);
    }
}

void In(SqBiTree t,int i){
    if(t[i]!='0'&&i<strlen(t)) {
        In(t,2*i);
        printf("%c",t[i]);
        In(t,2*i+1);
    }
}

void Post(SqBiTree t,int i){
    if(t[i]!='0'&&i<strlen(t)) {
        Post(t,2*i);
        Post(t,2*i+1);
        printf("%c",t[i]);
    }
}

void main(){
    SqBiTree bt;
    char temp[MAXSIZE];
    gets(temp);
    int i;
    for(i=1;temp[i-1]!='\0';i++) bt[i]=temp[i-1];
    bt[i]='\0';
    Pre(bt,1);
    printf("\n");
    In(bt,1);
    printf("\n");
    Post(bt,1);
}
