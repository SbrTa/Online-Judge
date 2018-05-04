#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char s[10];
    int T,t,a,b,len;
    scanf("%d",&T);
    getchar();
    for(t=1;t<=T;t++)
    {
        gets(s);
        len=strlen(s);
        a=(s[0]-'A')*(26*26)+(s[1]-'A')*26+(s[2]-'A');
        b=(((((((s[4]-'0')*10)+(s[5]-'0'))*10)+(s[6]-'0'))*10)+(s[7]-'0'));
        if(abs(a-b)<=100)
            printf("nice\n");
        else
            printf("not nice\n");
    }
    return 0;
}
