#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    int a[250],i,j,len,n,m;
    char s[80],ch[80];
    while(gets(s))
    {
        len=strlen(s);
        if(isdigit(s[0]))
        {
            n=0;
            j=0;
            for(i=len-1; i>=0; i--)
            {
                n=n*10+(s[i]-'0');
                if((n>=65&&n<=90)||(n>=97&&n<=122)||n==32||
                   n==33||n==44||n==46||n==58||n==59||n==63)
                {
                    printf("%c",n);
                    n=0;
                }
            }
        }
        else
        {
            for(i=0,j=len-1; i<len; j--,i++)
                a[j]=s[i];
            for(i=0; i<len; i++)
            {
                n=a[i];
                while(n!=0)
                {
                    printf("%d",n%10);
                    n/=10;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
