#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#define inf 225  //sqrt(50000)
using namespace std;

bool chk[inf+5];
vector<int>prime;

void PRIME()
{
    int i,j;
    for(i=3;i<=inf;i+=2)
        chk[i]=true;
    for(i=3;i*i<=inf;i+=2)
    {
        if(chk[i]==true)
        {
            for(j=i*i;j<=inf;j+=i+i)
                chk[j]=false;
        }
    }
    prime.push_back(2);
    for(i=3;i<=inf;i+=2)
        if(chk[i]==true) prime.push_back(i);
    prime.push_back(inf);
}

vector<long>ans;

long Co_Prime(long n)
{
    long i,cp=1;
    for(i=0;prime[i]*prime[i]<=n;i++)
    {
        long p=0;
        while(n%prime[i]==0)
        {
            p++;
            n/=prime[i];
        }
        if(p) cp = cp * pow(prime[i],p-1) * (prime[i]-1);
    }
    if(n>1) cp = cp * (n-1);
    return cp;
}

void PRE()
{
    long i,j,n;
    ans.push_back(0); //n=0
    ans.push_back(1); //n=1
    for(n=2;n<=50001;n++)
        ans.push_back( ans[n-1] + (Co_Prime(n)*2) );
}

int main()
{
    PRIME();
    PRE();
    long n;
    while(scanf("%ld",&n)==1 && n)
        printf("%ld\n",ans[n]);
    return 0;
}
