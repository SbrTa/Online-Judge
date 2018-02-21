#include<stdio.h>
#include<string.h>

int main()
{
    int T,tt,n;
    char ch;
    scanf("%d",&T);
    for(tt=1;tt<=T;tt++)
    {
        int i,a=0,b=0,w=0,t=0;
        scanf("%d",&n);
        getchar();
        for(i=0;i<n;i++)
        {
            scanf("%c",&ch);
            if(ch=='B')
                b++;
            else if(ch=='W')
                w++;
            else if(ch=='T')
                t++;
            else if(ch=='A')
                a++;
        }
        printf("Case %d: ",tt);
        if(w==0&&t==0&&b>=1)
            printf("BANGLAWASH\n");
        else if(b==0&&t==0&&w>=1)
            printf("WHITEWASH\n");
        else if(a==n)
            printf("ABANDONED\n");
        else if(b==w)
            printf("DRAW %d %d\n",b,t);
        else if(b>w)
            printf("BANGLADESH %d - %d\n",b,w);
        else
            printf("WWW %d - %d\n",w,b);
    }
    return 0;
}
