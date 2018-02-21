#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 31700
using namespace std;

bool check[inf];
vector<int>prime;

void PRIME()
{
    long i,j;
    for(i=3;i<=inf;i+=2)
        check[i]=true;
    for(i=3;i*i<=inf;i+=2)
    {
        if(check[i]==true)
        {
            for(j=i*i;j<=inf;j+=i+i)
                check[j]=false;
        }
    }
    prime.push_back(2);
    for(i=3;i<=inf;i+=2)
        if(check[i]==true) prime.push_back(i);
}


int main()
{
    PRIME();
    long n,ans,i,j;
    while(scanf("%ld",&n)==1 && n)
    {
        int s=prime.size();
        ans=1;
        for(i=0;prime[i]*prime[i]<=n;i++)
        {
            int c=0;
            while(n%prime[i]==0)
            {
                c++;
                n/=prime[i];
            }
            if(c) ans = ans * pow(prime[i],c-1) * (prime[i]-1);
        }
        if(n>1) ans=ans * (n-1);
        printf("%ld\n",ans);
    }
    return 0;
}
