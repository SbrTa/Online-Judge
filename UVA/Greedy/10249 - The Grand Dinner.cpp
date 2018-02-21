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

int main()
{
    int team,table,i,j,a;
    while(~scanf("%d%d",&team,&table) && team&&table)
    {
        vector<pair<int,int> >v;
        vector<int>seat;
        for(i=1;i<=team;i++)
        {
            scanf("%d",&a);
            v.push_back(make_pair(a,i));
        }
        for(i=0;i<table;i++)
        {
            scanf("%d",&a);
            seat.push_back(a);
        }
        sort(v.begin(),v.end());
        //for(i=0;i<team;i++) cout<<v[i].first<<" "<<v[i].second<<endl;

        vector<int>p[100];
        int f=1;
        int n=0;
        for(i=team-1;i>=0;i--)
        {
            int start=n,stop,again=0,member=v[i].first;
            for( ; ; )
            {
                if(member==0 || again==2) break;
                if(n==table)
                {
                    n=0;
                    again++;
                }
                if(seat[n])
                {
                    p[v[i].second].push_back(n);
                    seat[n]--;
                    member--;
                    stop=n;
                    //cout<<n<<" ";
                }
                n++;
            }
            if(again==2 || (again==1 && stop>=start))
            {
                f=0;
                break;
            }
            //cout<<endl;
        }
        if(f==0)
        {
            printf("0\n");
            continue;
        }
        printf("1\n");
        for(i=1;i<=team;i++)
        {
            printf("%d",p[i][0]+1);
            for(j=1;j<p[i].size();j++)
                printf(" %d",p[i][j]+1);
            printf("\n");
        }

    }
    return 0;
}
