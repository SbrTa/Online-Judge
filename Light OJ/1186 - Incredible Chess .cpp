#include<stdio.h>

int main()
{
    long long T,t,n,i,one,a[111],b[111],c[111];
    scanf("%lld",&T);
    for(t=1;t<=T;t++)
    {
        one=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        for(i=0;i<n;i++)
            scanf("%lld",&b[i]);
        for(i=0;i<n;i++)
        {
            c[i]=b[i]-a[i]-1;
            if(c[i]==1)
                one++;
            if(i==0)
                continue;
            c[i]=c[i]^c[i-1];
        }
        printf("xor %d\n",c[i-1]);
        printf("Case %lld: ",t);
        if(n==1)
            printf("white wins\n");
        else if(one==n&&n%2==1)
            printf("white wins\n");
        else if(one==n&&n%2==0)
            printf("black wins\n");
        else if(c[i-1]==0)
            printf("black wins\n");
        else if(c[i-1]>0)
            printf("white wins\n");
    }
    return 0;
}
