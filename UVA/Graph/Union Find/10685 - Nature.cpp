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

#define inI(n) scanf("%d",&n)
#define inL(n) scanf("%ld",&n)
#define inLL(n) scanf("%lld",&n)
#define inF(n) scanf("%f",&n)
#define inD(n) scanf("%lf",&n)
#define inLD(n) scanf("%Lf",&n)
#define inStr(n) scanf("%s",n)
#define inC(n) scanf("%c",&n)

#define pI(n) printf("%d",n)
#define pL(n) printf("%ld",n)
#define pLL(n) printf("%lld",n)
#define pF(n) printf("%f",n)
#define pD(n) printf("%lf",n)
#define pLD(n) printf("%Lf",n)
#define pStr(n) printf("%s",n)
#define pSpc(n) printf(" ")
#define pLine(n) printf("\n")

#define INF 111
#define MX 111
#define PI acos(-1.0)
using namespace std;

long par[5003],flag[5003];

long Parent(long r){
    if(par[r]==r) return r;
    return par[r] = Parent(par[r]);
}


int main(){
    long test,cs=1;
    long n,m,a,b,i,j,ch;
    while(inL(n) && inL(m)){
        //cout<<n<<" "<<m<<endl;
        if(!n && !m) break;
        for(i=0;i<=n;i++){
            par[i]=i;
            flag[i]=0;
        }
        long mx=1,index=0;
        map<string,long>mp;
        string a,b;
        for(i=0;i<n;i++){
            cin>>a;
            if(!mp[a]) mp[a]=++index;
        }
        while(m--){
            cin>>a>>b;
            long u = Parent(mp[a]);
            long v = Parent(mp[b]);
            //cout<<u<<" "<<v<<endl;
            if(u!=v){
                par[u]=v;
                long x = flag[u];
                long y = flag[v];
                if(mp[a]==u && flag[u]==0) x++;
                if(mp[b]==v && flag[v]==0) y++;
                flag[v] = x+y;
                if(x+y>mx) mx=x+y;
            }
        }
        pL(mx);
        pLine();
    }
    return 0;
}



