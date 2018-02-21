#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 46340+100 //sqrt(2^31)
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

long long MinSum(long long m)
{
    long long ans=0,i,j,n=m,c=0,x=0;
    for(i=0;i<v.size();i++)
    {
        if(n==1) break;
        if(v[i]*v[i]>n) break;
        long long cnt=0;
        while(n%v[i]==0)
        {
            if(x!=v[i])
            {
                x=v[i];
                c++;
            }
            if(cnt==0) cnt=1;
            n=n/v[i];
            cnt=cnt*v[i];
        }
        if(cnt) ans=ans+cnt;
    }
    if(n==m) ans=m+1;
    else if(n!=1)
    {
        ans=ans+n;
        if(x!=n) c++;
    }
    else if(c<=1) ans=m+1;
    return ans;
}



int main()
{
    PRIME();
    //printf("%lld\n",v[v.size()-1]*v[v.size()-1]);
    long long n,i,j,cs=1;
    while(cin>>n && n)
    {
        long long ans = MinSum(n);
        printf("Case %lld: %lld\n",cs++,ans);
    }
    return 0;
}
