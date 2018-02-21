#include<bits/stdc++.h>
using namespace std;

char f[10000];
char factorial[1000][10000];

void multiply(int m)
{
    int len,i,j,mul,carry=0;
    len=strlen(f);
    for(i=0;i<len;i++)
    {
        mul=carry+(f[i]-'0')*m;
        f[i]=(mul%10)+'0';
        carry=mul/10;
    }
    while(carry>0)
    {
        f[i]=carry%10+'0';
        carry=carry/10;
        i++;
    }
    f[i]='\0';
    for(j=0;j<i;j++)
        factorial[m][j]=f[j];
    factorial[m][i]='\0';
}

void fac()
{
    int m;
    strcpy(f,"1");
    for(m=2;m<=1000;m++)
        multiply(m);
}

void print(int n)
{
    int len,i;
    len=strlen(factorial[n]);
    printf("%d!\n",n);
    for(i=len-1;i>=0;i--)
        printf("%c",factorial[n][i]);
    printf("\n");
}

int main()
{
    int n;
    factorial[0][0]='1';
    factorial[1][0]='1';
    fac();
    while(scanf("%d",&n)==1)
        print(n);
    return 0;
}
