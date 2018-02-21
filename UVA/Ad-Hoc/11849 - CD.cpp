#include<bits/stdc++.h>
using namespace std;
long long a[1000005],b[1000005];
int main()
{
    long long n,m,i,j,count,flag;
    while(scanf("%lld%lld",&n,&m)==2)
    {
        if(n==0&&m==0)
            break;
        count=0;
        flag=0;
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        for(i=0;i<m;i++)
            scanf("%lld",&b[i]);
        for(i=0,j=0;i<n;i++)
        {
            if(flag==1)
                break;
            for(;;)
            {
                if(j>=m)
                {
                    flag=1;
                    break;
                }
                if(a[i]==b[j])
                {
                    count++;
                    j++;
                    break;
                }
                else if(a[i]<b[j])
                    break;
                else
                    j++;
            }
        }
        printf("%lld\n",count);
    }
    return 0;
}
