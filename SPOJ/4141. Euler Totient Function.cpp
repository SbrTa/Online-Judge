
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 1000+100 //sqrt(10^6)
using namespace std;

bool check[inf];
vector<int>v;

void PRIME()
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
    v.push_back(2);
    for(i=3;i<=inf;i+=2)
        if(check[i]==true) v.push_back(i);
}

long CoPrime(long n)
{
    long i,j,ans=1;
    for(i=0;i<v.size();i++)
    {
        if(n==1) break;
        if(v[i]*v[i]>n) break;
        long cnt=0;
        while(n%v[i]==0)
        {
            n=n/v[i];
            cnt++;
        }
        if(cnt) ans = ans * ( pow(v[i],cnt-1) * (v[i]-1) );
    }
    if(n!=1) ans=ans*(n-1);
    return ans;
}



int main()
{
    PRIME();
    long t,n,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long cnt = CoPrime(n);
        cout<<cnt<<endl;
    }
    return 0;
}
