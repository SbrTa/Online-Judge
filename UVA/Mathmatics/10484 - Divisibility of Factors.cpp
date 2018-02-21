#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<cstdlib>
#include<cmath>
#include<climits>
#define inf INT_LIMIT
#define eps 1e-9
using namespace std;

vector<int>prime;
vector<pair<int,int> >v;

void PRIME()
{
    int i,j;
    bool chk[111];
    for(i=3;i<=100;i+=2)
        chk[i]=true;
    for(i=3;i*i<=100;i+=2)
    {
        if(chk[i]==true)
        {
            for(j=i*i;j<=100;j+=i+i)
                chk[j]=false;
        }
    }
    prime.push_back(2);
    for(i=3;i<=100;i+=2)
        if(chk[i]==true) prime.push_back(i);
}

void find_divisors_of_n(long n)
{
    long i,j,cnt;
    for(i=0;i<prime.size();i++)
    {
        cnt=0;
        int t=prime[i];
        while(t<=n)
        {
            cnt = cnt + (n/t);
            t = t * prime[i];
        }
        if(cnt) v.push_back(make_pair(prime[i],cnt));
    }
}

bool remove_divisors_of_d(long d)
{
    long i,j;
    for(i=0;i<v.size();i++)
    {
        if(d==1) break;
        while(d%v[i].first==0)
        {
            v[i].second--;
            d=d/v[i].first;
        }
        if(v[i].second<0) return false;
    }
    if(d!=1) return false;
    return true;
}

int main()
{
    PRIME();
    long n,d,i,j;
    while(cin>>n>>d)
    {
        if(!n && !d) break;
        n=abs(n);
        d=abs(d);
        if(d==0)
        {
            cout<<'0'<<endl;
            continue;
        }
        v.clear();
        find_divisors_of_n(n);
        if(remove_divisors_of_d(d)==false)
        {
            cout<<'0'<<endl;
            continue;
        }
        long ans=1;
        for(i=0;i<v.size();i++)
            ans=ans*(v[i].second+1);
        cout<<ans<<endl;
    }
    return 0;
}
