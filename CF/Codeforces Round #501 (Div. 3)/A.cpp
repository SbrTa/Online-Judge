#include<bits/stdc++.h>
#define inf 100000000
using namespace std;

int main()
{
    int j,i,m,n,l,r,a[111];
    cin>>n>>m;
    for(i=1;i<=m;i++) a[i]=0;
    while(n--){
        cin>>l>>r;
        for(i=l;i<=r;i++) a[i]=1;
    }
    r=0;
    for(i=1;i<=m;i++) if(!a[i])r++;
    cout<<r<<endl;
    for(i=1;i<=m;i++) if(!a[i])cout<<i<<" ";


    return 0;
}
