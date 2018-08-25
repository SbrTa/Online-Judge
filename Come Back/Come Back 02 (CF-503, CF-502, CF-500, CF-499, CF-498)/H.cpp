#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define x first
#define y second
LL a[100005];

int main()
{
    LL n,m,i,j;
    map<LL,LL>mp;
    scanf("%lld",&n);
    scanf("%lld",&m);

    LL f=0;
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        if(mp[a[i]]) f=1;
        mp[a[i]]=1;
    }
    if(f==1){
        printf("0\n");
        return 0;
    }
    for(i=0;i<n;i++){
        if(mp[a[i]&m]){

        }
    }
    if(b<=a) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}

