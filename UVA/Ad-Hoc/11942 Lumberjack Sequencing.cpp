#include<stdio.h>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
    int T,t,n=10,i,a[10],b[10],c[10],j,count1,count2;
    scanf("%d",&T);
    printf("Lumberjacks:\n");
    for(t=1;t<=T;t++)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
            c[i]=a[i];
        }
        sort(b,b+n);
        count1=0;
        for(j=0;j<n;j++)
            if(b[j]!=a[j])
            {
                count1++;
                break;
            }
        sort(c,c+n,greater<int>());
        count2=0;
        for(j=0;j<n;j++)
            if(c[j]!=a[j])
            {
                count2++;
                break;
            }

        if(count1==0||count2==0)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }
    return 0;
}
