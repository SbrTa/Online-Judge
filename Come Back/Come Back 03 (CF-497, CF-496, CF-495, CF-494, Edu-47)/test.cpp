#include <bits/stdc++.h>
using namespace std;

typedef long long int  ll;

#define s(n) scanf("%lld",&n)
#define s2(n,m) scanf("%lld%lld",&n,&m)


int main()
{
    string s;
    cin>>s;
    ll ans = 0,l=s.size(),tm=0;

    for(ll i=0; i<l; i++)
    {
        ll x = (s[i]-'0');
        if(x%3==0)
        {
            ans++;
            tm = 0;
        }
        else
        {
            if(((tm%10)*10+x)%3==0)
            {
                ans++;
                tm=0;
            }
            else if((tm*10+x)%3==0)
            {
                ans++;
                tm=0;
            }
            else
            {
                tm *=10;
                tm+=x;
            }
        }

    }

    cout<<ans<<endl;





}
