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
        long ans=0;
        a[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%ld",&a[i]);
            if(a[i]-a[i-1]>ans)
                ans=a[i]-a[i-1];
        }
        long power=ans;
        for(i=1;i<=n;i++)
        {
            if(a[i]-a[i-1]==power) power--;
            else if(a[i]-a[i-1]>power)
            {
                ans++;
                break;
            }
        }
        printf("Case %ld: %ld\n",cs++,ans);
    }
    return 0;
}
