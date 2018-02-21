#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define inf 1000000
using namespace std;

bool check[inf];
vector<long>v;

long digit(long n)
{
    long m=0;
    while(n!=0)
    {
        m=m+n%10;
        n/=10;
    }
    return m;
}

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
    v.push_back(0); //0
    v.push_back(0); //1
    v.push_back(1); //2
    long l=1;
    for(i=3;i<=inf;i++)
    {
        if(i%2==1 && check[i]==true)
        {
            long d = digit(i);
            if((d>1 && d%2==1 && check[d]==true) || d==2)
                l++;
        }
        v.push_back(l);
    }
}

int main()
{
    PRIME();
    long n,a,b;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        int add=0,d=digit(a);
        if( (a%2==1 && check[a]==true && ((d%2==1 && check[d]==true) ||d==2) )  || a==2)
            add=1;
        cout<<v[b]-v[a]+add<<endl;
    }
    return 0;
}
