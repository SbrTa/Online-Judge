#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#define inf 100000000
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
        if(check[i]==true)  v.push_back(i);
}

int main()
{
    PRIME();
    long n,i,j;
    while(scanf("%ld",&n)==1)
    {
        long d=inf,a,b;
        if(n%2==1)
        {
            if(check[n-2]==true)
                printf("%ld is the sum of 2 and %ld.\n",n,n-2);
            else
                printf("%ld is not the sum of two primes!\n",n);
            continue;
        }
        bool flag = false;
        long l = upper_bound(v.begin(),v.end(),ceil(n/2))-v.begin()-1;
        for(i=l;i>=0;i--)
        {
            long m = n-v[i];
            if(m==v[i])
                continue;
            if((m>1 && m%2==1 && check[m]==true) || m==2)
            {
                d=m-v[i];
                a=min(v[i],m);
                b=max(v[i],m);
                flag=true;
                break;
            }
        }
        if(flag==true)
            printf("%ld is the sum of %ld and %ld.\n",n,a,b);
        else
            printf("%ld is not the sum of two primes!\n",n);
    }
    return 0;
}

