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

int check[inf];
vector<int>v;

void PRIME()
{
    int i,j;
    for(i=3;i<=inf;i+=2)
        check[i]=0;
    for(i=3;i*i<=inf;i+=2)
    {
        if(check[i]==0)
        {
            for(j=i*i;j<=inf;j+=i+i)
                check[j]=1;
        }
    }
    v.push_back(2);
    for(i=3;i<=inf;i+=2)
        if(check[i]==0) v.push_back(i);
}

int main()
{
    PRIME();
    int n,i,j;
    while(scanf("%d",&n)==1 && n!=0)
    {
        int start=lower_bound(v.begin(),v.end(),n)-v.begin();
        --start;
        int cnt=0;
        for(i=start; ;i--)
        {
            if(v[i]+v[i]<n)
                break;
            for(j=0;j<=i;j++)
            {
                if(v[i]+v[j]==n)
                    cnt++;
                if(v[i]+v[j]>n)
                    break;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
