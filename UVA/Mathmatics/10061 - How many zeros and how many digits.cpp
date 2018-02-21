#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<cstdlib>
#include<algorithm>
#include<climits>
#define inf 0x7f7f
#define pMax 30 //sqrt(800)
#define eps 1e-9
using namespace std;

vector<int>prime;
map<int,int>mp;

void PRIME()
{
    bool chk[pMax];
    int i,j;
    for(i=3;i<=pMax;i+=2) chk[i]=true;
    for(i=3;i*i<=pMax;i+=2)
    {
        if(chk[i])
            for(j=i*i;j<=pMax;j+=i+i) chk[j]=false;
    }
    prime.push_back(2);
    for(i=3;i<=pMax;i+=2) if(chk[i]) prime.push_back(i);
}


int frequency(int n, int b)
{
    double ans=0;
    for(int i=2;i<=n;i++)
        ans=ans+log10(i);
    ans=ans/log10(b);
    ans = floor(ans+eps)+1;
    return ans;
}

void BaseFactorization(int b)
{
    for(int i=0;i<prime.size()&&b>1;i++)
    {
        while(b%prime[i]==0)
        {
            mp[prime[i]]++;
            b=b/prime[i];
        }
    }
    if(b>1) mp[b]++;
}

int TZ(int n, int fact)
{
    int ans=0;
    while(n)
    {
        ans = ans+n/fact;
        n=n/fact;
    }
    return ans;
}



int main()
{
    PRIME();
    int n,b;
    while(cin>>n>>b)
    {
        int freq = frequency(n,b);

        mp.clear();
        BaseFactorization(b);
        int zero = INT_MAX;
        map<int,int>::iterator i;

        for(i=mp.begin();i!=mp.end();i++)
            zero = min( zero, TZ(n,(*i).first) / (*i).second );

        printf("%d %d\n",zero,freq);
    }
    return 0;
}
