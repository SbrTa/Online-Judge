#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#define inf 3200
#define eps 1e-9
using namespace std;

vector<int>prime;
bool chk[inf];

void Prime()
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
}

/*
long Find(long a, long lcm)
{
    vector<pair<long,long> >v;
    long i,j,ans=1;

    long size=prime.size();
    for(i=0;i<size;i++)
    {
        if(lcm==1) break;
        long cnt=0;
        while(lcm%prime[i]==0)
        {
            lcm = lcm/prime[i];
            cnt++;
        }
        if(cnt) v.push_back(make_pair(prime[i],cnt));
    }
    if(lcm!=1) v.push_back(make_pair(lcm,1));

    size=v.size();
    for(i=0;i<size;i++)
    {
        long p=v[i].first, n=v[i].second;
        while(a%p==0)
        {
            a=a/p;
            n--;
        }
        if(n)  ans=ans*pow(p,v[i].second);
        //cout<<"ans="<<ans<<endl;
    }

    return ans;
}
*/
long Find(long a, long lcm)
{
    vector<pair<long,long> >v;
    long i,j,ans=1;

    long size=prime.size();
    for(i=0;i<size;i++)
    {
        if(a==1) break;
        long cnt=0,cnt2=0;
        while(lcm%prime[i]==0)
        {
            lcm = lcm/prime[i];
            cnt++;
        }
        while(a%prime[i]==0)
        {
            a=a/prime[i];
            cnt2++;
        }
        if(cnt-cnt2) ans=ans*pow(prime[i],cnt);
    }
    if(a>1) lcm=lcm/a;
    ans=ans*lcm;

    return ans;
}


int main()
{
    Prime();
    long a,b,lcm,t;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld%ld",&a,&lcm);
        if(lcm%a)
        {
            printf("NO SOLUTION\n");
            continue;
        }

        b=Find(a,lcm);
        printf("%ld\n",b);
    }
    return 0;
}
