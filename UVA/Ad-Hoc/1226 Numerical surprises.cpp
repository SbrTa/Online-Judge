#include<stdio.h>
#include<string.h>
#define ll long long

int main()
{
    ll t,n,len,result,i;
    char m[2010];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        getchar();
        gets(m);
        len=strlen(m);
        result=0;
        for(i=0;i<len;i++)
            result=((result*10)+(m[i]-'0'))%n;
        printf("%lld\n",result);
    }
    return 0;
}
