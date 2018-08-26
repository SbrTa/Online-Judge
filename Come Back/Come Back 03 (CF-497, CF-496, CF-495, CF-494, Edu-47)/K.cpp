#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ff first
#define ss second

int main()
{
    LL n,d,i,j,a[111];
    cin>>n>>d;
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    LL s=2;
    for(i=1;i<n;i++){
        LL x = a[i-1]+d;
        LL y = a[i] - d;
        if(y==x) s++;
        if(y>x) s+=2;
    }
    cout<<s<<endl;
    return 0;
}

