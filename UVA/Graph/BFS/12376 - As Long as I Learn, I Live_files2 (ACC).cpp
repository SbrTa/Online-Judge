#include<bits/stdc++.h>
using namespace std;
vector<int>edges[110];
int a[110];

void bfs(int n, int source, int t)
{
    int taken[110],source2,max=0,i,j,v,vv;
    memset(taken,0,sizeof taken);
    taken[source]=1;
    while(1)
    {
        int size=edges[source].size();
        int m=-1;
        if(size==1&&taken[edges[source][0]]==1 || size==0)
            break;
        for(i=0; i<size; i++)
        {
            v=edges[source][i];
            if(taken[v]==0)
            {
                if(a[v]>m)
                {
                    m=a[v];
                    vv=v;
                    source2=v;
                }
            }
        }
        source=source2;
        taken[vv]=1;
        max=max+m;
    }
    printf("Case %d: %d %d\n",t,max,vv);
}

int main()
{
    int n=0,e,i,x,y,t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        for(i=0;i<n;i++)
            edges[i].clear();
        scanf("%d%d",&n,&e);
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(i=0; i<e; i++)
        {
            scanf("%d%d",&x,&y);
            edges[x].push_back(y);
        }
        bfs(n,0,t);
    }
    return 0;
}
