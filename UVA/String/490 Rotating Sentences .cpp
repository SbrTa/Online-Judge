#include<stdio.h>
#include<string.h>
int main()
{
    char s[110][110];
    int n=0,i,j,l,max=0;
    while(gets(s[n]))
        n++;
    for(i=0;i<n;i++)
    {
        l=strlen(s[i]);
        if(l>max)
            max=l;
        for(j=l;j<max;j++)
            s[i][j]=' ';
    }
    for(i=0;i<max;i++)
    {
        for(j=n-1;j>=0 ;j--)
            printf("%c",s[j][i]);
        printf("\n");
    }
    return 0;
}
