#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#define inf 1000006
using namespace std;

int main()
{
    long M,n,i;
    while(~scanf("%ld%ld",&M,&n) && M&&n)
    {
        vector<pair<long,long> >v;
        long p,r,left,right;
        for(i=0;i<n;i++)
        {
            scanf("%ld%ld",&p,&r);
            left = p-r;
            right = p+r;
            v.push_back(make_pair(left,right));
        }
        sort(v.begin(),v.end());
        left=right=0;
        long c=0,f=0;

        for(i=0;i<n;)
        {
            long l,r,mx=0;
            if(right>=M) break;
            while(v[i].first<=right && i<n)
            {
                if(v[i].second-right>mx)
                {
                    mx=v[i].second-right;
                    l=v[i].first;
                    r=v[i].second;
                }
                i++;
            }
            if(mx<=0)
            {
                f=1;
                break;
            }
            c++;
            left=l;
            right=r;
        }

        if(f==1 || right<M) printf("-1\n");
        else printf("%ld\n",n-c);
    }
    return 0;
}
