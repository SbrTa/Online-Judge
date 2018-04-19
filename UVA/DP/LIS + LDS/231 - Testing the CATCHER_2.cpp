#include<bits/stdc++.h>
using namespace std;
#define inf 20000005

long a[1000000],b[1000000];//c[1000000];
long n;

long binary_lis()
{
    long i,j,low,mid,high,l=0;

    for(i=0;i<n;i++){
        low=0;
        high=l;
        while(low<=high){
            mid=(low+high)/2;
            if(b[mid]>=a[i]) low = mid+1;
            else high = mid-1;
        }

        b[low]=a[i];
        //c[i]=low;
        if(l<low) l=low;
    }
    return l;
}


int main()
{
    long i,j,cs=1;
    while(1){
        n=0;
        while(scanf("%ld",&a[n])==1){
            if(n==0 && a[n]==-1){
                n=-1;
                break;
            }
            if(a[n]==-1) break;
            b[n]=-inf;
            n++;
        }
        b[0]=inf;
        if(n==-1) break;
        long mx = binary_lis();
        //for(i=0;i<n;i++) cout<<c[i]<<" ";
        //cout<<endl;
        if(cs>1) printf("\n");
        printf("Test #%ld:\n  maximum possible interceptions: %ld\n",cs++,mx);
    }
    return 0;
}
