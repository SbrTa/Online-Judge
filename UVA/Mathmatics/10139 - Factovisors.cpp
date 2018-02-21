#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 46345 //sqrt(2^31)
using namespace std;

bool check[inf];
vector<long>v;

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
    v.push_back(2);
    for(i=3;i<=inf;i+=2)
        if(check[i]==true) v.push_back(i);
}

bool Divisibility(long n, long b)
{
    long i,j;
    vector<pair<long,long> >base;
    for(i=0;v[i]*v[i]<=b;i++)
    {
        long cnt=0;
        while(b%v[i]==0)
        {
            cnt++;
            b=b/v[i];
        }
        if(cnt) base.push_back(make_pair(v[i],cnt));
    }
    if(b!=1) base.push_back(make_pair(b,1));

    long f=0;
    for(i=0;i<base.size();i++)
    {
        long p=base[i].first,cnt=0;
        while(p<=n)
        {
            cnt = cnt+(n/p);
            p=p*base[i].first;
        }
        if(cnt<base[i].second) {f=1;break;}

    }
    if(f==0) return true;
    return false;
}

int main()
{
    PRIME();
    long n,b;
    while(cin>>n>>b)
    {
        bool chk;
        chk = Divisibility(n,b);
        if(chk==true) printf("%ld divides %ld!\n",b,n);
        else printf("%ld does not divide %ld!\n",b,n);
    }
    return 0;
}
