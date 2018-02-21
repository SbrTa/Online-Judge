#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<long,long>mp;
    long i,a,s[10000],n=0;
    while(cin>>a)
    {
        if(!mp[a])
            s[n++]=a;
        mp[a]++;
    }
    for(i=0;i<n;i++)
        cout<<s[i]<<" "<<mp[s[i]]<<endl;
    return 0;
}
