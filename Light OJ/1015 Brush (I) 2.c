#include<stdio.h>
int main()
{
    int T,t,n,a[1000],i,sum;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>0)
                sum=sum+a[i];
        }
        printf("Case %d: %d\n",t,sum);
    }
    return 0;
}
