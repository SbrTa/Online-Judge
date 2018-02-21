#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test,n,m,v,ans;
    map<char,long long>mp;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        char c,str[10004];
        mp.clear();
        while(n--)
        {
            getchar();
            scanf("%c %lld",&c,&v);
            mp[c]=v;
        }
        scanf("%lld",&m);
        getchar();
        for(ans=0;m--;)
        {
            gets(str);
            for(int i=0;str[i];i++)
                ans+=mp[str[i]];
        }
        printf("%.2lf$\n",(double)ans/100);
    }
    return 0;
}
