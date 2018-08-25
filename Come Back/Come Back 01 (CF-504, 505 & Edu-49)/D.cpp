#include<bits/stdc++.h>
using namespace std;
#define LL long long


int main()
{
    LL n,k,i,j;
    string s;
    map<char,LL>mp;
    cin>>n>>s;
    for(i=0;i<n;i++){
        mp[s[i]]++;
        if(n==1 || mp[s[i]]>1){
            printf("Yes\n");
            return 0;
        }
    }

    printf("No\n");
    return 0;
}

