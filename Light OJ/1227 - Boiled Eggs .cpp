#include<stdio.h>
int main()
{
    int T,t,n,p,q,weight[30],total_weight,i,j,k,temp,count;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d %d",&n,&p,&q);
        for(i=0;i<n;i++)
            scanf("%d",&weight[i]);
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
                if(weight[i]>weight[j])
                {temp=weight[i]; weight[i]=weight[j]; weight[j]=temp;}
        total_weight=0; count=0;
        for(k=0;k<n;k++)
        {
            total_weight=total_weight+weight[k];
            if(total_weight>q)
                break;
            count++;
        }
        if(count>=p)
            printf("Case %d: %d\n",t,p);
        else
            printf("Case %d: %d\n",t,count);
    }
    return 0;
}
