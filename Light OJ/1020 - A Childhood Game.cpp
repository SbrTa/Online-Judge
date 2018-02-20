#include<stdio.h>
#include<string.h>
int main()
{
    long n,t,T,no=0;
    char s[7];
    scanf("%ld",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%ld%s",&n,s);
        if(strcmp(s,"Alice")==0)
        {
            if(n%3==1)
                printf("Case %d: Bob\n",t);
            else
                printf("Case %d: Alice\n",t);
        }
        else
        {
            if(n%3==0)
                printf("Case %d: Alice\n",t);
            else
                printf("Case %d: Bob\n",t);
        }
    }
    return 0;
}
