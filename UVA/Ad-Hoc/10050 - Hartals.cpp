#include<bits/stdc++.h>
using namespace std;
#define ind(n) scanf("%d",&n)

int main()
{
    int test,n,day[3655],p,m,i;
    ind(test);
    while(test--)
    {
        memset(day,0,sizeof(day));
        ind(n);
        ind(p);
        while(p--)
        {
            ind(m);
            for(i=m;i<=n;i+=m)
            {
                if(i%7==0||i%7==6)
                    continue;
                day[i]=1;
            }
        }
        int hortal=0;
        for(i=1;i<=n;i++)
            if(day[i]==1) hortal++;
        printf("%d\n",hortal);
    }
    return 0;
}
