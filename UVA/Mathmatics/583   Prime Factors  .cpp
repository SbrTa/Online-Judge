#include<bits/stdc++.h>
using namespace std;

#define max 50000
unsigned long long int prime[max],status[max];

int main()
{
    //Generate prime//
    unsigned long long int l=0,i,j;
    for(i=3; i<=max; i+=2)
        status[i]=0;
    for(i=3; i*i<=max; i+=2)
    {
        if(status[i]==0)
        {
            for(j=i*i; j<=max; j+=i+i)
                status[j]=1;
        }
    }
    prime[l++]=2;
    for(i=3; i<=max; i+=2)
    {
        if(status[i]==0)
            prime[l++]=i;
    }

    //main Code//

    long long n;
    while(cin>>n)
    {
        if(n==0)
            break;
        printf("%lld =",n);

        int flag=0;

        if(n<0)
        {
            printf(" -1");
            n=n*(-1);
            flag=1;
        }
        for(i=0;prime[i]<=n;i++)
        {
            if(prime[i]==prime[l-1])
                break;
            long long r=0;
            while(r==0)
            {
                r=n%prime[i];
                if(r==0)
                {
                    if(flag==0)
                    {
                        printf(" %llu",prime[i]);
                        n=n/prime[i];
                        flag=1;
                        continue;
                    }
                    printf(" x %llu",prime[i]);
                    n=n/prime[i];
                }
            }
        }
        if(n>1&&flag==0)
            printf(" %lld",n);
        else if(n>1)
            printf(" x %lld",n);
        puts("");
    }
    return 0;
}
