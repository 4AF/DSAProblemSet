#include<stdio.h>
int a[5],i,j,k,key;
int main()
{
	i=0;
	j=1;
	while(i<5)
	{scanf("%d",&a[i]);
	i++;}
	int st=0;
	for(int i=0;i<4;i++)
	{
		if(a[i]-a[i+1]==1)
		{
			st=1;
		}
	}
	if(st==0)
	{
		printf("重排失败");
	}
	else
	{
		while(j<5)
	{
		k=j-1;
		key=a[j];
		while(k>=0&&a[k+1]>a[k])
		{
			a[k+1]=a[k];
			a[k]=key;
			k--;
		}
		j++;
	}
    printf("%d %d %d %d %d",a[0],a[1],a[2],a[3],a[4]);
	}
	
	return 0;
}

