#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#define inf 65536 //sqrt(2^32)
#define eps 1e-9
using namespace std;

bool chk[inf+2];
vector<long>prime;

void Prime()
{
    long i,j;
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
}

long FindPower(long long n)
{
    long i,j,p=0,s=prime.size();
    vector<long>v;
    for(i=0;prime[i]*prime[i]<=n;i++)
    {
        if(n==1) break;
        long cnt=0;
        while(n%prime[i]==0)
        {
            n=n/prime[i];
            cnt++;
        }
        if(cnt) v.push_back(cnt);
    }
    if(n>1) v.push_back(1);

    sort(v.begin(),v.end());
    if(v[0]==1) return 1;
    p=v[0];
    for(i=1;i<v.size();i++)
    {
        if(v[i]%p)
            return 1;
    }
    return p;
}

int main()
{
    Prime();
    long long n,i,j;
    while(scanf("%lld",&n)==1 && n)
    {
        int f=0;
        if(n<0)
        {
            n=-n;
            f=1;
        }
        //cout<<n<<endl;
        long ans=FindPower(n);
        while(f==1 && ans%2==0)
            ans=ans/2;
        printf("%ld\n",ans);
    }
    return 0;
}
