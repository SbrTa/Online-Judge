#include<stdio.h>

int main()
{
    long long T,t,n,a[111],one,i;
    scanf("%lld",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%lld",&n);
        one=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            if(a[i]==1)
                one++;
            if(i==0)
                continue;
            a[i]=a[i]^a[i-1];
        }
        //printf("%lld\n",a[i-1]);
        if(n==1)
            printf("Case %lld: Bob\n",t);
        else if(one==n&&n%2==0)
            printf("Case %lld: Alice\n",t);
        else if(one==n&&n%2==1)
            printf("Case %lld: Bob\n",t);
        else if(a[i-1]==0)
            printf("Case %lld: Bob\n",t);
        else if(a[i-1]>0)
            printf("Case %lld: Alice\n",t);
    }
    return 0;
}
