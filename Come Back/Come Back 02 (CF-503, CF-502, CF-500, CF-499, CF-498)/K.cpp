#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define x first
#define y second


int main()
{
    LL n,m,i,j;
    string a,b;
    cin>>n>>a>>b;

    LL a0=0,a1=0,a0b0=0,a1b0=0;
    for(i=0;i<n;i++){
        if(a[i]=='0') a0++;
        else a1++;
        if(a[i]=='0' && b[i]=='0') a0b0++;
        if(a[i]=='1' && b[i]=='0') a1b0++;
    }

    //cout<<a0<<" "<<a1<<endl;
    //cout<<a0b0<<" "<<a1b0<<endl;

    LL s = (a0b0*a1) + (a1b0*(a0-a0b0));
    cout<<s<<endl;

    return 0;
}

