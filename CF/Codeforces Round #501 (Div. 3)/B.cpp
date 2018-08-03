#include<bits/stdc++.h>
#define inf 100000000
using namespace std;

int main()
{
    int j,i,m,n,l,r,a;
    string s,t;
    map<char,int>mp;
    cin>>n>>s>>t;

    for(i=0;i<n;i++) mp[s[i]]++;
    for(i=0;i<n;i++) mp[t[i]]--;
    for(char ch = 'a'; ch<='z'; ch++){
        if(mp[ch]>0){
            printf("-1\n");
            return 0;
        }
    }
    vector<int>x;
    for(i=0;i<n;i++){
        int jj;
        for(j=0;j<n;j++) if(s[j]==t[i]) jj=j;
        for(j=jj;j>i;j--){
            swap(s[j],s[j-1]);
            x.push_back(j);
        }
    }

    n = x.size();
    if(n>10000){
        printf("-1\n");
        return 0;
    }
    cout<<n<<endl;
    for(i=0;i<n;i++) cout<<x[i]<<" ";
    return 0;
}
