#include<bits/stdc++.h>
using namespace std;
#define LL long long


int main()
{
    LL n,m,i,j,star=0;
    string s,t;
    cin>>n>>m;
    cin>>s>>t;
    for(i=0,j=0;i<n;i++,j++){
        if(s[i]=='*'){
            star=1;
            break;
        }
        if(j==m || s[i]!=t[j]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(!star) if(s==t){
        cout<<"YES"<<endl;
        return 0;
    }
    else{
        cout<<"NO"<<endl;
        return 0;
    }
    LL x=j-1;
    for(i=n-1,j=m-1;i>=0;i--,j--){
        if(s[i]=='*'){
            break;
        }
        if(s[i]!=t[j] || j==x){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
