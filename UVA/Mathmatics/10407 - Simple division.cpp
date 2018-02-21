#include<iostream>
#include<cstdio>
#include<algorithm>
#define inf 0x7f7f7f7f
using namespace std;

int main()
{
    long a[1001],l,i,j;
    while(1)
    {
        long n,mn=inf;
        for(l=0;;l++)
        {
            cin>>n;
            if(n==0) break;
            if(n<mn) mn=n;
            a[l]=n;
        }
        if(l==0) break;

        long gcd;
        for(i=0;i<l;i++)
        {
            if(i==0) gcd = a[i] - mn;
            else gcd = __gcd(gcd,a[i]-mn);
        }
        cout<<gcd<<endl;
    }
    return 0;
}

