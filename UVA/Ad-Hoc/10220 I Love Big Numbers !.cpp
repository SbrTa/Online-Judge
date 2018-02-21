#include<stdio.h>
#include<string.h>

char fact[1005][10000],f[10000];

void factorial(int m)
{
    int len,i,cin=0,j,mul;
    len=strlen(f);
    for(i=0;i<len;i++)
    {
        mul=cin+(f[i]-'0')*m;
        f[i]=(mul%10)+'0';
        cin=mul/10;
    }
    while(cin>0)
    {
        f[i]=(cin%10)+'0';
        cin=cin/10;
        i++;
    }
    f[i]='\0';
    for(j=0;j<i;j++)
        fact[m][j]=f[j];
    fact[m][i]='\0';
}

void fac()
{
    int m;
    strcpy(f,"1");
    for(m=2;m<=1000;m++)
        factorial(m);
}

int main()
{
    int n,i,len,sum;
    fact[0][0]='1';
    fact[1][0]='1';
    fac();
    while(scanf("%d",&n)==1)
    {
        sum=0;
        len=strlen(fact[n]);
        for(i=0;i<len;i++)
            sum+=(fact[n][i]-'0');
        printf("%d\n",sum);
    }
    return 0;
}
