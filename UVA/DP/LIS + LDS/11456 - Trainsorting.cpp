#include<bits/stdc++.h>
using namespace std;
#define inf 2000000000
long a[2002],b1[2002],b2[2002],c1[2002],c2[2002],n;

void binary_lis()
{
    long i,j,low,mid,high,l=0;
    b1[0]=-inf;
    for(i=n-1,j=0;i>=0;i--,j++){
        low=0;
        high=l;
        while(low<=high){
            mid=(low+high)/2;
            if(b1[mid]<a[i]) low=mid+1;
            else high=mid-1;
        }
        c1[j]=low;
        b1[low]=a[i];
        if(l<low) l=low;
    }
}

void binary_lds()
{
    long i,j,low,mid,high,l=0;
    b2[0]=inf;
    for(i=n-1,j=0;i>=0;i--,j++){
        low=0;
        high=l;
        while(low<=high){
            mid=(low+high)/2;
            if(b2[mid]>a[i]) low=mid+1;
            else high=mid-1;
        }
        c2[j]=low;
        b2[low]=a[i];
        if(l<low) l=low;
    }
}

int main()
{
    long i,j,test;
    scanf("%ld",&test);
    while(test--){
        scanf("%ld",&n);
        for(i=0;i<n;i++){
            scanf("%ld",&a[i]);
            b1[i]=inf;
            b2[i]=-inf;
        }
        //for(i=0;i<n;i++) a[n-i-1]=aa[i];
        //for(i=0;i<n;i++) cout<<a[i]<<" ";
        //cout<<endl;
        binary_lis();
        binary_lds();
        long mx=0;
        for(i=n-1;i>=0;i--)// cout<<c1[i]<<" "<<c2[i]<<endl;
        if(c1[i]+c2[i]-1>mx) mx=c1[i]+c2[i]-1;
        printf("%ld\n",mx);
    }
    return 0;
}
/*
1
8
8 1 9 3 4 6 5 2
*/
