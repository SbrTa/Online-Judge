#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
    long n,s,i,j,a,v[100005];
    //vector<long>v;
    while(scanf("%ld%ld",&n,&s)==2)
    {
        //v.clear();
        int f=0;
        for(i=0;i<n;i++)
        {
            scanf("%ld",&v[i]);
            //v.push_back(a);
            if(v[i]>=s) f=1;
        }
        if(f==1)
        {
            printf("1\n");
            continue;
        }

        //Sliding Window
        long front=0,rear=0,ans=n+1,sum=0;
        for(i=0;i<n;i++)
        {
            sum+=v[i];
            if(sum>=s)
            {
                rear=i;
                while(sum>=s)
                {
                    if(ans>(rear-front+1)) ans=rear-front+1;
                    sum=sum-v[front];
                    front++;
                    //cout<<ans<<endl;
                }
            }
        }
        if(ans>n) ans=0;
        printf("%ld\n",ans);
    }
    return 0;
}
