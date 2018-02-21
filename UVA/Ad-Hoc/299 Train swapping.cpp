#include<stdio.h>
int main()
{
    int T,t,n,a[55],i,j,count,temp;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        count=0;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
                if(a[i]>a[j])
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                    count++;
                }
        }
        printf("Optimal train swapping takes %d swaps.\n",count);
    }
    return 0;
}
