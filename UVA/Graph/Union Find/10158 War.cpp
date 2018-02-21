#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    LL n,i,j,a,b,c;
    LL par[100000];
    cin>>n;
    for(i=0;i<=n;i++)
        par[i]=-5;
    while(cin>>c>>a>>b&&c>0)
    {
        if(c==1)
        {
            LL u = (par[a]==-5)?a:par[a];
            LL v = (par[b]==-5)?b:par[b];
            if((u==a&&v==b)||(u==a&&v==-1)||(u==-1&&v==b))
                par[a]=par[b]=-1;
            else if((u==-1&&v==-2)||(u==-2&&v==-1))
                cout<<"-1\n";
            else if(u==a&&v!=b)
            {
                par[a]=par[b]=-1;
            A    par[v]=-2;
            }
            else if(u!=a&&v==b)
            {
                par[a]=par[b]=-1;
                par[u]=-2;
            }
        }
        else if(c==2)
        {
            LL u = (par[a]==-5)?a:par[a];
            LL v = (par[b]==-5)?b:par[b];
            if(u==-1&&v==-1)
                cout<<"-1";
            else if(u==-1&&v==b)
                par[b]=-2;
            else if(u==a&&v==-1)
                par[a]=-2;
            else if(u==a&&v==b)
            {
                par[a]=b;
                par[b]=a;
            }
        }
        else if(c==3)
        {
            LL u = (par[a]==-5)?a:par[a];
            LL v = (par[b]==-5)?b:par[b];
            if((u==-1&&v==-1)||(u==-2&&v==-2))
                cout<<"1\n";
            else
                cout<<"0\n";
        }
        else if(c==4)
        {
            LL u = (par[a]==-5)?a:par[a];
            LL v = (par[b]==-5)?b:par[b];
            if((u==-1&&v==-2)||(u==-2&&v==-1))
                cout<<"1\n";
            else
                cout<<"0\n";
        }
    }
    return 0;
}
