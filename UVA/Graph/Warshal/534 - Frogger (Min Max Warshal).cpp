#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;

float graph[202][202];

int sqr(int m)
{
    return m*m;
}
int abs(int m)
{
    if(m<0)
        return (-1)*m;
    return m;
}

void MinMaxWarshal(int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                graph[i][j]=min(graph[i][j],max(graph[i][k],graph[k][j]));
}


int main()
{
    vector<pair<int,int> >v;
    int n,i,j,cs=1;
    while(cin>>n&&n!=0)
    {
        v.clear();
        for(i=1;i<=n;i++)
        {
            int x,y;
            cin>>x>>y;
            v.push_back(make_pair(x,y));
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                float d;
                if(v[i].first==v[j].first && v[i].second==v[j].second)
                    d=0;
                else if(v[i].first==v[j].first)
                    d=abs(v[i].second-v[j].second);
                else if(v[i].second==v[j].second)
                    d=abs(v[i].first-v[j].first);
                else
                    d= sqrt(sqr(abs(v[i].first-v[j].first)) + sqr(abs(v[i].second-v[j].second)));

                graph[i+1][j+1]=d;
                graph[j+1][i+1]=d;
            }
        }

        MinMaxWarshal(n);
        cout<<"Scenario #"<<cs++<<endl;
        printf("Frog Distance = %.3f\n\n",graph[1][2]);
    }
    return 0;
}
