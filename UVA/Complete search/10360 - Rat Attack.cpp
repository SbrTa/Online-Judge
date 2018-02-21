#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#define inf 1000006
using namespace std;

long a[1030][1030];

int main()
{
    long t,r,n,x,y,m,i,j;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld%ld",&r,&n);

        memset(a,0,sizeof(a));
        for(i=0; i<n; i++)
        {
            scanf("%ld%ld%ld",&x,&y,&m);
            a[x][y]=m;
        }

        for(i=0; i<=1025; i++)
        {
            for(j=0; j<=1025; j++)
            {
                if(j==0) continue;
                else a[i][j] = a[i][j] + a[i][j-1];
            }
        }

        long have=0;
        for(i=r; i<1025-r; i++)
        {
            for(j=r; j<1025-r; j++)
            {
                long temp=0,ii;
                for(ii=i-r; ii<=i+r; ii++)
                {
                    if(j-r==0) temp+=(a[ii][j+r]-a[ii][j-r]);
                    else temp+=(a[ii][j+r]-a[ii][j-r-1]);
                }

                if(temp>have)
                {
                    x=i;
                    y=j;
                    have=temp;
                    //cout<<x<<" "<<y<<" "<<have<<endl;
                }
            }
        }
        printf("%ld %ld %ld\n",x,y,have);
    }
    return 0;
}
