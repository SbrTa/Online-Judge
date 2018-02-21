#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
#define inf 46340+1000
using namespace std;

bool check[inf];
vector<long>v;

void PRIME()
{
    long i,j;
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
    v.push_back(2);
    for(i=3; i<=inf; i+=2)
    {
        if(check[i]==true)
            v.push_back(i);
    }
}


int main()
{
    PRIME();
    long n,i,j;
    while(cin>>n && n)
    {
        if(n<0)  printf("%ld = -1 x ",n),n=n*(-1);
        else     printf("%ld = ",n);
        bool x=true;
        for(i=0;i<v.size();i++)
        {
            while(n%v[i]==0)
            {
                n=n/v[i];
                if(x==true) cout<<v[i],x=false;
                else printf(" x %ld",v[i]);
            }
            if(n==1)
                break;
        }
        if(n>1 && x==true) cout<<n;
        else if(n>1 && x==false) printf(" x %ld",n);
        cout<<endl;
    }
    return 0;
}
