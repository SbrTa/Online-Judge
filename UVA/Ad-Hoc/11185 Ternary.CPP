#include<stdio.h>
int main()
{
    long long int d,t,a[9999],i,j;
    for(;;)
    {
	i=0;
	scanf("%lld",&d);
	if(d<0) break;
	if(d==0)    printf("0\n");
	else{
        while(d!=0)
            {a[i]=d%3;   d=d/3;  i++;}
        for(j=i-1;j>=0;j--)
            printf("%lld",a[j]);
        printf("\n");	}
    }
    return 0;
}
