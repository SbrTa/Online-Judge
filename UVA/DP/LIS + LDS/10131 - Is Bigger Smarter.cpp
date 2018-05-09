#include<bits/stdc++.h>
using namespace std;

struct elephant
{
    int n,w,s;
}epp[1011];

bool srt(elephant a, elephant b)
{
    if(a.w<b.w) return true;
    if(a.w==b.w && a.s>b.s) return true;
    return false;
}

int dp[1011],dir[1011],n;

int lis(int l)
{
    if(l==n) return 0;
    if(dp[l]>=0) return dp[l];
    int mxx = 0;
    for(long i=l+1;i<n;i++){
        if(epp[i].w>epp[l].w && epp[i].s<epp[l].s){
            lis(i);
            if(dp[i]>mxx){
                mxx=dp[i];
                dir[l]=i;//epp[l].n;
            }
        }
    }
    dp[l] = mxx+1;
    return dp[l];
}

int main()
{
    int i,j;
    n=0;
    while(scanf("%d%d",&epp[n].w,&epp[n].s)==2){
        epp[n].n=1+n;
        n++;
    }
    sort(epp,epp+n,srt);
    //for(i=0;i<n;i++) cout<<epp[i].n<<" "<<epp[i].w<<" "<<epp[i].s<<endl;
    for(i=0;i<=n;i++) dp[i] = dir[i] = -1;
    int last=0,mx=0;
    for(i=0;i<n;i++){
        dp[i]=lis(i);
        //cout<<dp[i]<<endl;
        if(dp[i]>mx){
            mx=dp[i];
            last = i;//epp[i].n;
        }
    }
    //for(i=0;i<=n;i++) cout<<dir[i]<<endl;

    printf("%d\n",mx);
    while(last!=-1){
        printf("%d\n",epp[last].n);
        last=dir[last];
    }
    return 0;
}
