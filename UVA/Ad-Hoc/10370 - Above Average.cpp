#include<stdio.h>
int main()
{
    int T,t,n,i,a[1001],sum,count;
    float avg,result;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        sum=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum=sum+a[i];
        }
        avg=(float)sum/n;
        count=0;
        for(i=1;i<=n;i++)
            if(a[i]>avg)    count++;
        result=(float)(count*100)/n;
        printf("%.3f%%\n",result);
    }
return 0;
}
