#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 500000 //sqrt(500000)
using namespace std;

bool check[inf+5];
vector<int>prime;

void Prime()
{
    int i,j;
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
    prime.push_back(inf);
}

vector<int>v;

void Pre()
{
    long i,j,n,m,s,c;
    v.push_back(0);
    v.push_back(1);
    for(j=2;j<=500000;j++)
    {
        if(j==2 || (j%2==1 && check[j]==true))
        {
            v.push_back(1);
            continue;
        }
        n=m=j;
        c=0;
        while(1)
        {
            c++;
            s=0;
            for(i=0;prime[i]*prime[i]<=n;i++)
            {
                while(n%prime[i]==0)
                {
                    n/=prime[i];
                    s+=prime[i];
                }
            }
            if(n>1) s+=n;
            if(s==m) break;
            if(s<j)
            {
                c=c+v[s];
                break;
            }
            n=s;
            m=s;
        }
        v.push_back(c);
    }
}


int main()
{
    Prime();
    Pre();
    long low,up,i,mx,test,cs=1;
    scanf("%ld",&test);
    while(test--)
    {
        scanf("%ld%ld",&low,&up);
        if(low>up) swap(low,up);
        mx=-1;
        for(i=low;i<=up;i++)
            if(v[i]>mx) mx=v[i];
        printf("Case #%ld:\n%ld\n",cs++,mx);
    }
    return 0;
}
