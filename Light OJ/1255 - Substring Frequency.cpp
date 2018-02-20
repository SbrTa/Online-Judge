#include<stdio.h>
#include<string.h>

char str[1000005],substr[1000005];
long fail[1000005];

void preProces(char *substr)
{
    long i=0,j=-1,len;
    len=strlen(substr);
    fail[i]=j;
    while(i<len)
    {
        while(j>=0&&substr[i]!=substr[j])
            j=fail[j];
        i++;
        j++;
        fail[i]=j;
    }
}

long KMP(char *str, char *substr)
{
    long i=0,j=0,count=0,lenStr,lenSub;
    lenStr=strlen(str);
    lenSub=strlen(substr);
    preProces(substr);
    while(i<lenStr)
    {
        while(j>=0&&str[i]!=substr[j])
            j=fail[j];
        i++;
        j++;
        if(j==lenSub)
        {
            count++;
            j=fail[j];
        }
    }
    return count;
}

int main()
{
    long T,t;
    scanf("%ld",&T);
    getchar();
    for(t=1;t<=T;t++)
    {
        gets(str);
        gets(substr);
        printf("Case %ld: %ld\n",t,KMP(str,substr));
    }
    return 0;
}
