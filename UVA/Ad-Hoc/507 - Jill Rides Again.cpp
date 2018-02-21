#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,n,test,cs=1,a;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        int start,stop, x=1,mx=-1,sum=0;
        for(i=1;i<n;i++){
            scanf("%d",&a);
            if(sum+a>=0){
                sum = sum+a;
                if(sum>mx || (sum==mx && i+1-x>stop-start)){
                    mx=sum;
                    stop=i+1;
                    start=x;
                }
            }
            else{
                sum=0;
                x=i+1;
            }
        }
        if(mx>=0)printf("The nicest part of route %d is between stops %d and %d\n",cs++,start,stop);
        else printf("Route %d has no nice parts\n",cs++);
    }
    return 0;
}
