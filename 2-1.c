#include <stdio.h>
#include <stdlib.h>

typedef char datatype;
#define maxsize 64
typedef struct
{
    datatype data[maxsize];
    int top;
} Seqstack;

/*置空栈*/
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

/*进栈*/
Seqstack *PUSH(Seqstack *s, datatype x) //将元素x插入顺序栈s的顶部
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

/*退栈*/
datatype POP(Seqstack *s) //若栈非空，取出栈顶元素删除
{
    if (empty(s))
    {
        printf("underflow");
        exit(0);
    }
    else
    {
        s->top--;                     //删去栈顶元素
        return (s->data[s->top + 1]); //返回被删值
    }
}

/*取栈顶*/
datatype TOP(Seqstack *s) //取顺序栈s的栈顶
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
                    k++; //找到是哪个右括号
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
            printf("匹配成功");
        else{
            while(!empty(s))
        {
            if(TOP(s)== '(' || TOP(s) == '[' || TOP(s) == '{')
            {
                for (k = 0; left[k] != TOP(s);)
                    k++; //找到是哪个左括号
                printf("缺少%c括号",right[k]);
                POP(s);
            }
            else
            {
                for (k = 0; right[k]!= TOP(s);)
                    k++; //找到是哪个右括号
                printf("缺少%c括号",left[k]);
                POP(s);
            }
        }
        }
        return 0;
    }
