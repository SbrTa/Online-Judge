#include<bits/stdc++.h>
using namespace std;

long par[50000+5],rank[50000+5];

long Find(long p){
    return (par[p]==p)?p:Find(par[p]);
}

int main()
{
    long t=1,n,m,a,b,u,v;
    while(cin>>n>>m&&n!=0&&m!=0)
    {
        for(long i=0;i<=n;i++)
        {
            par[i]=i;
            rank[i]=0;
        }
        while(m--)
        {
            cin>>a>>b;
            u=Find(a);
            v=Find(b);
            if(u!=v)
            {
                n--;
                if(rank[u]>rank[v])
                    swap(u,v);
                if(rank[u]==rank[v])
                    rank[v]++;
                par[u]=v;
            }
        }
        printf("Case %ld: %ld\n",t++,n);
    }
    return 0;
}
