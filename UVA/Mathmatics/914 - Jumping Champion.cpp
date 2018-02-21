#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
#define inf 1000000+10
using namespace std;

bool check[inf];
vector<long>v;
long dif[78499+10][114+10];

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

void PRE()
{
    memset(dif,0,sizeof(dif));
    long i,j,d;
    for(i=1; i<v.size(); i++)
    {
        d = v[i] - v[i-1];
        dif[i][d] = dif[i-1][d] + 1;
        for(j=1; j<=125; j++)
            if(j!=d)    dif[i][j] = dif[i-1][j];
    }
}

int main()
{
    PRIME();
    PRE();

    long t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(a>b) swap(a,b);
        long low = lower_bound(v.begin(),v.end(),a) - v.begin();
        long up = upper_bound(v.begin(),v.end(),b) - v.begin();
        if(up-low<2)
        {
            cout<<"No jumping champion\n";
            continue;
        }
        //cout<<low<<" "<<up<<endl;
        long mx=0,n,i,cnt=0;
        for(i=0; i<=125; i++)
        {
            long x = dif[up-1][i]-dif[low][i];

            if(x==mx)
                cnt++;
            if(x>mx)
            {
                cnt=1;
                mx=x;
                n=i;
            }
        }
        if(cnt>=2)
            cout<<"No jumping champion\n";
        else
            cout<<"The jumping champion is "<<n<<endl;
    }
    return 0;
}
