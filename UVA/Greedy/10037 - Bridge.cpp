#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#define inf 1000006
using namespace std;

int main()
{
    int t,n,i,j,a,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        deque<int>eipar;
        vector<pair<int,int> >jay;
        vector<int>ase;
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&a);
            eipar.push_back(a);
        }
        sort(eipar.begin(),eipar.end());

        if(cs>1) printf("\n");
        cs++;
        if(n==1)
        {
            printf("%d\n%d\n",a,a);
            continue;
        }

        long time=0;
        int a,b,c,d;

        while(1)
        {
            int sz=eipar.size();
            a=eipar[0];
            b=eipar[1];
            if(sz==2)
            {
                jay.push_back(make_pair(a,b));
                time+=b;
                break;
            }
            if(sz==3)
            {
                c=eipar[2];
                jay.push_back(make_pair(a,c));
                ase.push_back(a);
                jay.push_back(make_pair(a,b));
                time+=(c +a+ b);
                break;
            }
            c=eipar[sz-2];
            d=eipar[sz-1];

            int first = d +a +c +a;
            int second = b +a +d +b;
            if(first<=second)
            {
                jay.push_back(make_pair(a,d));
                ase.push_back(a);
                jay.push_back(make_pair(a,c));
                ase.push_back(a);
                time+=first;
            }
            else
            {
                jay.push_back(make_pair(a,b));
                ase.push_back(a);
                jay.push_back(make_pair(c,d));
                ase.push_back(b);
                time+=second;
            }
            eipar.pop_back();
            eipar.pop_back();
        }
        n=jay.size();
        printf("%ld\n",time);
        for(i=0;i<n;i++)
        {
            if(i!=0) cout<<ase[i-1]<<endl;
            printf("%d %d\n",jay[i].first,jay[i].second);
        }
    }
    return 0;
}

