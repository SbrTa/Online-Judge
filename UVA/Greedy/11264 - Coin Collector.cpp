#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#define inf 1000006
using namespace std;

int main()
{
    long t,n,a[1111],i;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&n);
        for(i=0;i<n;i++) scanf("%ld",&a[i]);
        long long sum = 0;
        long c = 0;
        for(i=0;i<n;i++)
        {
            if(i==n-1)
            {
                if(a[i]>sum) c++;
                continue;
            }
            if(a[i]>sum && sum+a[i]<a[i+1])
            {
                c++;
                sum+=a[i];
            }
        }
        printf("%ld\n",c);
    }
    return 0;
}
