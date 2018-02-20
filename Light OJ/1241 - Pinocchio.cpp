#include<stdio.h>

int main()
{
    int t,T,n,a,fals,b;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        fals=0; b=2;
        while(n--)
        {
            scanf("%d",&a);
            if(a>b)
                fals+=(a-b-1)/5+1;
            if(a<2)
                b=2;
            else
                b=a;
        }
        printf("Case %d: %d\n",t,fals);
    }
    return 0;
}
