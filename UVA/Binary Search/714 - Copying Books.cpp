#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#define inf -99999999
using namespace std;

int main()
{
    long t,n,k;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld %ld",&n,&k);
        long long min=0,max=0,mid,i,j,s;
        long part,v[555];
        for(i=0;i<n;i++)
        {
            scanf("%ld",&v[i]);
            if(v[i]>min) min=v[i];
            max+=v[i];
        }

//Binary Search
        while(min<max)
        {
            mid = (min+max)/2;
            s=0;
            part=1;
            for(i=0;i<n;i++)
            {
                s+=v[i];
                if(s>mid)
                {
                    s=v[i];
                    part++;
                }
            }
            //cout<<part<<endl;
            if(part>k) min = mid+1;
            else max = mid;
            //cout<<min<<" "<<max<<endl;
        }

// Output Processing
        long p[555];
        for(i=0;i<=n;i++) p[i]=0;
        s=0;
        part=k-1;
        for(i=n-1;i>=0;i--)
        {
            s+=v[i];
            //cout<<endl<<(n-i)<<" "<<part<<endl;
            if(s>max || i<part)
            {
                //cout<<v[i]<<endl;
                part--;
                p[i+1]=1;
                s=v[i];
            }
        }

//Printing Output
        printf("%ld",v[0]);
        for(i=1;i<n;i++)
        {
            if(p[i]) printf(" /");
            printf(" %ld",v[i]);
        }
        printf("\n");
    }
    return 0;
}
