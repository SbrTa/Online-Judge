#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#define inf 2000000+2
#define MX 2000000+2
using namespace std;

int main()
{
    long n,i,j,a[10004],firstCase=1;
    while(~scanf("%ld",&n) && n)
    {
        for(i=0;i<n;i++)
            scanf("%ld",&a[i]);
        sort(a,a+n);
        long p=0;
        for(i=0;i<n;)
        {
            long x=0,temp=a[i];
            while(temp==a[i] && i<n)
            {
                i++;
                x++;
            }
            if(x>p) p=x;
        }

        if(!firstCase) printf("\n");
        firstCase=0;
        printf("%ld\n",p);
        for(i=0;i<p;i++)
        {
            for(j=i;j<n;j+=p)
            {
                if(i!=j) printf(" ");
                printf("%ld",a[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
