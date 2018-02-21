#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#define inf 1000006
#define MX 1000000000000+12
using namespace std;

vector<long long>v;
vector<long>p;
bool chk[inf];

void prime()
{
    long i,j;
    for(i=3;i<=inf;i+=2) chk[i]=true;

    for(i=3;i*i<=inf;i++)
    {
        if(chk[i]==true)
        {
            for(j=i*i;j<=inf;j+=i+i)
                chk[j]=false;
        }
    }
    p.push_back(2);
    for(i=3;i<=inf;i+=2)
        if(chk[i]==true) p.push_back(i);
    //cout<<p.size()<<endl;
}


int main()
{
    prime();
    long long i,j,n,a,b,t;
    for(i=0;i<p.size();i++)
    {
        n=p[i];
        while(n*p[i]<=MX)
        {
            n=n*p[i];
            v.push_back(n);
        }
    }
    //cout<<v.size()<<endl;
    sort(v.begin(),v.end());

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        long up = upper_bound(v.begin(),v.end(),b) - v.begin();
        long low = lower_bound(v.begin(),v.end(),a) - v.begin();
        printf("%ld\n",up-low);
    }
    return 0;
}
