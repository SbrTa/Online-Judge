#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ff first
#define ss second


int main()
{
    LL n,k,i,j,x,y;
    cin>>n>>k;
    for(i=0;i<k;i++){
        cin>>x>>y;
    }

    LL a[1111];

    for(i=1;i<=n;i++) a[i]=0;

    for(i=1;i<=n;i++) if(i%2) a[i]=1;
    for(i=1;i<=n;i++) cout<<a[i];
    cout<<endl;

    return 0;
}

