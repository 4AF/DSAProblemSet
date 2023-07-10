//aim="abacababdeadcde"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 255
typedef struct{
    char ch[MAXSIZE+1];
    int length;
}SString;

int next[8];

void InitSSting(SString *s){
    s->length=0;
}
void get_next(SString T,int *next){
    int i=1,j=0;
    
    next[1]=0;
    while(i<T.length){
        if(j==0||T.ch[i]==T.ch[j]){
            ++i;++j;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }
}

void get_nextval(SString T,int *nextval){
    int i=1,j=0;
    nextval[1]=0;
    while(i<T.length){
        if(j==0||T.ch[i]==T.ch[j]){
            ++i;++j;
            if(T.ch[i]!=T.ch[j]) nextval[i]=j;
            else nextval[i]=nextval[j];
        }
        else{
            j=nextval[j];
        }
    }
}

int Index_KMP(SString S,SString T){
    int i=1,j=1;
    get_next(T,next);
    while(i<=S.length&&j<=T.length){
        if(S.ch[i]==T.ch[j]||j ==0){
            ++i;
            ++j;
        }
        else {
            j=next[j];
        }
    }
    if(j>T.length)return i-T.length;
    else return 0;
}

int Index_BF(SString S,SString T){
    int i=1,j=1;
    while(i<=S.length&&j<=T.length){
        if(S.ch[i]==T.ch[j]){
            ++i;
            ++j;
        }
        else {
            i=i-j+2;
            j=1;
        }
    }
    if(j>=T.length)return i-T.length;
    else return 0;
}

int Index_BF2(SString S,SString T,int pos){
    int i=pos,j=1;
    while(i<=S.length&&j<=T.length){
        if(S.ch[i]==T.ch[j]){
            ++i;
            ++j;
        }
        else {
            i=i-j+2;
            j=1;
        }
    }
    if(j>=T.length) return i-T.length;
    else return 0;
}



int main(){
    SString S,T;
    InitSSting(&T);
    strcpy(S.ch,"0abacababdeadcde");S.length=15;
    char temp[8];
    gets(temp);
    int i;
    for(i=1;temp[i-1]!='\0';i++){
        T.ch[i]=temp[i-1];
        T.length++;
    }
    if(Index_KMP(S,T)) printf("匹配成功\n");
    else printf("匹配未成功\n");
    for(i=1;i<=T.length;i++) printf("%d",next[i]-1);
    return 0;
}
