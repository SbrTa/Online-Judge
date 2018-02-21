#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#define inf 1048576+10
using namespace std;

bool chk[inf+5];
vector<long>nPrime;
void CompositePrime()
{
    long i,j;
    for(i=1;i<=inf;i+=2) chk[i]=true;
    for(i=2;i<=inf;i+=2) chk[i]=false;
    chk[2]=true;
    for(i=3;i*i<=inf;i+=2)
    {
        if(chk[i]==true)
        {
            for(j=i*i;j<=inf;j+=i+i)
                chk[j]=false;
        }
    }

    for(i=2;i<=inf;i++)
    {
        if(chk[i]==true) continue;
        for(j=i+i;j<=inf;j+=i)
            chk[j]=true;
    }
}

int main()
{
    CompositePrime();
    long n,a,i;
    while(scanf("%ld",&n)==1)
    {
        long ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%ld",&a);
            if(chk[a]==false) ans++;
        }
        printf("%ld\n",ans);
    }
    return 0;
}
