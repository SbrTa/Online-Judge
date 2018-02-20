#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        int ans=0,a;
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a);
            if(a>0)
                ans+=a;
        }
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
