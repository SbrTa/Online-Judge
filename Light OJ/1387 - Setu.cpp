#include<stdio.h>
#include<string.h>

int main()
{
    long int T,t,n,money,tk;
    char s[10];
    scanf("%ld",&T);
    for(t=1;t<=T;t++)
    {
        printf("Case %ld:\n",t);
        money=0;
        scanf("%ld",&n);
        getchar();
        while(n--)
        {
            scanf("%s",&s);
            if(strcmp(s,"donate")==0)
            {
                scanf("%ld",&tk);
                money=money+tk;
            }
            else if(strcmp(s,"report")==0)
                printf("%ld\n",money);
        }
    }
    return 0;
}
