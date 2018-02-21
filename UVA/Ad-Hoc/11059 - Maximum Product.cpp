#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[20],n,cs=1;
    while(cin>>n)
    {
        int i,j;
        long max=-1,sum=0;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
        {
            sum=1;
            for(j=i;j<n;j++)
            {
                sum=sum*a[j];
                if(sum>max)
                    max=sum;
            }
        }
        if(max<0) max=0;
        printf("Case #%d: The maximum product is %ld.\n\n",cs++,max);
    }
    return 0;
}

