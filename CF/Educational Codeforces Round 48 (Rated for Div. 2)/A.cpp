#include<bits/stdc++.h>
#define inf 100000000
using namespace std;

int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    int a,r=m;
    for(i=1;i<=n;i++){
        int s=0;
        scanf("%d",&a);
        if(a>=r){
            if(r){
                a = a-r;
                r=0;
                s++;
            }
        }
        else{
            r = r-a;
            a=0;
        }
        s+=(a/m);
        if(a%m){
            r = m - (a%m);
        }
        printf("%d ",s);
    }
    return 0;
}
