#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int a,b,dp[1011][1011];//visited[1011][1011];
char s1[1011],s2[1011];

int lcs(int i, int j)
{
    if(i==a || b==j){
        return 0;
    }
    if(dp[i][j]>=0) return dp[i][j];

    int x = 0;
    if(s1[i]==s2[j])    x = 1 + lcs(i+1,j+1);
    else    x = max(lcs(i+1,j) , lcs(i,j+1));

    //visited[i][j]=1;
    dp[i][j] = x;
    return dp[i][j];
}

int main()
{
    while(gets(s1)){
        gets(s2);
        //cout<<s1<<endl;
        //cout<<s2<<endl;
        a = strlen(s1);
        b = strlen(s2);
        //memset(dp,0,sizeof(dp));
        //memset(visited,0,sizeof(visited));
        for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) dp[i][j]=-1;
        printf("%d\n",lcs(0,0));
    }
    return 0;
}
