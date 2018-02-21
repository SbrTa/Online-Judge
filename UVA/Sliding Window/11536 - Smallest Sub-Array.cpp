#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int v[1000005];

int main()
{
    long n,m,k,i,j,t,cs=1;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld%ld%ld",&n,&m,&k);
        v[1]=1;
        v[2]=2;
        v[3]=3;
        for(i=4;i<=n;i++)
            v[i] = (v[i-1]+v[i-2]+v[i-3])%m + 1;

        //for(i=1;i<=n;i++) cout<<v[i]<<" ";
        //cout<<endl;
        //5 20 12 4
        int kk[111];
        for(i=0;i<=k;i++) kk[i]=-1;

        long front=1,rear=1,cnt=0,ans=n+1;

        for(i=1;i<=n;i++)
        {
            rear++;
            if(v[i]<=k)
            {
                if(kk[v[i]]<front) cnt++;
                kk[v[i]]=i;
            }
            if(cnt==k)
            {
                while(cnt>=k)
                {
                    //cout<<cnt<<endl<<rear<<"-"<<front<<endl;
                    if(ans>(rear-front)) ans=rear-front;
                    if(v[front]<=k && kk[v[front]]<=front) cnt--;
                    front++;
                    //cout<<"ans="<<ans<<endl;
                }
            }
        }
        printf("Case %ld: ",cs++);
        if(ans>n) printf("sequence nai\n");
        else printf("%ld\n",ans);
    }
    return 0;
}
