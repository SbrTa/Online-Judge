#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define inf 10000007
using namespace std;

bool check[inf];
vector<long long>v;

void PRIME()
{
    long long i,j;
    for(i=3; i<=inf; i+=2)
        check[i]=true;
    for(i=3; i*i<=inf; i+=2)
    {
        if(check[i]==true)
        {
            for(j=i*i; j<=inf; j+=i+i)
                check[j]=false;
        }
    }
    v.push_back(2);
    for(i=3; i<=inf; i+=2)
        if(check[i]==true)  v.push_back(i);
}

int main()
{
    PRIME();
    long long n,i;
    while(cin>>n && n)
    {
        long long mx,cnt=0;
        n=abs(n);
        for(i=0; i<v.size(); i++)
        {
            if(n%v[i]==0)
            {
                while(n%v[i]==0)
                {
                    n=n/v[i];
                }
                cnt++;
                mx=v[i];
            }
            if(n==1 || v[i]*v[i]>n) break;
        }
        if(n==1)
        {
            if(cnt<=1) printf("-1\n");
            else printf("%lld\n",mx);
        }
        else
        {
            if(cnt<1)  printf("-1\n");
            else printf("%lld\n",n);
        }
    }
    return 0;
}
