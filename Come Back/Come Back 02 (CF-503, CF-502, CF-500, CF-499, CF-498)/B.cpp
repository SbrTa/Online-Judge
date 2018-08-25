#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define x first
#define y second

int main()
{
    LL n,d,i,j,a;
    vector<pair<LL,LL> >v;
    vector<LL>s;
    map<LL,LL>mp;
    cin>>n>>d;
    for(i=0;i<n;i++){
        cin>>a;
        v.push_back({a,i});
    }

    sort(v.begin(),v.end());

    LL t=0;
    for(i=n-1,j=0;j<d;i--,j++){
        t+=v[i].x;
        mp[v[i].y]=1;
    }
    cout<<t<<endl;
    t=0;
    for(i=0;i<n;i++){
        if(mp[i]){
            t++;
            s.push_back(t);
            t=0;
        }
        else{
            t++;
        }
    }
    s[d-1]+=t;
    for(i=0;i<d;i++) cout<<s[i]<<" ";



    return 0;
}
