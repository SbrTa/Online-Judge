#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 1000+5
using namespace std;

bool check[inf+2];
vector<int>prime;
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
    prime.push_back(2);
    for(i=3;i<=inf;i+=2)
        if(check[i]==true) prime.push_back(i);
    prime.push_back(inf+5);
}

void Pre()
{
    v.push_back(0);  //0
    v.push_back(1);  //1
    v.push_back(2);  //2

    long n,i,j;
    for(i=2;v[i]<1000000;i++)
    {
        n=v[i];
        long ans=1;
        for(j=0;prime[j]*prime[j]<=n;j++)
        {
            int c=0;
            while(n%prime[j]==0)
            {
                c++;
                n/=prime[j];
            }
            ans=ans*(c+1);
        }
        if(n>1) ans=ans*2;
        v.push_back(v[i]+ans);
    }
}

int main()
{
    PRIME();
    Pre();
    long test,cs=1,a,b;
    scanf("%ld",&test);
    while(test--)
    {
        scanf("%ld%ld",&a,&b);
        long up = upper_bound(v.begin(),v.end(),b) - v.begin();
        long low = upper_bound(v.begin(),v.end(),a) - v.begin();
        if(v[low-1]==a) low--;
        //cout<<v[low-1]<<" "<<v[low]<<endl;
        //cout<<v[up-1]<<" "<<v[up]<<endl;
        printf("Case %ld: %ld\n",cs++,up-low);
    }
    return 0;
}
