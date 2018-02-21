#include<bits/stdc++.h>
using namespace std;

bool comp(string a, string b)
{
    if(a+b>b+a) return true;
    return false;
}

int main()
{
    int n,i;
    string str[100];
    while(cin>>n&&n!=0)
    {
        for(i=0;i<n;i++)
            cin>>str[i];
        sort(str,str+n,comp);
        for(i=0;i<n;i++)
            cout<<str[i];
        cout<<endl;
    }
    return 0;
}
