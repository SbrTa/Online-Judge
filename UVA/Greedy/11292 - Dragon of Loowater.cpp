#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#define inf 1000006
using namespace std;

int main()
{
    long h,m,head[20000+5],man[20000+5],i;
    while(~scanf("%ld%ld",&h,&m) && h&&m)
    {
        for(i=0;i<h;i++) scanf("%ld",&head[i]);
        for(i=0;i<m;i++) scanf("%ld",&man[i]);

        if(m<h)
        {
            printf("Loowater is doomed!\n");;
            continue;
        }

        sort(head,head+h);
        sort(man,man+m);

        long ans=0,j=0,f=0;
        for(i=0;i<h;i++)
        {
            while(1)
            {
                if(j==m)
                {
                    f=1;
                    break;
                }
                if(man[j]>=head[i])
                {
                    ans+=man[j];
                    j++;
                    break;
                }
                j++;
            }
            if(f==1) break;
        }
        if(f==0) printf("%ld\n",ans);
        else printf("Loowater is doomed!\n");
    }
    return 0;
}

