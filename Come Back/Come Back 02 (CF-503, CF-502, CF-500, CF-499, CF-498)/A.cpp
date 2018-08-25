#include<bits/stdc++.h>
using namespace std;
#define LL long long


int main()
{
    LL n,m,i,j,a[1005];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2==0) a[i]--;
    }
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}
