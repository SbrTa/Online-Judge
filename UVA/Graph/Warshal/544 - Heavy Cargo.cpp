#include<cstdio>
#include<iostream>
#include<map>
#include<string.h>
#define inf 0x7f7f
using namespace std;

int graph[202][202];
map<string,int>mp;

void MaxMinWarshal(int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                graph[i][j]=max(graph[i][j],min(graph[i][k],graph[k][j]));
}

int main()
{
    int n,edg,i,j,w,cs=1;
    string a,b;
    while(cin>>n>>edg)
    {
        if(n==0&&edg==0)
            break;
        memset(graph,0,sizeof(graph));
        mp.clear();
        int m=1;
        for(i=0;i<edg;i++)
        {
            cin>>a>>b>>w;
            if(mp[a]==0)
                mp[a]=m++;
            if(mp[b]==0)
                mp[b]=m++;
            graph[mp[a]][mp[b]]=w;
            graph[mp[b]][mp[a]]=w;
        }

        MaxMinWarshal(n);
        cin>>a>>b;
        cout<<"Scenario #"<<cs++<<endl;
        cout<<graph[mp[a]][mp[b]]<<" tons\n\n";
    }
    return 0;
}
