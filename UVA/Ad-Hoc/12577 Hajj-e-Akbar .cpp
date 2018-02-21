#include<stdio.h>
#include<string.h>
int main()
{
    int c,d,t=1,i;
    char s[5];
    for(;;)
    {
        gets(s);
        if(s[0]=='*')
            break;
        c=strcmp(s,"Hajj");
        d=strcmp(s,"Umrah");
        if(c==0)
            printf("Case %d: Hajj-e-Akbar\n",t);
        else if(d==0)
            printf("Case %d: Hajj-e-Asghar\n",t);
        t++;
    }
    return 0;
}
