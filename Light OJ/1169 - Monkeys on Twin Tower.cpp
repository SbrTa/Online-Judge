#include<bits/stdc++.h>
using namespace std;

int n,f1[1011],f2[1011],b12[1011],b21[1011];

void call(int i)
{
    if(i==n) return;
    f1[i] = min( f1[i-1]+f1[i] , f2[i-1]+b21[i]+f1[i] );
    f2[i] = min( f2[i-1]+f2[i] , f1[i-1]+b12[i]+f2[i] );
    call(i+1);
}

int main()
{
    int i,j,test,cs=1;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&f1[i]);
        for(i=0;i<n;i++) scanf("%d",&f2[i]);
        for(i=1;i<n;i++) scanf("%d",&b12[i]);
        for(i=1;i<n;i++) scanf("%d",&b21[i]);
        call(1);
        printf("Case %d: %d\n",cs++,min(f1[n-1],f2[n-1]));
    }
    return 0;
}
