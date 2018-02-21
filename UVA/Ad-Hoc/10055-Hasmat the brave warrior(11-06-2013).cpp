#include<stdio.h>
int main()
{
    long a,b,s;
    while(scanf("%ld%ld",&a,&b)==2)
    {   if(a>b&&a>=0&&b>=0)
            s=a-b;
        else
            s=b-a;
        printf("%ld\n",s);
    }
return 0;
}
