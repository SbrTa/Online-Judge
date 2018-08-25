#include<bits/stdc++.h>
using namespace std;
#define LL long long


int main()
{
    LL n,k,i,j;
    string s;
    map<LL,LL>mp;
    stack<LL>open;
    cin>>n>>k>>s;

    LL need = (n-k)/2;
    for(i=0;i<n;i++){
        if(s[i]=='(') open.push(i);
        if(need && s[i]==')'){
            mp[i]=1;
            mp[open.top()]=1;
            open.pop();
            need--;
        }
    }
    for(i=0;i<n;i++){
        if(!mp[i]) cout<<s[i];
    }
    cout<<endl;


    return 0;
}

