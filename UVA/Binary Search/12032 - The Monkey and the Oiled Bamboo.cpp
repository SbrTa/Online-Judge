#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#define inf 100005
using namespace std;

long a[inf];

int main()
{
    long test,cs=1,n,i,j;
    scanf("%ld",&test);
    while(test--)
    {
        scanf("%ld",&n);
        a[0]=0;
        for(i=1;i<=n;i++)
            scanf("%ld",&a[i]);

        long low=0,high=10000000,mid,ans;
        while(low<=high)
        {
            mid=(low+high)/2;
            //printf("low=%ld  high=%ld  mid=%ld\n",low,high,mid);
            long power=mid;
            int f=0;
            for(i=1;i<=n;i++)
            {
                if(a[i]-a[i-1]>power)
                {
                    f=1;
                    break;
                }
                else if(a[i]-a[i-1]==power)
                    power--;
            }
            if(f==0)
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        printf("Case %ld: %ld\n",cs++,ans);
    }
    return 0;
}
