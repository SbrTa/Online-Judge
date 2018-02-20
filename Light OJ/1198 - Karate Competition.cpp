#include<bits/stdc++.h>
using namespace std;
#define mem(a,n) memset(a,n,sizeof(a))

int main()
{
    int T,t,n,a[100],b[100],flag1[55],flag2[55],i,j;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>n;
        for(i=0;i<n;i++)
             cin>>a[i];
        for(i=0;i<n;i++)
            cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        mem(flag1,0);
        mem(flag2,0);

        int ans=0,last;
        for(i=0;i<n;i++)
        {
            last=-1;
            for(j=0;j<n;j++)
            {
                if(a[i]<b[j])
                    break;
                if(flag2[j]==0&&a[i]>b[j])
                    last=j;
            }
            if(last>-1)
            {
                flag1[i]=1;
                flag2[last]=1;
                ans=ans+2;
            }
        }
        //cout<<ans<<endl;
        for(i=0;i<n;i++)
        {
            if(flag1[i]==1)
                continue;
            last=-1;
            for(j=0;j<n;j++)
            {
                if(a[i]<b[j])
                    break;
                if(flag2[j]==0&&a[i]==b[j])
                {
                    last=j;
                    break;
                }
            }
            if(last>-1)
            {
                flag2[last]=1;
                ans=ans+1;
            }
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
