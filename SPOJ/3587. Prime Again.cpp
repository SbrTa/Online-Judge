#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#define inf 1000000
using namespace std;

long chk[inf/64];
vector<long>v;

bool check(long n, long pos)
{
    return (bool)(n & (1<<pos));
}

long set(long n, long pos)
{
    return n = n | (1<<pos);
}


void PRIME()
{
    long i,j;
    for(i=3;i<=inf;i+=2)
        chk[i]=0;
    for(i=3;i*i<=inf;i+=2)
    {
        if(check(chk[i/64],i%64)==0)
        {
            for(j=i*i;j<=inf;j+=i+i)
                chk[j/64] = set(chk[j/64],j%64);
        }
    }
    v.push_back(2);
    for(i=3;i<=inf;i+=2)
        if(check(chk[i/64],i%64)==0)  v.push_back(i);
}

int main()
{
    long i,j;
    for(i=0;i<10;i++)
        cout<<v[i]<<endl;
}

