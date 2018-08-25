#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define inf 200000

bool eql(char a, char b)
{
    map<char,int>mp;
    mp[a-1]=1;
    mp[a+1]=1;
    if(a=='a'){
        if(a+1==b+1 || a+1==b-1) return true;
    }
    if(b=='a'){
        if(b+1==a+1 || b+1==a-1) return true;
    }
    if(a=='z'){
        if(a-1==b+1 || a-1==b-1) return true;
    }
    if(b=='z'){
        if(b-1==a+1 || b-1==a-1) return true;
    }
    else{
        if(mp[b-1] || mp[b+1]) return true;
    }
    return false;
}

int main()
{
    LL t,n,i,j,x,y;
    string s;
    //cout<<(eql('a','a'))<<endl;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        LL f=1;
        for(i=0,j=n-1;i<n/2;i++,j--){
            if(!eql(s[i],s[j])){
                //cout<<s[i]<<" "<<s[j]<<endl;
                f=0;
                break;
            }
        }
        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

