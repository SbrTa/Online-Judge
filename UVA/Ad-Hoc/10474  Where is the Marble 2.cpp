#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,m,i,a[100000],b[100000],t=1,j,pos,found;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)
            break;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(i=0; i<m; i++)
            scanf("%d",&b[i]);
        sort(a,a+n);
        printf("CASE# %d:\n",t);
        for(i=0; i<m; i++)
        {
            found=0;
            for(j=0; j<n; j++)
            {
                if(b[i]==a[j])
                {
                    pos=j+1;
                    found=1;
                    break;
                }
            }
            if(found==1)
                printf("%d found at %d\n",b[i],pos);
            else
                printf("%d not found\n",b[i]);
        }
        t++;
    }
    return 0;
}
