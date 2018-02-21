#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#define inf 1000006
#define eps 1e-9
using namespace std;

int main()
{
    long n,m,i;
    double w;
    while(~scanf("%ld%ld%lf",&n,&m,&w))
    {
        vector<pair<double,double> >v;
        double pos,r,left,right,d;
        for(i=0; i<n; i++)
        {
            scanf("%lf%lf",&pos,&r);
            //if(r+r<=w) continue;
            d = sqrt( (r*r) - ((w/2.0)*(w/2.0)) );
            left = pos - d;
            right = pos + d;
            v.push_back(make_pair(left,right));
        }
        sort(v.begin(),v.end());

        //cout<<endl<<endl;
        //for(i=0;i<v.size();i++) printf("%.10lf %.10lf\n",v[i].first,v[i].second);
        //cout<<endl<<endl;

        left=0;
        right=0;
        long f=1,c=0;
        for(i=0; i<n; )
        {
            //cout<<left<<" "<<right<<endl;
            double lft,rgt,mx=0;
            while(v[i].first<=right && i<n)
            {
                if(v[i].second-right>mx)
                {
                    mx=v[i].second-right;
                    lft=v[i].first;
                    rgt=v[i].second;
                }
                i++;
            }
            if(mx<=0) break;
            left=lft;
            right=rgt;
            c++;
            if(right>=m)
            {
                f=0;
                break;
            }
        }
        if(f==0) printf("%ld\n",c);
        else printf("-1\n");
    }
    return 0;
}
