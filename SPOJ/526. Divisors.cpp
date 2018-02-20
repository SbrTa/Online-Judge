#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 999930
using namespace std;

bool check[inf+2];
vector<long>p;
long v[inf+2];

void Prime()
{
    long i,j,mx=0;
    for(i=2; i<=inf; i++)
    {
        check[i]=true;
        v[i]=2;
    }
    check[1]=false;
    for(i=2; i<=inf/2; i++)
    {
        for(j=i+i; j<=inf; j+=i)
        {
            check[j]=false;
            v[j]++;
            //if(v[j]>mx) mx=v[j];
        }
    }
    //cout<<mx<<endl;
    p.push_back(2);
    for(i=3; i<128; i+=2)
        if(check[i]==true) p.push_back(i);
}

int main()
{
    Prime();
    //cout<<v[999927]<<endl;
    long i,j,n=0;
    for(i=3; i<inf; i++)
    {
        if(v[i]%2==1 && check[v[i]]==true)
            continue;
        for(j=0; p[j]*p[j]<v[i]; j++)
        {
            if(v[i]%p[j]==0)
            {
                long d=v[i]/p[j];
                if((d%2==1 && check[d]==true) || d==2)
                {
                    n++;
                    if(n%9==0)
                        printf("%ld\n",i);
                    //printf("%ld = %ld\n",i,v[i]);
                    break;
                }
            }
        }
    }
    return 0;
}

