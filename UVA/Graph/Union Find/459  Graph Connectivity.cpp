#include<bits/stdc++.h>
using namespace std;
#define mem(a,n) memset(a,n,sizeof(a))

int par[30],n,flag[30];

int find_parent(int p)
{
    if(par[p]==p)
        return p;
    else
        return find_parent(par[p]);
}

void Union(int a,int b)
{
    int u=find_parent(a);
    int v=find_parent(b);
    if(u!=v)
    {
        par[u]=v;
        n--;
        flag[u]=flag[v]=1;
    }
}

int main()
{
    int T,t,i;
    scanf("%d\n\n",&T);
    for(t=1;t<=T;t++)
    {
        string s;
        int a,b;
        mem(flag,0);
        getline(cin,s);
        n=s[0]-'A'+1;
        for(i=0; i<=n; i++)
            par[i]=i;
        while(1)
        {
            getline(cin,s);
            if(s.empty())
                break;
            a=s[0]-'A';
            b=s[1]-'A';
            Union(a,b);
        }
        if(t>1)
            cout<<endl;
        cout<<n<<endl;
    }
    return 0;
}
