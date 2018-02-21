#include<stdio.h>
#include<string.h>
int main()
{
    int eng,span,ger,fren,ita,rus,t=1;
    char s[14];
    for(;;)
    {
        gets(s);
        if(s[0]=='#')
            break;

        eng=strcmp(s,"HELLO");
        span=strcmp(s,"HOLA");
        ger=strcmp(s,"HALLO");
        fren=strcmp(s,"BONJOUR");
        ita=strcmp(s,"CIAO");
        rus=strcmp(s,"ZDRAVSTVUJTE");

        if(eng==0)
            printf("Case %d: ENGLISH\n",t);
        else if(span==0)
            printf("Case %d: SPANISH\n",t);
        else if(ger==0)
            printf("Case %d: GERMAN\n",t);
        else if(fren==0)
            printf("Case %d: FRENCH\n",t);
        else if(ita==0)
            printf("Case %d: ITALIAN\n",t);
        else if(rus==0)
            printf("Case %d: RUSSIAN\n",t);
        else
            printf("Case %d: UNKNOWN\n",t);
        t++;
    }
    return 0;
}
