#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

vector<long>v[1000006];

int main()
{
    long n,m,i,a,b;
    while(scanf("%ld%ld",&n,&m)==2)
    {
        for(i=1;i<=n;i++)
            v[i].clear();

        for(i=1;i<=n;i++)
        {
            scanf("%ld",&a);
            v[a].push_back(i);
        }
        while(m--)
        {
            scanf("%ld%ld",&a,&b);
            if(a>v[b].size())
                printf("0\n");
            else
                printf("%ld\n",v[b][a-1]);
        }
    }
    return 0;
}
