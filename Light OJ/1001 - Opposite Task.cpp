#include<stdio.h>
int main()
{
    int t,n,a,b;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        if(n>10)
        {
            a=n-10;
            b=10;
        }
        else
        {
            a=0;
            b=n;
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}
