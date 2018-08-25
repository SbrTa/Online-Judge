#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define x first
#define y second


int main()
{
    LL n,m,a[1003],i,j;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    for(j=1;j<=n;j++){
        m=j;
        map<LL,LL>mp;
        while(1){
            if(mp[m]){
                cout<<m<<" ";
                break;
            }
            mp[m]=1;
            m = a[m];
        }
    }
    return 0;
}


