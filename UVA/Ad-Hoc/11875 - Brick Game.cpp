#include<stdio.h>
int main()
{
    int T,t,n,a[11],i,j,temp,b;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
            {
                if(a[j]>a[i])
                    {temp=a[i]; a[i]=a[j]; a[j]=temp;}
            }
        b=(n/2);
        printf("Case %d: %d\n",t,a[b]);
    }
    return 0;
}
