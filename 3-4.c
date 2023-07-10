

#include<stdio.h>


int isleaf(int pos,int n)
{
    if(pos > n / 2 - 1)
        return 1;
    else
        return 0;
}

void SiftDown(int pos, int n, int* Heap)
{
    if(pos < 0 || pos >= n)
        printf("Heap is null or full!\n");
    int temp = Heap[pos];
    while(!isleaf(pos,n))
    {
        int lc = 2 * pos + 1;
        if((lc < n-1) && Heap[lc] < Heap[lc + 1]) //判断结点沉底时在这一步是和其左孩子交换还是右孩子交换，即和左右孩子中更大的那个交换
            lc++;
        if(temp >= Heap[lc])
            break;
        Heap[pos] = Heap[lc];
        pos = lc;
    }
    Heap[pos] = temp;
}

int main()
{
    int heap1[8] = {14,16,21,18,30,35};
    int heap2[12] = {3,13,4,7,12,1,6,2,9,8};
    int n;
    char s[30];
    gets(s);             
    if(s[0]=='1')
    {
        n = 6;
        for(int i = n / 2 - 1; i >= 0; i--)
        {
            SiftDown(i,n,heap1);
        }
        for(int i = 0; i < n - 1; i++)
        {
            printf("%d ",heap1[i]);
        }
        printf("%d",heap1[n-1]);
    }
    else
    {
        n = 10;
        for(int i = n / 2 - 1; i >= 0; i--)
        {
            SiftDown(i,n,heap2);
        }
        for(int i = 0; i < n - 1; i++)
        {
            printf("%d ",heap2[i]);
        }
        printf("%d",heap2[n-1]);
    }

    return 0;
}

