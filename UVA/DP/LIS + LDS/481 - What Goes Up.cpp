#include<bits/stdc++.h>
using namespace std;
#define inf 20000005

long n,a[inf],b[inf],c[inf];
bool v[inf];

long binary_lis()
{
    long i,j,low,mid,high,l=0;

    for(i=0;i<n;i++){
        low=0;
        high=l;
        while(low<=high){
            mid=(low+high)/2;
            if(b[mid]<a[i]) low = mid+1;
            else high = mid-1;
        }
        b[low]=a[i];
        c[i]=low;
        if(l<low) l=low;
    }
    return l;
}

int main()
{
    long i,j,x;
    n=0;
    while(scanf("%ld",&a[n])==1){
        b[n]=inf;
        n++;
    }
    b[0]=-inf;
    long l = binary_lis();

    //for(i=0;i<n;i++) cout<<c[i]<< " ";
    //cout<<endl;

    printf("%ld\n-\n",l);
    long last;
    while(1){
        n--;
        if(c[n]==l){
            last=n;
            break;
        }
    }
    long sq[l+1];
    j=0;
    sq[j++]=a[last];
    for(i=last-1;i>=0;i--){
        if(c[i]+1 == c[last]){
            last = i;
            sq[j++]=a[last];
        }
    }
    for(i=l-1;i>=0;i--) printf("%ld\n",sq[i]);

    return 0;
}

/*
input: 8 1 9 8 3 4 6 1 5 2
(1) 1 3 4 6
(2) 1 3 4 5
output: 1 3 4 5
*/
