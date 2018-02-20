#include<stdio.h>
#include<string.h>
int main()
{
    long long i,a,b,c,t,T,n,area,min,max,min_loc,max_loc;
    char s[101][25];
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        min=100000000; max=-1;
        scanf("%lld",&n);
        for(i=0; i<n; i++)
        {
            scanf("%s%lld%lld%lld",s[i],&a,&b,&c);
            area=a*b*c;
            if(area>max)
            {
                max=area;
                max_loc=i;
            }
            if(area<min)
            {
                min=area;
                min_loc=i;
            }
        }
        printf("Case %lld: ",t);
        if(max==min)
            printf("no thief\n");
        else
            printf("%s took chocolate from %s\n",s[max_loc],s[min_loc]);
    }
    return 0;
}
