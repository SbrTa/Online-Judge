#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL par[100000],war[100000];

LL Find(LL p)
{
    if(par[p]<0)
        return par[p];
    else if(par[p]==p)
        return p;
    else
        return Find(par[p]);
}

LL SetEnemy(LL p, LL x)
{
    LL n=0;
    if(par[p]==p)
        n=1;
    war[p]=-x;
    if(n==1)
        return x;
    else
        return SetEnemy(par[p],x);
}

int main()
{
    LL n,i,j,a,b,c;
    cin>>n;
    for(i=0;i<=n;i++)
    {
        par[i]=i;
        war[i]=1;
    }
    while(cin>>c>>a>>b&&c>0)
    {
        if(c==1)
        {
            LL u = Find(a);
            LL v = Find(b);
            //cout<<"in1 "<<u<<" "<<v<<endl;
            //if((u==-1&&v==-2)||(u==-2&&v==-1))
            if((war[u]<0&&abs(war[u])==v)||(war[v]<0&&u==abs(war[v])))
                cout<<"-1\n";
            else if(u!=v)
            {
                par[u]=v;
            }
        }
        else if(c==2)
        {
            LL u = Find(a);
            LL v = Find(b);
            //cout<<"in2 "<<u<<" "<<v<<endl;
            if(u==v)
                cout<<"-1\n";
            else
            {
                LL x = SetEnemy(a,b);
                LL y = SetEnemy(b,a);
            }
        }
        else if(c==3)
        {
            LL u = Find(a);
            LL v = Find(b);
            //cout<<"in3 "<<u<<" "<<v<<endl;
            if(u==v)
                cout<<"1\n";
            else
                cout<<"0\n";
        }
        else if(c==4)
        {
            LL u = Find(a);
            LL v = Find(b);
            //cout<<"in4 "<<u<<" "<<v<<endl;
            if((war[u]<0&&abs(war[u])==v)||(war[v]<0&&u==abs(war[v])))
                cout<<"1\n";
            else
                cout<<"0\n";
        }
    }
    return 0;
}
