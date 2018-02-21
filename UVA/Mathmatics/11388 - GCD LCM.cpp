#include<iostream>
using namespace std;

int main()
{
    long a,b,t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(b%a==0)
            cout<<a<<" "<<b<<endl;
        else
            cout<<"-1\n";
    }
    return 0;
}
