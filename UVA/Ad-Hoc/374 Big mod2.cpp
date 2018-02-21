#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll BigMod(ll B, ll P, ll M)
{
    if(P==0)
        return 1;
    if(P%2==0)
        return (BigMod(B,P/2,M)%M*BigMod(B,P/2,M)%M);
    else
        return ((B%M)*BigMod(B,P-1,M)%M);
}

int main()
{
    ll B,P,M;
    while(cin>>B>>P>>M)
    {
        ll result=BigMod(B,P,M);
        cout<<result<<endl;
    }
    return 0;
}
