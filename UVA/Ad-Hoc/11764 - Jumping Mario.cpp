#include<stdio.h>
int main()
{
    int T,t,n,i,a[100],high,low;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        high=0;low=0;
        for(i=1;i<n;i++)
        {
            if(a[i]==a[i+1])    continue;
            if(a[i]>a[i+1])     low++;
            else    high++;
        }
        printf("Case %d: %d %d\n",t,high,low);
    }
    return 0;
}
