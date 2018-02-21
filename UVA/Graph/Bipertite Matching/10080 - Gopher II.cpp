#include<bits/stdc++.h>
using namespace std;

int n,m,s,v;
int match[111],visited[111];
vector<int>graph[111];

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

int MaxBPM()
{
    int i,j,cnt=0;
    for(i=1;i<=m;i++) match[i]=0;
    for(i=1;i<=n;i++){
        for(j=0;j<=m;j++) visited[j]=0;
        if(bpm(i)==false) cnt++;
    }
    return cnt;
}

int main()
{
    int i,j,k,l;
    float gopherX[111],gopherY[111],holeX[111],holeY[111];
    while(scanf("%d%d%d%d",&n,&m,&s,&v)==4){
        for(i=1;i<=n;i++) scanf("%f%f",&gopherX[i],&gopherY[i]);
        for(i=1;i<=m;i++) scanf("%f%f",&holeX[i],&holeY[i]);

        for(i=1;i<=n;i++){
            graph[i].clear();
            for(j=1;j<=m;j++){
                float dist = sqrt(( (gopherX[i]-holeX[j])*(gopherX[i]-holeX[j]) ) +
                                  ( (gopherY[i]-holeY[j])*(gopherY[i]-holeY[j]) ));
                float time =  dist / (float)v;
                int t = ceil(time);
                if(t<=s) graph[i].push_back(j);
            }
        }
        int ans = MaxBPM();
        printf("%d\n",ans);
    }
    return 0;
}
