#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ff first
#define ss second

int main()
{
    LL n,m=0,i,j;
    string s,t;
    cin>>s>>t;
    for(i=s.size()-1, j=t.size()-1; i>=0 && j>=0; i--,j--){
        if(s[i]==t[j]) m++;
        else break;
    }
    cout<<(s.size()+t.size()-m-m)<<endl;
    return 0;
}

