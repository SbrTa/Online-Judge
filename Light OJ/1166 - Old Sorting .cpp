#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int t,T,n,i,j,a[10000];
    cin>>T;
    for(t=1;t<=T;t++)
    {
        int count=0;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];
        for(i=1;i<=n;i++)
        {
            if(a[i]==i)
                continue;
            for(j=i;j<=n;j++)
            {
                if(a[j]==i)
                {
                    a[j]=a[i];
                    a[i]=i;
                    count++;
                    break;
                }
            }
        }
        printf("Case %d: %d\n",t,count);
    }
    return 0;
}
