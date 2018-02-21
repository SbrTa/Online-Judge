#include<bits/stdc++.h>
using namespace std;

int main()
{
    long a[10001],madian,i=0;
    while(cin>>a[i++])
    {
        sort(a,a+i);
        if(i==1)
            cout<<a[i-1]<<endl;
        else if(i%2==1)
            cout<<a[i/2]<<endl;
        else
            cout<<(a[i/2]+a[i/2-1])/2<<endl;
    }
    return 0;
}
