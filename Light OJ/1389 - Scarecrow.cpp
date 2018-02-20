#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#define inf 1000006
using namespace std;

int main()
{
    int t,cs=1,n,i,j;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>s;
        int ans=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='.')
            {
                ans++;
                i+=2;
            }
        }
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}

