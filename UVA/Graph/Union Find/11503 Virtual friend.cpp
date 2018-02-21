#include<bits/stdc++.h>
using namespace std;
#define mem(a,n) memset(a,n,sizeof(a))

long find_parent(long);

long flag[100005];
long par[100005];
map<string,long>mp;

int main()
{
    string a,b;
    long index,T,N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        mp.clear();
        mem(flag,0);
        mem(par,-1);
        index=1;
        while(N--)
        {
            cin>>a>>b;

            if(mp[a]==0)
                mp[a]=index++;
            if(mp[b]==0)
                mp[b]=index++;

            int u=find_parent(mp[a]);
            int v=find_parent(mp[b]);

            //if(u==v)
                //cout<<"total="<<flag[v]<<endl;
            if(u!=v)
            {
                par[u]=v;
                int x=flag[u];
                int y=flag[v];

                if(u==mp[a]&&flag[u]==0) x++;

                if(v==mp[b]&&flag[v]==0) y++;

                flag[v]=x+y;
                //cout<<"total="<<flag[v]<<endl;
            }
            cout<<flag[v]<<endl;
        }
    }
    return 0;
}

long find_parent(long r)
{
    if(par[r]<0)
        return r;
    else
        return find_parent(par[r]);
}
