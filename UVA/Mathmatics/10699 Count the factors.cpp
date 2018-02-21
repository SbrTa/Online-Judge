#include<bits/stdc++.h>
using namespace std;

#define max 1000000
unsigned long long int prime[max],status[max];

int main()
{
    unsigned long long int total=0,i,j;
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
    prime[total++]=2;
    for(i=3; i<=max; i+=2)
    {
        if(status[i]==0)
            prime[total++]=i;
    }


    unsigned long long int n,count;
    while(cin>>n)
    {
        if(n==0)
            break;
        count=0;
        for(i=0;i<total;i++)
        {
            if(prime[i]>n)
                break;
            if(n%prime[i]==0)
                count++;
        }
        printf("%llu : %llu\n",n,count);
    }
    return 0;
}
