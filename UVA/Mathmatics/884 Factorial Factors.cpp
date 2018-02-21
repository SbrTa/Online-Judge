#include<bits/stdc++.h>
using namespace std;
#define max 1000002

long long prime[max],status[max],pre[max],help[max],i,j,n;

int main()
{
//Prime Generator & Pre-Calculator
    long long  p=0,count;
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
    prime[p++]=3;

    pre[2]=1;
    pre[3]=2;
    pre[4]=4;

    help[1]=0;
    help[2]=help[3]=1;
    help[4]=2;

    for(i=5; i<max; i++)
    {
        if(status[i]==0&&i%2==1)
        {
            prime[p++]=i;
            pre[i]=pre[i-1]+1;
            help[i]=1;
        }
        else
        {
            count=0;
            for(j=0; j<p; j++)
            {
                if(i%prime[j]==0)
                    break;
            }
            count=help[i/prime[j]]+1;
            help[i]=count;
            pre[i]=pre[i-1]+count;
        }
    }

//Main Code
    while(cin>>n)
        cout<<pre[n]<<endl;
    return 0;
}
