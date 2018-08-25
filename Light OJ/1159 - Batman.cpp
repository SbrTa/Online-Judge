#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;
int la,lb,lc;
string dp[55][55][55];

string max(string xx, string yy)
{
    return (xx.size()>yy.size())?xx:yy;
}

string call(int i, int j, int k)
{
    if(i==la || j==lb || k==lc) return "";
    if(dp[i][j][k]!="-") return dp[i][j][k];
    string x,y,z,mx1,mx2;
    x=call(i+1,j,k); y=call(i,j+1,k); z=call(i,j,k+1);
    mx1 = max(x,max(y,z));
    x=call(i+1,j+1,k); y=call(i,j+1,k+1); z=call(i+1,j,k+1);
    mx2 = max(x,max(y,z));
    string mx = max(mx1,mx2);

    if(a[i]==b[j] && a[i]==c[k]){
        x=a[i]+call(i+1,j+1,k+1);
        mx=max(mx,x);
    }
    return dp[i][j][k]=mx;
}

int main()
{
    int test,cs=1,i,j,k;
    scanf("%d",&test);
    while(test--)
    {
        getchar();
        cin>>a>>b>>c;
        //swap(a,c);
        la=a.size();
        lb=b.size();
        lc=c.size();
        for(i=0;i<=la;i++)
            for(j=0;j<=lb;j++)
                for(k=0;k<=lc;k++) dp[i][j][k]="-";
        d=call(0,0,0);
        printf("Case %d: %d\n",cs++,d.size());
    }
    return 0;
}
