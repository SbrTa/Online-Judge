#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ff first
#define ss second

int main()
{
    LL n,m,i,j;
    string s;
    cin>>s;
    s+="2";
    n = s.size();

    vector<LL>v;
    LL one=0;
    for(i=0;i<n;i++) if(s[i]=='1') one++;

    LL x=0;
    for(i=0;i<n;i++){
        if(s[i]=='2'){
            v.push_back(x);
            x=0;
        }
        if(s[i]=='0') x++;
    }

    for(i=0;i<v[0];i++) cout<<"0";
    for(i=0;i<one;i++) cout<<"1";
    for(i=1;i<v.size();i++){
        cout<<"2";
        for(j=0;j<v[i];j++) cout<<"0";
    }
    cout<<endl;


    return 0;
}

