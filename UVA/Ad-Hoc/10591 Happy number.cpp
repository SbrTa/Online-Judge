#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int T,t,n,nn,m,r;
    cin>>T;
    for(t=1; t<=T; t++)
    {
        cin>>n;
        nn=n;
        while(n>9)
        {
            m=0;
            while(n!=0)
            {
                r=n%10;
                m=r*r+m;
                n=n/10;
            }
            n=m;
        }
        if(n==1||n==7)
            cout<<"Case #"<<t<<": "<<nn<<" is a Happy number."<<endl;
        else
            cout<<"Case #"<<t<<": "<<nn<<" is an Unhappy number."<<endl;
    }
    return 0;
}
