#include<stdio.h>
int main()
{
    int array[1001],i,j,n,count,temp;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
            scanf("%d",&array[i]);
        count=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
                if(array[i]>array[j])
                    count++;
        }
        printf("Minimum exchange operations : %d\n",count);
    }
    return 0;
}
