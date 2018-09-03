#include<bits/stdc++.h>
using namespace std;

int n,dp[1000],a[1000];

void lis(int l)
{
    if(l==n) return;
    if(dp[l]>=0) return;
    int mx=0;
    for(int i=l+1;i<n;i++){
        if(a[i]>a[l]){
            lis(i);
            if(mx<dp[i]) mx=dp[i];
        }
    }
    dp[l]=mx+1;
}

int main()
{
    int i,j;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
        dp[i]=-1;
    }
    int mx = 0;
    for(i=0;i<n;i++){
        lis(i);
        if(mx<dp[i]) mx=dp[i];
    }
    cout<<mx<<endl;
    for(i=0;i<n;i++){
        if(dp[i]==mx){
            cout<<a[i]<<" ";
            mx--;
        }
    }
    cout<<endl;
    return 0;
}
/*
10
1 5 3 2 8 5 9 2 6 1

*/
