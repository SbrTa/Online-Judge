#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int>graph[111];
int visited[111],match[111];

bool bpm(int u)
{
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        if(visited[v]) continue;
        visited[v]=1;
        if(!match[v] || bpm(match[v])){
            match[v]=u;
            return true;
        }
    }
    return false;
}

int maxBpm()
{
    int i,j,cnt=0;
    for(i=0;i<=m;i++) match[i]=0;
    for(i=1;i<=n;i++){
        for(j=0;j<=m;j++) visited[j]=0;
        if(bpm(i)) cnt++;
    }
    return cnt;
}

int main()
{
    int test,cs=1;
    int a[111],x,i,j;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            graph[i].clear();
        }
        scanf("%d",&m);
        for(i=1;i<=m;i++){
            scanf("%d",&x);
            for(j=1;j<=n;j++){
                if(!a[j] && !x) graph[j].push_back(i);
                if(!a[j]) continue;
                if(x%a[j]==0) graph[j].push_back(i);
            }
        }
        printf("Case %d: %d\n",cs++,maxBpm());
    }
    return 0;
}
