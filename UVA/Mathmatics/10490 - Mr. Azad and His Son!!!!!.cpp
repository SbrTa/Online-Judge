#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#define inf 0x7f7f
using namespace std;

struct info
{
    long long n;
    bool flag;
}st;

vector<info>v;

bool isprime(long long a)
{
    if(a==2 || a==1)    return true;
    if(a==0 || a%2==0)  return false;
    for(long long i=3; i*i<=a; i+=2)
        if(a%i==0)  return false;
    return true;
}

void PRE()
{
    long long i,m=1;
    st.n=0;
    st.flag=false;
    v.push_back(st);

    for(i=1;i<=31;i++)
    {
        st.flag=false;
        m=m*2;
        st.n = m-1;
        if(isprime(m-1)==true)
            st.flag=true;
        v.push_back(st);
    }
}

int main()
{
    PRE();
    long long a;
    while(cin>>a && a!=0)
    {
        if(!isprime(a))
        {
            printf("Given number is NOT prime! NO perfect number is available.\n");
            continue;
        }
        if(!v[a].flag)
        {
            printf("Given number is prime. But, NO perfect number is available.\n");
            continue;
        }
        printf("Perfect: %lld!\n",v[a].n * (v[a-1].n+1));
    }
    return 0;
}
