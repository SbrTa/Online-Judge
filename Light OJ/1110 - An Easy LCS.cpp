#include<bits/stdc++.h>
using namespace std;

string a,b,sol,ab[111],dp[111][111];
int aa,bb,ind;

string MIN(string aa, string bb)
{
    if(aa.size()>bb.size()) return aa;
    if(aa.size()<bb.size()) return bb;
    return (aa<bb)?aa:bb;
}

string lcs(int i, int j)
{
    if(i==aa || j==bb) return "";
    if(dp[i][j]!="-") return dp[i][j];
    string a1,a2,a3,mn;
    a1 = lcs(i+1,j);
    a2 = lcs(i,j+1);
    mn = MIN(a1,a2);
    if(a[i]==b[j]){
        a3 = a[i] + lcs(i+1,j+1);
        mn = MIN(mn,a3);
    }
    return dp[i][j]=mn;
}

int main()
{
    int test,i,j,cs=1;
    scanf("%d\n",&test);
    while(test--){
        //getchar();
        cin>>a>>b;
        aa = a.size();
        bb = b.size();
        for(i=0;i<=aa;i++){
            for(j=0;j<=bb;j++)
                dp[i][j]="-";
        }
        printf("Case %d: ",cs++);
        string n = lcs(0,0);
        //cout<<n<<endl;
        if(n=="") printf(":(\n");
        else cout<<n<<endl;
    }
    return 0;
}
