#include<bits/stdc++.h>
using namespace std;
#define inf 200000000

long a[10000],b[10000],c[10000],sol[10000],n;

long binary_lis()
{
    long i,j,low,mid,high,l=0;
    b[0]=-inf;
    for(i=0;i<n;i++){
        low=0;
        high=l;
        while(low<=high){
            mid=(low+high)/2;
            if(b[mid]<a[i]) low=mid+1;
            else high=mid-1;
        }
        b[low]=a[i];
        c[i]=low;
        if(l<low) l=low;
    }
    return l;
}

int main()
{
    char ch[100];
    long i,j,test;
    bool cs=false;
    scanf("%ld\n\n",&test);
    //getchar();
    while(test--){
        if(cs) printf("\n");
        cs=true;
        n=0;
        while(gets(ch) && strlen(ch)){
            a[n]=atoi(ch);
            b[n]=inf;
            n++;
        }
        //for(i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
        long mx=binary_lis();
        //for(i=0;i<n;i++) cout<<c[i]<<" ";cout<<endl;
        printf("Max hits: %ld\n",mx);
        long l=mx,stp=0;
        n--;
        while(n>=0){
            if(c[n]==mx && (a[n]<sol[mx+1] || !stp)){
                sol[mx]=a[n];
                mx--;
                stp=1;
            }
            n--;
        }
        for(i=1;i<=l;i++) printf("%ld\n",sol[i]);
    }
    return 0;
}
