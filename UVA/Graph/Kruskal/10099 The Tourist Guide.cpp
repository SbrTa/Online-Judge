#include<bits/stdc++.h>
using namespace std;
#define mx 1000

int par[mx];
vector<pair<int,pair<int,int> > >edge;
int node,edg,start,stop,total;

int Find(int r)
{
    if(par[r]==r)
        return r;
    return par[r]=Find(par[r]);
}

int kruskal()
{
    for(int i=0;i<=node;i++)
        par[i]=i;
    for(int i=0;i<edge.size();i++)
    {
        int u = Find(edge[i].second.first);
        int v = Find(edge[i].second.second);
        if(u!=v)
            par[u]=v;
        if(Find(start)==Find(stop))
            return --edge[i].first;
    }
}


int main()
{
    int cs=1;
    while(cin>>node>>edg)
    {
        if(node==0&&edg==0)
            break;
        edge.clear();
        for(int i=0;i<edg;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            edge.push_back(make_pair(w,make_pair(u,v)));
        }
        sort(edge.begin(),edge.end());
        reverse(edge.begin(),edge.end());
        cin>>start>>stop>>total;
        cout<<"Scenario #"<<cs++<<endl;
        cout<<"Minimum Number of Trips = ";
        if(start==stop)
        {
            cout<<"0\n";
            continue;
        }
        int n=kruskal();
        int trip=total/n;
        if(total%n)
            trip++;
        cout<<trip<<endl<<endl;
    }
    return 0;
}
