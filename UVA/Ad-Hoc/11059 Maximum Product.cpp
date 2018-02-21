#include<stdio.h>
int main()
{
    long long int n,a[20],i,j=1,k,mul,max,l;
    while(scanf("%lld",&n)==1)
    {
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        max=0;
        for(i=0;i<n;i++)
        {
            mul=1;
            for(k=i;k<n;k++)
            {
                mul=mul*a[k];
                if(mul>max)
                    max=mul;
            }
        }
        printf("Case #%lld: The maximum product is %lld.\n\n",j,max);
        j++;
    }
    return 0;
}
