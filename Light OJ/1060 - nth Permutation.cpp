#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s,sol;
ll n,a[30],fact[22];

void fct()
{
    fact[0]=1;
    for(ll i=1;i<=20;i++) fact[i]=fact[i-1]*i;
}

int main()
{
    fct();
    //for(int i=0;i<=20;i++) cout<<fact[i]<<endl;
    ll test,cs=1,i,j;
    scanf("%lld",&test);
    while(test--){
        cin>>s>>n;
        sol="";
        ll len=s.size();
        for(i=0;i<=26;i++) a[i]=0;
        for(i=0;i<len;i++) a[s[i]-'a']++;
        ll x=fact[len];
        for(i=0;i<26;i++)   x=x/fact[a[i]];
        printf("Case %d: ",cs++);
        if(x<n){
            printf("Impossible\n");
            continue;
        }
        while(1){
            ll f=0;
            for(i=0;i<26;i++){
                if(a[i]){
                    f=1;
                    x=len-sol.size()-1;
                    x=fact[x];
                    for(j=0;j<26;j++){
                        if(i==j) x=x/fact[a[j]-1];
                        else x=x/fact[a[j]];
                    }
                    if(x>=n){
                        sol+=(i+'a');
                        a[i]--;
                        i=-1;
                        //if(x==n) n=0;
                    }
                    else n=n-x;
                    //cout<<x<<" "<<n<<" "<<sol<<endl;
                }
            }
            if(f==0 || sol.size()==len) break;
        }
        cout<<sol<<endl;
    }
    return 0;
}
