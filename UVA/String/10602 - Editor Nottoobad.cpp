#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<vector>
#define inf 1000
using namespace std;

int main()
{
    int t,n,i,j;
    string s[111];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            cin>>s[i];
        sort(s,s+n);
        int cnt=s[0].size(),c;
        for(i=1;i<n;i++)
        {
            for(c=0; c<s[i-1].size() && s[i-1][c]==s[i][c]; c++);
            cnt+=(s[i].size()-c);
        }
        printf("%d\n",cnt);
        for(i=0;i<n;i++)
            cout<<s[i]<<endl;
    }
    return 0;
}
