#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    long long test,cs=1,fac[22],l[27],i,ans=1;
    char s[22];
    for(i=1;i<=20;i++)
    {
        ans=ans*i;
        fac[i]=ans;
    }
    scanf("%lld",&test);
    getchar();
    while(test--)
    {
        gets(s);
        int len=strlen(s);
        ans=fac[len];
        for(i=0;i<=26;i++) l[i]=0;
        for(i=0;i<len;i++)
            l[s[i]-'A']++;
        for(i=0;i<26;i++)
            if(l[i]>1) ans=ans/fac[l[i]];
        printf("Data set %lld: %lld\n",cs++,ans);
    }
    return 0;
}
