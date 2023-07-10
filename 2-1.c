#include <stdio.h>
#include <stdlib.h>

typedef char datatype;
#define maxsize 64
typedef struct
{
    datatype data[maxsize];
    int top;
} Seqstack;

/*�ÿ�ջ*/
void SETNULL(Seqstack *s)
{
    s->top = -1;
}

int empty(Seqstack *s)
{
    if (s->top >= 0)
        return 0;
    else
        return 1;
}

/*��ջ*/
Seqstack *PUSH(Seqstack *s, datatype x) //��Ԫ��x����˳��ջs�Ķ���
{
    if (s->top == maxsize - 1)
    {
        printf("overflow");
        return NULL;
    }
    else
    {
        s->top++;
        s->data[s->top] = x;
        return s;
    }
}

/*��ջ*/
datatype POP(Seqstack *s) //��ջ�ǿգ�ȡ��ջ��Ԫ��ɾ��
{
    if (empty(s))
    {
        printf("underflow");
        exit(0);
    }
    else
    {
        s->top--;                     //ɾȥջ��Ԫ��
        return (s->data[s->top + 1]); //���ر�ɾֵ
    }
}

/*ȡջ��*/
datatype TOP(Seqstack *s) //ȡ˳��ջs��ջ��
{
    if (empty(s))
    {
        printf("stack is empty");
        exit(0);
    }
    else
    {
        return (s->data[s->top]);
    }
}

int main()
{
    Seqstack *s=(Seqstack*)malloc(sizeof(Seqstack));
    SETNULL(s);
    char x[maxsize];
    int k;
    char left[3] = {'(', '[', '{'};
    char right[3] = {')', ']', '}'};
    gets(x);
    int i=0;
   	while(x[i]!='\0')
   	{
   		while (x[i] == '(' || x[i] == '[' || x[i] == '{' || x[i] == ')' || x[i] == ']' || x[i] == '}')
    	{
            if (x[i] == '(' || x[i] == '[' || x[i] == '{')
            {
                PUSH(s, x[i]);
            }
            else
            {
                for (k = 0; right[k] != x[i];)
                    k++; //�ҵ����ĸ�������
                if (!empty(s) && left[k] == TOP(s))
                    POP(s);
                else{
                	PUSH(s,x[i]);
				}
            }
            i++;
        }
        i++;
	   }
        
        if (empty(s))
            printf("ƥ��ɹ�");
        else{
            while(!empty(s))
        {
            if(TOP(s)== '(' || TOP(s) == '[' || TOP(s) == '{')
            {
                for (k = 0; left[k] != TOP(s);)
                    k++; //�ҵ����ĸ�������
                printf("ȱ��%c����",right[k]);
                POP(s);
            }
            else
            {
                for (k = 0; right[k]!= TOP(s);)
                    k++; //�ҵ����ĸ�������
                printf("ȱ��%c����",left[k]);
                POP(s);
            }
        }
        }
        return 0;
    }
