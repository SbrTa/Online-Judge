#include<stdio.h>
#include<string.h>

int main()
{
    long T,t,n,r,i,len;
    char s[1000];
    scanf("%ld",&T);
    getchar();
    for(t=1;t<=T;t++)
    {
        scanf("%s%ld",&s,&n);
        len=strlen(s);
        r=0;
        for(i=0;i<len;i++)
        {
            if(s[i]=='-')
                continue;
            r=(r*10+(s[i]-'0'))%n;
        }
        if(r==0)
            printf("Case %ld: divisible\n",t);
        else
            printf("Case %ld: not divisible\n",t);
    }
    return 0;
}
