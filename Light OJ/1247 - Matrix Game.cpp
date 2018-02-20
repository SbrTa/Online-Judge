#include<stdio.h>

int main()
{
    long long T,t,r,c,n,a[111],one,i,j;
    scanf("%lld",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%lld%lld",&r,&c);
        one=0;
        for(i=0;i<r;i++)
        {
            a[i]=0;
            for(j=0;j<c;j++)
            {
                scanf("%lld",&n);
                a[i]+=n;
            }
            if(a[i]==1)
                one++;
            if(i==0)
                continue;
            a[i]=a[i]^a[i-1];
        }
        if(r==1&&c==1)
            printf("Case %lld: Alice\n",t);
        else if(one==r&&r%2==1)
            printf("Case %lld: Alice\n",t);
        else if(one==r&&r%2==0)
            printf("Case %lld: Bob\n",t);
        else if(a[i-1]==0)
            printf("Case %lld: Bob\n",t);
        else if(a[i-1]>0)
            printf("Case %lld: Alice\n",t);
    }
    return 0;
}
