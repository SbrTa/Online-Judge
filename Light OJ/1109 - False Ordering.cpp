#include<bits/stdc++.h>
using namespace std;

struct info
{
    int d,n;
}divs[1005];

int call(int m)
{
    int i,t=0;
    for(i=1;i<=m;i++)
        if(m%i==0)
            t++;
    return t;
}

bool comp(info x, info y)
{
    if(x.d==y.d)
        return (x.n>y.n);
    else
        return (x.d<y.d);
}

int main()
{
    int test,cs=1,m,i;

    for(i=1;i<=1000;i++)
    {
        divs[i].d=call(i);
        divs[i].n=i;
    }
    sort(divs+1,divs+1001,comp);
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&m);
        printf("Case %d: %d\n",cs++,divs[m].n);
    }
    return 0;
}
