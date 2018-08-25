#include<bits/stdc++.h>
using namespace std;
#define LL long long


int main()
{
    LL n,k,i,j,s;
    cin>>n>>k;

    s = (k-1)/2;
    if(n<k-1) s -= (k-1) - n;
    if(s<0) s=0;
    cout<<s<<endl;
    return 0;
}
