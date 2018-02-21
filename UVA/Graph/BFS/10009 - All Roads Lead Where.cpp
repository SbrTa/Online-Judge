#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
using namespace std;

vector<int>v[30];
int par[30];

void bfs(int s, int d, int index){
    queue<int>q;
    int visited[30],i;
    for(i=1;i<=index;i++) visited[i]=0;
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int a = q.front();
        int sz = v[a].size();
        for(i=0;i<sz;i++){
            int b = v[a][i];
            if(!visited[b]){
                visited[b]=1;
                par[b]=a;
                if(b==d) return;
                q.push(b);
            }
        }
        q.pop();
    }
}

int main()
{
    int test,cs=1;
    int n,m,i,j,q;
    string a,b;
    scanf("%d",&test);
    while(test--){
        if(!cs) puts("");
        cs=0;
        for(i=0;i<30;i++) v[i].clear();
        scanf("%d %d",&n,&q);
        map<char,int>mp;
        map<int,char>mmp;
        //getchar();
        int index=1;
        while(n--){
            cin>>a>>b;
            if(!mp[a[0]]){
                mp[a[0]] = index;
                mmp[index] = a[0];
                index++;
            }
            if(!mp[b[0]]){
                mp[b[0]] = index;
                mmp[index] = b[0];
                index++;
            }
            v[mp[a[0]]].push_back(mp[b[0]]);
            v[mp[b[0]]].push_back(mp[a[0]]);
        }

        while(q--){
            for(i=1;i<=index;i++) par[i]=i;
            cin>>a>>b;
            int x = mp[a[0]];
            int y = mp[b[0]];
            bfs(y,x,index);
            cout<<mmp[x];
            while(par[x]!=x){
                cout<<mmp[par[x]];
                x = par[x];
            }
            puts("");
        }
    }
    return 0;
}

/*
1
7 3
Rome Turin
Turin Venice
Turin Genoa
Rome Pisa
Pisa Florence
Venice Athens
Turin Milan
Turin Pisa
Milan Florence
Athens Genoa
*/
