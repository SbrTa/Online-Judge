#include<bits/stdc++.h>
using namespace std;

vector<long>v[22];

void vector_clear()
{
    for(long i=0; i<22; i++)
        v[i].clear();
}

long BFS(long source, long destination)
{
    queue<long>q;
    long i,j,visit[22],distance[22];
    memset(visit,0,sizeof(visit));
    memset(distance,0,sizeof(distance));
    q.push(source);
    visit[source]=1;
    while(!q.empty())
    {
        long n=q.front();
        long size=v[n].size();
        for(i=0; i<size; i++)
        {
            long m=v[n][i];
            if(visit[m]==0)
            {
                distance[m]=distance[n]+1;
                q.push(m);
                visit[m]=1;
            }
        }
        q.pop();
    }
    return distance[destination];
}

int main()
{
    long i,j,a,b,c,t,tt,T,TT=0,source,destination;
    while(cin>>t)
    {
        vector_clear();
        for(i=0; i<t; i++)
        {
            cin>>a;
            v[1].push_back(a);
            v[a].push_back(1);
        }
        for(i=2; i<=19; i++)
        {
            cin>>tt;
            for(j=0; j<tt; j++)
            {
                cin>>a;
                v[i].push_back(a);
                v[a].push_back(i);
            }
        }
        cin>>T;
        TT++;
        cout<<"Test Set #"<<TT<<endl;
        while(T--)
        {
            cin>>source>>destination;
            b=source;
            c=destination;
            if(source>destination)
            {
                long temp=source;
                source=destination;
                destination=temp;
            }
            long d=BFS(source,destination);
            printf("%2ld to %2ld: %ld\n",b,c,d);
        }
        puts("");
    }
    return 0;
}
