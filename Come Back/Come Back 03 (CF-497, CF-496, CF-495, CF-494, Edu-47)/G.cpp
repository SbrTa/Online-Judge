#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ff first
#define ss second

int main()
{
    LL n,m,i,j,a[1003];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    a[n]=1;
    LL s=0;
    vector<LL>v;
    for(i=1;i<=n;i++){
        if(a[i]==1){
            s++;
            v.push_back(a[i-1]);
        }
    }
    cout<<s<<endl;
    for(i=0;i<s;i++) cout<<v[i]<<" "; cout<<endl;
    return 0;
}

