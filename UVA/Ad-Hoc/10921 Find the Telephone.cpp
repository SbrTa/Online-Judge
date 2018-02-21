#include<stdio.h>
#include<string.h>
int main()
{
    int len,i;
    char s[30];
    while(gets(s))
    {
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]=='0')
                printf("0");
            else if(s[i]=='1')
                printf("1");
            else if(s[i]=='-')
                printf("-");
            else if(s[i]>='A'&&s[i]<='C')
                printf("2");
            else if(s[i]>='D'&&s[i]<='F')
                printf("3");
            else if(s[i]>='G'&&s[i]<='I')
                printf("4");
            else if(s[i]>='J'&&s[i]<='L')
                printf("5");
            else if(s[i]>='M'&&s[i]<='O')
                printf("6");
            else if(s[i]>='P'&&s[i]<='S')
                printf("7");
            else if(s[i]>='T'&&s[i]<='V')
                printf("8");
            else if(s[i]>='W'&&s[i]<='Z')
                printf("9");
        }
        printf("\n");
    }
    return 0;
}
