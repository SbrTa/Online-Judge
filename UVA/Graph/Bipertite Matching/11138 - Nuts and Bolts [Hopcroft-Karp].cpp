#include<bits/stdc++.h>
using namespace std;
#define inf 0x7f7f7f7f
vector<int>graph[505];
int n,m,dist[1005],match[1005];

bool bfs()
{
    int i,j,u,v;
    queue<int>q;
    for(i=1;i<=n;i++){
        if(!match[i]){
            dist[i]=0;
            q.push(i);
        }
        else dist[i]=inf;
    }
    dist[0]=inf;
    while(!q.empty()){
        u=q.front();
        q.pop();
        if(!u) continue;
        for(i=0;i<graph[u].size();i++){
            v=graph[u][i];
            if(dist[match[v]]==inf){
                dist[match[v]] = dist[u] + 1;
                q.push(match[v]);
            }
        }
    }
    return dist[0]!=inf;
}

bool dfs(int u)
{
    if(!u) return true;
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        if(dist[match[v]] == dist[u]+1){
            if(dfs(match[v])){
                match[u]=v;
                match[v]=u;
                return true;
            }
        }
    }
    dist[u]=inf;
    return false;
}


int hopcroft_karp()
{
    int cnt=0,i;
    while(bfs()){
        for(i=1;i<=n;i++){
            if(!match[i] && dfs(i)) cnt++;
        }
    }
    return cnt;
}

int main()
{
    int test,cs=1;
    int i,j,a;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        for(i=0; i<=n+m; i++)
            dist[i]=0,
            match[i]=0;
        for(i=1; i<=n; i++)
        {
            graph[i].clear();
            for(j=1; j<=m; j++)
            {
                scanf("%d",&a);
                if(a) graph[i].push_back(j+n);
            }
        }
        //cout<<mBPM()<<endl
        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",cs++,hopcroft_karp());
    }
    return 0;
}

