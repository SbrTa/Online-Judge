#include<stdio.h>
#include<string.h>
#include<stdlib.h>

long bin(long n)
{
    long i=0,j,r,nn;
    char s[25],ss[25];
    while(n!=0)
    {
        r=n%2;
        s[i++]=(r+'0');
        n/=2;
    }
    for(j=0;j<i;j++)
        ss[j]=s[i-j-1];
    ss[j]='\0';
    return atol(ss);
}

int main()
{
    long T,t,a,b,c,d,aa,bb,cc,dd,aaa,bbb,ccc,ddd;
    scanf("%ld",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%ld.%ld.%ld.%ld",&a,&b,&c,&d);
        scanf("%ld.%ld.%ld.%ld",&aa,&bb,&cc,&dd);
        aaa=bin(a);
        bbb=bin(b);
        ccc=bin(c);
        ddd=bin(d);
        if(aa==aaa&&bb==bbb&&cc==ccc&&dd==ddd)
            printf("Case %ld: Yes\n",t);
        else
            printf("Case %ld: No\n",t);
    }
    return 0;
}
