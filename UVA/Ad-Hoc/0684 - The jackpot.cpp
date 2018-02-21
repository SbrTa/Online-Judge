#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,sum,mx,a;
    while(scanf("%d",&n) && n){
        sum=0;
        mx=0;
        for(i=0;i<n;i++){
            scanf("%d",&a);
            sum+=a;
            if(sum>=0){
                mx = max(sum,mx);
            }
            else sum=0;
        }
        if(mx) printf("The maximum winning streak is %d.\n",mx);
        else printf("Losing streak.\n");
    }

    return 0;
}
