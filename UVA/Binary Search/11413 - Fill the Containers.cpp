#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#define inf 1000006
using namespace std;

int main()
{
    long n,m,a[1111],i,j;
    while(scanf("%ld%ld",&n,&m)==2)
    {
        long max,min,sum=0,ans;
        for(i=0;i<n;i++)
        {
            scanf("%ld",&a[i]);
            sum+=a[i];
        }
        max=sum;
        min=max/m;
        while(min<=max)
        {
            long mid=(max+min)/2;
            long temp=0,need=0;

            //printf("min=%ld max=%ld mid=%ld\n",min,max,mid);
            for(i=0;i<=n;i++)
            {
                if(i==n)
                {
                    if(temp) need++;
                    break;
                }

                temp+=a[i];
                if(temp==mid)
                {
                    temp=0;
                    need++;
                }
                else if(temp>mid)
                {
                    temp=a[i];
                    need++;
                }
                if(need>m || a[i]>mid)
                {
                    need=m+1;
                    break;
                }
            }
            if(need<=m)
            {
                ans=mid;
                max=mid-1;
            }
            else
                min=mid+1;
        }
        printf("%ld\n",ans);

    }
    return 0;
}
