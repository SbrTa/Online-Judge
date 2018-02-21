#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#define inf -99999999
using namespace std;

string s[500005],str[500005],x,y;

int main()
{
    long n,i,j,a,b;
    while(~scanf("%ld",&n) && n)
    {
        if(n%2)
        {
            for(i=0;i<n;i++) cin>>x>>y;
            printf("NO\n");
            continue;
        }
        for(i=0;i<n;i++)
        {
            cin>>x>>y;
            s[i]=x+y;
            str[i]=y+x;
        }
        sort(s,s+n);
        sort(str,str+n);
        int f=0;
        for(i=0;i<n;i++)
        {
            if(s[i]!=str[i])
            {
                f=1;
                break;
            }
        }

        if(f==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
