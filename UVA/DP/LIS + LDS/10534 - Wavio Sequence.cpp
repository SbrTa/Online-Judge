#include<bits/stdc++.h>
using namespace std;
#define inf 2000000000
long a[10004],b1[10004],c1[10004],b2[10004],c2[10004],n;

void binary_lis()
{
    b1[0]=-inf;
    long i,j,low,mid,high,l=0;
    for(i=0;i<n;i++){
    //for(i=0;i<n;i++){
        low=0;
        high=l;
        while(low<=high){
            mid=(low+high)/2;
            if(a[i]>b1[mid]) low=mid+1;
            else high=mid-1;
        }
        c1[i]=low;
        b1[low]=a[i];
        if(low>l) l=low;
    }
}

void rev_binary_lis()
{
    b2[0]=-inf;
    long i,j,low,mid,high,l=0;
    for(i=n-1;i>=0;i--){
    //for(i=0;i<n;i++){
        low=0;
        high=l;
        while(low<=high){
            mid=(low+high)/2;
            if(a[i]>b2[mid]) low=mid+1;
            else high=mid-1;
        }
        c2[i]=low;
        b2[low]=a[i];
        if(low>l) l=low;
    }
}

long min(long x, long y)
{
    return (x<y)?x:y;
}

int main()
{
    long i;
    while(scanf("%ld",&n)==1){
        for(i=0;i<n;i++){
            scanf("%ld",&a[i]);
            b1[i]=inf;
            b2[i]=inf;
        }
        binary_lis();
        rev_binary_lis();
        long l=0;
        //for(i=0;i<n;i++) cout<<c1[i]<<" "; cout<<endl;
        //for(i=0;i<n;i++) cout<<c2[i]<<" "; cout<<endl;
        for(i=0;i<n;i++)
            if(min(c1[i],c2[i])*2-1>l) l=min(c1[i],c2[i])*2-1;
        printf("%ld\n",l);
    }
    return 0;
}
