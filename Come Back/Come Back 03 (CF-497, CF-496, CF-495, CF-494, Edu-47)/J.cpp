#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ff first
#define ss second

int main()
{
    LL n,i,j;
    string s;
    cin>>s;
    n = s.size();
    LL ans=0,m=0;

    for(i=0;i<n;i++){
        LL x = (s[i]-'0');
        if(x%3==0){
            ans++;
            m=0;
            continue;
        }
        if(((m%10)*10+x)%3==0){
            ans++;
            m=0;
            continue;
        }
        m = m*10 + x;
        if(m%3==0){
            ans++;
            m=0;
            continue;
        }
    }
    cout<<ans<<endl;
    return 0;
}

