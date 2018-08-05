#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

int main()
{
    long long n,m,q,l,r,i,x[1111],ans;
    //scanf("%lld%lld%lld",&n,&m,&q);
    cin>>n>>m>>q;
    string s,t;
    cin>>s>>t;
    x[0]=0;
    for(i=0;i<n;i++){
        x[i+1] = x[i];
        if(i+m<=n){
            if(s.substr(i,m)==t) x[i+1]++;
        }
    }

    for(i=0;i<q;i++){
        //scanf("%lld%lld",&l,&r);
        cin>>l>>r;
        if(r-l+1 < m){
            //printf("0\n");
            cout<<"0"<<endl;
        }
        else{
            ans = x[r-m+1] - x[l-1];
            //printf("%lld\n",ans);
            cout<<ans<<endl;
        }
    }


    return 0;
}

