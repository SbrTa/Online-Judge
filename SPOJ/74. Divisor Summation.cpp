#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 4294967297 //sqrt(18446744073709551616)
using namespace std;

int main()
{
    long t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long i,ans=1;
        for(i=2;i*i<=n;i++)
            if(n%i==0) ans=ans+i+(n/i);
        i--;
        if(i*i==n)
            ans=ans-i;
        cout<<ans<<endl;
    }
    return 0;
}

