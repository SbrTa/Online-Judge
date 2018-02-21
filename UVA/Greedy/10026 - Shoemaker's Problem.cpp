#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

bool cmp(pair<float,int>a, pair<float,int>b)
{
    if(a.first==b.first) return (a.second<b.second);
    return (a.first>b.first);
}

int main()
{
    int t,n,i,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        vector<pair<float,int> >v;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            float a,b,c;
            scanf("%f%f",&a,&b);
            c=b/a;
            //printf("%f\n",c);
            v.push_back(make_pair(c,i));
        }
        sort(v.begin(),v.end(),cmp);
        if(cs>1) printf("\n");
        cs++;
        printf("%d",v[0].second);
        for(i=1;i<n;i++)
            printf(" %d",v[i].second);
        printf("\n");
    }
    return 0;
}
