#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long

int main()
{
    ll n,r,i,j,a,b;
    while(cin>>n>>r)
    {
        if(n==0&&r==0)
            return 0;
        a=n; b=r;
        ll combination=1;
        ll boro=(n-r>r)?n-r:r;
        ll choto=n-boro;
        for(i=1;i<=choto;i++,n--)
            combination=combination*n/i;
        cout<<a<<" things taken "<<b<<" at a time is "<<combination<<" exactly.\n";
    }
}
