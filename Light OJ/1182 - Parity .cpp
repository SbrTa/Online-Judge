#include<stdio.h>
int main()
{
    int T,t,n,r,one;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        one=0;
        while(n!=0)
        {
            r=n%2;
            if(r==1)
                one++;
            n=n/2;
        }
        if(one%2==1)
            printf("Case %d: odd\n",t);
        else
            printf("Case %d: even\n",t);
    }
    return 0;
}
