#include<stdio.h>
#include<string.h>
#define ll long long

int remind(char m[], ll n, ll len)
{
    ll i,result=0;
    for(i=0;i<len;i++)
        result=((result*10)+(m[i]-'0'))%n;
    return result;
}

int main()
{
    ll t,n,len,s;
    char m[2010];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        getchar();
        gets(m);
        len=strlen(m);
        s=remind(m,n,len);
        printf("%lld\n",s);
    }
    return 0;
}

