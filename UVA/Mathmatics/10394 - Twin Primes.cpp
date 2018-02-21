#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 20000000
using namespace std;

struct info
{
    long a,b;
} in;

vector<info>v;
bool check[inf];

void PRIME()
{
    int i,j;
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
    v.push_back(in);
    for(i=3; i<=inf; i+=2)
    {
        if(check[i] && check[i+2])
        {
            in.a=i;
            in.b=i+2;
            v.push_back(in);
        }
    }
}

int main()
{
    PRIME();
    long n;
    while(cin>>n)
        printf("(%ld, %ld)\n",v[n].a,v[n].b);
    return 0;
}
