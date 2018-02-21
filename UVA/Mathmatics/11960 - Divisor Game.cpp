#include<bits/stdc++.h>
using namespace std;
#define max 1000001

unsigned long long int prime[max],divid[max],status[max],mxid[max];

void primeCheck()
{
    unsigned long long int i,j,p=0,count;
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
    prime[p++]=2;
    for(i=3; i<=max; i+=2)
    {
        if(status[i]==0)
            prime[p++]=i;
    }
}

void divisor()
{
    unsigned long long int i,j,d,m,power;
    for(i=1; i<=max; i++)
    {
        d=1;
        m=i;
        for(j=0; prime[j]*prime[j]<=m; j++)
        {
            if(m==2||(m%2==1&&status[m]==0))
            {
                d=d*2;
                m=1;
                break;
            }
            if(m==1)
                break;
            power=0;
            while(m%prime[j]==0)
            {
                power++;
                m=m/prime[j];
            }
            d=d*(power+1);
        }
        if(m>1)
            d=d*2;
        divid[i]=d;
    }
}


int main()
{
    unsigned long long int T,n,l,mx,id;
    primeCheck();
    divisor();
    mx=divid[1];
    mxid[1]=1;
    for(l=2; l<=max; l++)
    {
        if(divid[l]>=mx)
        {
            mx=divid[l];
            id=l;
        }
        mxid[l]=id;
    }
    cin>>T;
    while(T--)
    {
        cin>>n;
        cout<<mxid[n]<<endl;
    }
    return 0;
}
