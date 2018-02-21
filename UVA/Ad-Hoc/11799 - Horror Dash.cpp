#include<stdio.h>
int main()
{
    int T,t,n,i,j,a[10001],temp;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
                if(a[i]>a[j])
                    {temp=a[i]; a[i]=a[j]; a[j]=temp;}
        printf("Case %d: %d\n",t,a[n-1]);
    }
    return 0;
}
