#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define inf 10000+1
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
        if(check[i]==true)  v.push_back(i);
}

int main()
{
    PRIME();
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int low = upper_bound(v.begin(),v.end(),ceil(n/2)) - v.begin();
        cout<<v[low]<<endl;
    }
    return 0;
}
