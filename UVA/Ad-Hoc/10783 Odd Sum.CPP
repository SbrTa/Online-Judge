#include<stdio.h>
int main()
{
int a,b,T,sum=0,i,j;
scanf("%d",&T);
if(T>=1&&T<=100)
{
    for(i=1;i<=T;i++)
    {
	scanf("%d%d",&a,&b);
	if(a>=0&&a<=b&&b<=100)
	{

	    for(j=a;j<=b;j++)
		if(j%2==1)
		    sum=sum+j;
	    printf("Case %d: %d\n",i,sum);
	    sum=0;
	}
	else
	    printf("Case %d: 0\n",i);
    }
}
return 0;
}
