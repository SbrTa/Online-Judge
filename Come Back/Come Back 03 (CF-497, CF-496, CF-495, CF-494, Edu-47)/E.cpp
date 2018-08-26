#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ff first
#define ss second

int main()
{
    LL n,m,i,j,a,b;
    cin>>n;
    vector<pair<LL,LL> >v;
    for(i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    if(n==1){
        printf("YES\n");
        return 0;
    }
    LL p = max(v[0].ff,v[0].ss);
    LL f=1;
    for(i=1;i<n;i++){
        if(max(v[i].ff,v[i].ss)<=p){
            p=max(v[i].ff,v[i].ss);
        }
        else if(min(v[i].ff,v[i].ss)<=p){
            p=min(v[i].ff,v[i].ss);
        }
        else f=0;
    }
    if(!f) printf("NO\n");
    else printf("YES\n");
    return 0;
}
/*
10
4 3
1 1
6 5
4 5
2 4
9 5
7 9
9 2
4 10
10 1
*/
