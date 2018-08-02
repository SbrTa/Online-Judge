#include<bits/stdc++.h>
#define inf 100000000
using namespace std;

int main()
{
    int j,i,m,n,a,b,x[100005];
    long long t=0;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a>>b;
        t+=a;
        x[i] = a-b;
    }
    if(t<=m){
        printf("0\n");
        return 0;
    }
    sort(x,x+n);
    for(i=n-1,j=0;i>=0;i--){
        t-=x[i];
        j++;
        if(t<=m){
            printf("%d\n",j);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
