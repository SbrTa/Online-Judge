#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int n,m,list[3005],i,j,count,diff[3005],temp;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
            scanf("%d",&list[i]);
        for(i=0;i<n-1;i++)
            diff[i]=abs(list[i]-list[i+1]);
        m=n-1;
        for(i=0;i<m-1;i++)
            for(j=i+1;j<m;j++)
                if(diff[i]>diff[j])
                { temp=diff[i]; diff[i]=diff[j]; diff[j]=temp; }
        count=0;
        if(diff[0]==0||diff[0]==1)
        {
            for(i=0;i<m-1; i++)
                if(abs((diff[i]-diff[i+1]))!=1)
                    count++;
            if(count==0)
                printf("Jolly\n");
            else
                printf("Not jolly\n");
        }
        else
            printf("Not jolly\n");
    }
return 0;
}
