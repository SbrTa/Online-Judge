#include<bits/stdc++.h>
using namespace std;

vector<int>graph[10];
int n,m,visited[40],match[40];

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

bool maxBpm()
{
    int i,j,f=0;
    for(i=0;i<=m;i++) match[i]=0;
    for(i=1;i<=6;i++){
        int t=n/6;
        while(t--){
            for(j=0;j<=m;j++) visited[j]=0;
            if(bpm(i)) f++;
            if(f==m) return true;
        }
    }
    return false;
}

int main()
{
    map<string,int>mp;
    mp["XXL"] = 1;
    mp["XL"] = 2;
    mp["L"] = 3;
    mp["M"] = 4;
    mp["S"] = 5;
    mp["XS"] = 6;

    int test,i,j;
    char a[10],b[10];
    scanf("%d",&test);
    while(test--){
        scanf("%d%d",&n,&m);
        for(i=0;i<=6;i++) graph[i].clear();
        for(i=1;i<=m;i++){
            scanf("%s%s",a,b);
            //printf("%s %s\n",a,b);
            graph[mp[a]].push_back(i);
            graph[mp[b]].push_back(i);
        }
        if(maxBpm()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
