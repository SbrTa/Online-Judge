#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ff first
#define ss second

LL a[120004];

int main()
{
    LL n,m,i,j;
    map<LL,LL>mp;
    vector<LL>two;
    m=1;
    for(i=1;;i++){
       m = m*2;
       if(m>10000000009) break;
       two.push_back(m);
    }
    //cout<<two.size()<<" "<<two[two.size()-1]<<endl;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&m);
        a[i]=m;
        mp[m]++;
    }

    LL s=0;
    for(i=0;i<n;i++){
        LL ok=0;
        for(j=0;j<33;j++){
            LL d = two[j]-a[i];
            if(d==a[i] && mp[d]>1){
                //cout<<a[i]<<" "<<d<<endl;
                ok=1;
                break;
            }
            else if(d!=a[i] && mp[d]){
                //cout<<a[i]<<" "<<d<<endl;
                ok=1;
                break;
            }
        }
        if(!ok) s++;
    }
    cout<<s<<endl;

    return 0;
}

