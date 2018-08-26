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
    n  = s.size();

    for(i=0;i<n;i++){
        if(i==n-1){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='n') continue;
            printf("NO\n");
            return 0;
        }
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='n') continue;
        if(s[i+1]=='a' || s[i+1]=='e' || s[i+1]=='i' || s[i+1]=='o' || s[i+1]=='u');
        else{
            printf("NO\n");
            return 0;
        }

    }
    printf("YES\n");
    return 0;
}

