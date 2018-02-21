#include<stdio.h>

int tariff(int a[], int m, int pulse, int rate)
{
    int j,cost=0,r,co;
    for(j=0;j<m;j++)
    {
        co=(a[j]+1)/pulse;
        r=(a[j]+1)%pulse;
        cost=cost+(co*rate);
        if(r!=0)
            cost+=rate;
    }
    return cost;
}

int main()
{
    int T,t,min[2010],n,i,mp,m_rate,mile,jp,j_rate,juice;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&min[i]);
        mp=30; m_rate=10;
        mile=tariff(min,n,mp,m_rate);

        jp=60; j_rate=15;
        juice=tariff(min,n,jp,j_rate);

        if(mile==juice)
            printf("Case %d: Mile Juice %d\n",t,mile);
        else if(mile>juice)
            printf("Case %d: Juice %d\n",t,juice);
        else
            printf("Case %d: Mile %d\n",t,mile);
    }
    return 0;
}
