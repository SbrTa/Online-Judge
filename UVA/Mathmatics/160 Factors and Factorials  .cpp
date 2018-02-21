#include<bits/stdc++.h>
using namespace std;
#define max 101

int main()
{
    int prime[max],status[max],calc[max],i,j,k,l,n,p=0;

//Prime Generator
    for(i=3; i<=max; i+=2)
        status[i]=0;
    for(i=3; i*i<=max; i+=2)
    {
        if(status[i]==0)
        {
            for(j=i*i; j<=max; j+=i+i)
                status[j]=1;
        }
    }
    prime[p++]=2;
    for(i=3; i<=max; i+=2)
    {
        if(status[i]==0)
            prime[p++]=i;
    }

//Main Code
    while(cin>>n)
    {
        if(n==0)
            break;
        printf("%3d! =",n);
        if(n==1)
        {
            puts("");
            continue;
        }
        memset(calc,0,sizeof(calc));
        l=0;
        for(j=2; j<=n; j++)
        {
            int m=j;
            for(i=0;;)
            {
                if(m==1)
                {
                    if(i>l)
                        l=i;
                    break;
                }
                if(m%prime[i]==0)
                {
                    m=m/prime[i];
                    calc[i]++;
                }
                else
                    i++;
            }
        }
        j=0;
        for(i=0; i<=l; i++)
        {
            j++;
            if(j==16)
            {
                j=1;
                printf("\n      ");
            }
            printf("%3d",calc[i]);
        }
        puts("");
    }
    return 0;
}
