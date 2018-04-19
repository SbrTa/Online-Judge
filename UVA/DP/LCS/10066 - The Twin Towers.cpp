#include<stdio.h>

int aa,bb,a[105],b[105],dp[105][105];

int Max(int i, int j)
{
    return (i>j)?i:j;
}

int lcs(int i, int j)
{
    if(i==aa || j==bb)  return 0;
    if(dp[i][j]>=0) return dp[i][j];

    int x;
    if(a[i]==b[j])  x = 1 + lcs(i+1,j+1);
    else x = Max(lcs(i+1,j) , lcs(i,j+1));

    dp[i][j] = x;
    return dp[i][j];
}

int main()
{
    int i,j,cs=1;
    while(scanf("%d%d",&aa,&bb) && aa+bb!=0){
        for(i=0;i<aa;i++){
            scanf("%d",&a[i]);
            for(j=0;j<bb;j++) dp[i][j]=-1;
        }
        for(i=0;i<bb;i++) scanf("%d",&b[i]);
        //if(cs>1) printf("\n");
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",cs++,lcs(0,0));
    }

    return 0;
}
