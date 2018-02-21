#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 1000002
using namespace std;

bool check[inf+5];
vector<long>prime;
vector<int>v,w;

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

void Pre()
{
    long i,j,n,m;
    v.push_back(0);  //0
    w.push_back(0);  //0
    v.push_back(1);  //1
    w.push_back(1);  //1
    v.push_back(-1);  //2
    w.push_back(0);  //2
    for(n=3;n<=1000000;n++)
    {
        if(n%2 && check[n]==true)
        {
            v.push_back(-1);
            w.push_back(w[n-1]-1);
            continue;
        }

        int in=0;
        for(i=0;prime[i]*prime[i]<=n;i++)
        {
            if(n%prime[i]==0)
            {
                if(v[n/prime[i]]==0 || n%(prime[i]*prime[i])==0)
                    in=0;
                else if(v[n/prime[i]]==1)
                    in=-1;
                else in=1;
                break;
            }
        }
        v.push_back(in);
        w.push_back(w[n-1]+in);
    }
}

int main()
{
    PRIME();
    Pre();
    long n;
    while(scanf("%ld",&n)==1 && n)
        printf("%8ld%8d%8d\n",n,v[n],w[n]);
    return 0;
}
