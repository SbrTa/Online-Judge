#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#define inf 1000000
using namespace std;

int main()
{
    int n,a[55],i,j;
    while(cin>>n && n)
    {
        for(i=0;i<n;i++)
            cin>>a[i];
        int cnt=0,m=0;
        sort(a,a+n);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                m++;
                if(__gcd(a[i],a[j])==1)
                    cnt++;
            }
        }
        //cout<<m<<" "<<cnt<<endl;
        if(cnt==0)
        {
            printf("No estimate for this data set.\n");
            continue;
        }
        double ans = sqrt( (double)(6*m) / (double)cnt);
        printf("%.6lf\n",ans);
    }
    return 0;
}
