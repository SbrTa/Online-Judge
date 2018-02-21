#include<bits/stdc++.h>
using namespace std;

int np,nk,mx[22],visited[1011],match[1011];
vector<int>graph[22];


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

bool maxBPM()
{
    int i,j;
    for(i=0;i<=np;i++) match[i]=0;
    for(i=1;i<=nk;i++){
        //for(j=0;j<=np;j++) visited[j]=0;
        while(mx[i]--){
            for(j=0;j<=np;j++) visited[j]=0;
            if(bpm(i)==false) return false;
        }
    }
    return true;
}

int main()
{
    int i,j,n,a;
    while(scanf("%d%d",&nk,&np)==2){
        if(!nk && !np) break;
        for(i=1;i<=nk;i++){
            scanf("%d",&mx[i]);
            graph[i].clear();
        }
        for(i=1;i<=np;i++){
            scanf("%d",&n);
            while(n--){
                scanf("%d",&a);
                graph[a].push_back(i);
            }
        }
        bool f = maxBPM();
        printf("%d\n",f);
        if(!f) continue;
        for(i=1;i<=nk;i++){
            f=false;
            for(j=1;j<=np;j++){
                if(match[j]==i){
                    if(f==true) printf(" ");
                    printf("%d",j);
                    f=true;
                }
            }
            printf("\n");
        }
    }
    return 0;
}
