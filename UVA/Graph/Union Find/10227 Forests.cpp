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



int main(){
    int test,cs=1;
    int a,b,i,j,man,tree;
    inI(test);
    while(test--){
        char s[105];
        int f[105][105],m[105];
        vector<int>v[1000];
        inI(man);
        inI(tree);
        getchar();
        for(i=0;i<=man;i++) for(j=0;j<=tree;j++) f[i][j]=0;
        for(i=0;i<=man;i++) m[i]=0;

        while(gets(s) && sscanf(s,"%d%d",&a,&b)==2){
            if(!f[a][b]){
                v[a].push_back(b);
                f[a][b]=1;
            }
        }

        for(i=1;i<=man;i++) sort(v[i].begin(),v[i].end());
/*
        for(i=1;i<=man;i++){
            for(j=0;j<v[i].size();j++)
                cout<<v[i][j]<<" ";
            cout<<endl;
        }
*/

        int ans=0;
        for(i=1;i<=man;i++){
            if(!m[i]){
                ans++;
                for(j=i+1;j<=man;j++){
                    int x=v[i].size();
                    int y=v[j].size();
                    if(x!=y) continue;
                    int zz=0;
                    for(int l=0; l<x; l++){
                        if(v[i][l] != v[j][l]){
                            zz=1;
                            break;
                        }
                    }
                    if(!zz) m[j]=1;
                }
            }
        }
        if(cs>1) pLine();
        cs=2;
        pI(ans),pLine();
    }
    return 0;
}
