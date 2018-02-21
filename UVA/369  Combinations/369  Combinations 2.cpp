#include<bits/stdc++.h>
using namespace std;

long long combin(long long n, long long r)
{
    long long combination=1,boro,choto,i;

    boro=(n-r>r)?n-r:r;
    choto=n-boro;

    for(i=1; i<=choto; i++, n--)
        combination=combination*n/i;

    return combination;
}


int main()
{
    long long n,r;
    while(cin>>n>>r)
    {
        if(n==0&&r==0)
            return 0;
        cout<<n<<" things taken "<<r<<" at a time is "<<combin(n,r)<<" exactly.\n";
    }
}
