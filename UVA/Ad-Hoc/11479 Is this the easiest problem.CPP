#include<stdio.h>
int main()
{
    long int T,a,b,c,i;
    scanf("%ld",&T);
    if(T>0&&T<20)
    {
	for(i=1;i<=T;i++)
	{
	    scanf("%ld %ld %ld",&a,&b,&c);
	    if((a+b>c)&&(a+c>b)&&(b+c>a))
	    {
		if(((a==b)&&(a==c)))
		    printf("Case %ld: Equilateral\n",i);
		else if((a==b)||(b==c)||(c==a))
		    printf("Case %ld: Isosceles\n",i);
		else
		    printf("Case %ld: Scalene\n",i);
	    }
	    else
		printf("Case %ld: Invalid\n",i);
	}
    }
    return 0;
}
