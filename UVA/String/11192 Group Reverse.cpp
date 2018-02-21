#include<stdio.h>
#include<string.h>
int main()
{
    int n,len,i,j,nn;
    char s[110];
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        getchar();
        gets(s);
        len=strlen(s);
        nn=len/n;
        for(i=0;i<n;i++)
        {
            for(j=(i+1)*nn-1;j>=i*nn;j--)
                printf("%c",s[j]);

        }
        puts("");
    }
    return 0;
}
