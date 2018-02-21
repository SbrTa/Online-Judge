#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 32768
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

int main()
{
    PRIME();
    int n,i,j;
    while(scanf("%d",&n)==1 && n!=0)
    {
        int cnt=0;
        for(i=0;v[i]+v[i]<=n;i++)
        {
            int temp = n-v[i];
            if((temp%2==1 && check[temp]==true) || temp==2)
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
