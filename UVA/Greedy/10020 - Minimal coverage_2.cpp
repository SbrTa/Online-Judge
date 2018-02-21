#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#define inf 1000006
using namespace std;

int main()
{
    long t,cs=1,m,i,j;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&m);
        long left,right;
        vector<pair<long,long> >v;
        while(1)
        {
            scanf("%ld%ld",&left,&right);
            if(left==0 && right==0) break;
            v.push_back(make_pair(left,right));
        }
        sort(v.begin(),v.end());
        long sz=v.size();
        i=0;
        left=0;
        right=0;
        while(1)
        {
            if(i>=sz) break;
            if(v[i].first>0) break;
            if(v[i].second>0)
            {
                left=v[i].first;
                right=v[i].second;
            }
            i++;
        }

        stringstream fout;

        long f=0,c=0;
        if(right<=0) f=1;
        for(--i;i<sz;)
        {
            c++;
            fout<<left<<" "<<right<<endl;
            if(right>=m) break;
            long l=0,r=0,mx=0;
            while(v[i].first<=right && i<sz)
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
            left=l;
            right=r;
        }
        if(cs>1) printf("\n");
        cs++;
        if(f==1)
        {
            printf("0\n");
            continue;
        }
        printf("%ld\n",c);
        cout<<fout.str();
    }
    return 0;
}
