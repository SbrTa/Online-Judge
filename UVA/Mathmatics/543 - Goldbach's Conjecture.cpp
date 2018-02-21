#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 1000001
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

int main()
{
    PRIME();
    long n,i,j;
    while(scanf("%ld",&n)==1 && n!=0)
    {
        int flag=0;
        for(i=0;v[i]+v[i]<=n;i++)
        {
            long temp = n-v[i];
            if((temp%2==1 && check[temp]==true))
            {
                long mn = min(v[i],temp);
                long mx = max(v[i],temp);
                printf("%ld = %ld + %ld\n",n,mn,mx);
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}

