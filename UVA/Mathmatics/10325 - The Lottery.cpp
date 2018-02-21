#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    vector<long>v;
    long n,m,i,j,a;
    while(scanf("%ld%ld",&n,&m)==2)
    {
        v.clear();
        for(i=0;i<m;i++)
        {
            scanf("%ld",&a);
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        for(i=0;i<m;i++)
        {
            for(j=i+1;j<m;j++)
            {
                if(v[j]%v[i]==0)
                {
                    m--;
                    v.erase(v.begin()+j,v.begin()+j+1);
                }
            }
        }

        //inclusion exclusion
        long pw=pow(2,m),lcm,cnt,ans=0;
        for(i=1;i<pw;i++)
        {
            lcm=1;
            cnt=0;
            for(j=m-1;j>=0;j--)
            {
                if(i&(1<<j))
                {
                    lcm = (lcm/__gcd(lcm,v[j]))*v[j];
                    cnt++;
                }
            }
            if(cnt%2==1) ans=ans+(n/lcm);
            else ans=ans-(n/lcm);
        }
        printf("%ld\n",n-ans);
    }
    return 0;
}
