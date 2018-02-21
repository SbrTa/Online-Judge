#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int i,cs=1,n,ans[1002];
    for(i=1;i<=1000;i++) ans[i]=-1;
    for(n=1;n<=1000;n++)
    {
        int sum=0;
        for(i=1;i*i<=n;i++)
        {
            if(i*i==n) sum+=i;
            else if(n%i==0) sum=sum+i+(n/i);
        }
        if(sum<=1000) ans[sum]=n;
    }
    while(scanf("%d",&n)==1 && n)
        printf("Case %d: %d\n",cs++,ans[n]);
    return 0;
}
