#include<bits/stdc++.h>
using namespace std;

vector<int>graph[505];
int n,m,visited[505],match[505];


bool BPM(int u)
{
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        if(visited[v])
            continue;
        visited[v]=1;
        if( !match[v] ||  BPM(match[v])){
            match[v]=u;
            return true;
        }
    }
    return false;
}

int mBPM()
{
    int i,j,u,ret=0;
    for(i=0;i<=m;i++) match[i]=0;
    for(u=1;u<=n;u++){
        for(i=0;i<=m;i++) visited[i]=0;
        if(BPM(u)) ret++;
    }
    return ret;
}

int main()
{
    int test,cs=1;
    int i,j,a;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        for(i=0; i<=n; i++) graph[i].clear();
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scanf("%d",&a);
                if(a) graph[i].push_back(j);
            }
        }
        //cout<<mBPM()<<endl
        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",cs++,mBPM());
    }
    return 0;
}
