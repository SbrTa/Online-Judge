#include<stdio.h>
int main()
{
    long long int T,t,m[2010],n,i,mp,mil,r,mile,jp,juic,juice;
    scanf("%lld",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&m[i]);
        mp=30;mile=0;
        for(i=0;i<n;i++)
        {
            mil=(m[i]+1)/mp;
            r=(m[i]+1)%mp;
            if(r>0)
                mil++;
            mile=mile+(mil*10);
        }

        jp=60;juice=0;
        for(i=0;i<n;i++)
        {
            juic=(m[i]+1)/jp;
            r=(m[i]+1)%jp;
            if(r>0)
                juic++;
            juice=juice+(juic*15);
        }

        if(mile==juice)
            printf("Case %lld: Mile Juice %lld\n",t,mile);
        else if(mile>juice)
            printf("Case %lld: Juice %lld\n",t,juice);
        else
            printf("Case %lld: Mile %lld\n",t,mile);
    }
    return 0;
}
