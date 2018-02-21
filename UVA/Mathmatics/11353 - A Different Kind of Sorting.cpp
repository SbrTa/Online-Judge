#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 2000000
using namespace std;

bool check[inf+5];
vector<long>prime;

void Prime()
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
    prime.push_back(inf);
}

struct info
{
    long d,p;
};

vector<info>v;

bool cmp(info a, info b)
{
    if(a.d<b.d) return true;
    if(a.d==b.d && a.p<b.p) return true;
    return false;
}

void Pre()
{
    long i,j,n,c;
    info in;
    in.p=1;
    in.d=1;
    v.push_back(in);
    v.push_back(in);
    for(i=2;i<=2000000;i++)
    {
        if(i==2 || (i%2 && check[i]==true))
        {
            in.p=i;
            in.d=1;
            v.push_back(in);
            continue;
        }
        n=i;
        c=0;
        int f=0;
        for(j=0;prime[j]*prime[j]<=n;j++)
        {
            if(n%prime[j]==0)
            {
                n/=prime[j];
                c=v[n].d+1;
                f=1;
                break;
            }
        }
        if(f==0) c++;
        in.p=i;
        in.d=c;
        v.push_back(in);
    }
    sort(v.begin(),v.end(),cmp);
}

int main()
{
    Prime();
    Pre();
    long n,cs=1;
    while(scanf("%ld",&n)==1 && n)
        printf("Case %ld: %ld\n",cs++,v[n].p);
    return 0;
}
