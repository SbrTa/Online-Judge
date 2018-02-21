#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    int i,j,len;
    char s[100000];
    while(gets(s))
    {
        len=strlen(s);
        int m=0,alp=0,l;
        s[len]='\0';
        for(i=0;i<=len;i++)
        {
            if(s[i]!=' ')
            {
                if(m==0)
                {
                    l=i;
                    m++;
                }
                alp++;
            }
            if(s[i]==' ')
            {
                for(j=l+alp-1;j>=l;j--)
                    printf("%c",s[j]);
                if(s[i]!='\0')
                    printf(" ");
                m=0;
                alp=0;
            }
            if(s[i]=='\0')
            {
                for(j=l+alp-2;j>=l;j--)
                    printf("%c",s[j]);
            }
        }
        puts("");
    }
    return 0;
}
