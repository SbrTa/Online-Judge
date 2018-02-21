#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 2706363+5
#define MX 2706363+2
using namespace std;

bool check[inf+2];
vector<long>prime,v;

void Prime()
{
    long i,j;
    for(i=3; i<=inf; i+=2)
        check[i]=true;
    for(i=3; i*i<=inf; i+=2)
    {
        for(j=i*i; j<=inf; j+=i+i)
            check[j]=false;
    }
    prime.push_back(2);
    for(i=3; i<=inf; i+=2)
        if(check[i]==true) prime.push_back(i);
    prime.push_back(inf+5);
}

void CF()
{
    v.push_back(0);  //0
    v.push_back(0);  //1
    v.push_back(1);  //2

    long ans,i,n;
    for(n=3; n<=MX; n++)
    {
        if(n%2 && check[n]==true)
        {
            v.push_back(1);
            continue;
        }
        for(i=0; ; i++)
        {
            if(n%prime[i]==0)
            {
                v.push_back(v[n/prime[i]] + 1);
                break;
            }
        }
    }
    for(i=2;i<=MX;i++) v[i]=v[i]+v[i-1];
}

int main()
{
    Prime();
    CF();
    long test,n,i,ans;
    scanf("%ld",&test);
    while(test--)
    {
        scanf("%ld",&n);
        long ans = upper_bound(v.begin(),v.end(),n) - v.begin();
        //for(ans=0;v[ans]<=n;ans++);
        printf("%ld\n",ans);
    }
    return 0;
}
