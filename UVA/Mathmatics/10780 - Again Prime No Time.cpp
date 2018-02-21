#include<bits/stdc++.h>
using namespace std;
#define inf 10001

int p[inf];
int check[inf];
int f[inf][1250];

void PRIME()
{
    int i,j;
    //for(i=3;i<=inf;i+=2)
      //  check[i]=0;
    for(i=3;i*i<=inf;i+=2)
    {
        if(check[i]==0)
        {
            for(j=i*i;j<=inf;j+=i+i)
                check[j]=1;
        }
    }
    p[0]=2;
    j=1;
    for(i=3;i<=inf;i+=2)
        if(check[i]==0) p[j++]=i;
}

void factor(int n)
{
    int m=n;
    int i,j;
    for(i=0;;i++){
        if(n==1) break;
        int x=0;
        while(n%p[i]==0){
            x++;
            n=n/p[i];
        }
        //cout<<n<<" "<<p[i]<<" "<<x<<endl<<endl;
        f[m][i]=x;
    }
    for(i=0;i<1250;i++) f[m][i] = f[m][i]+f[m-1][i];
}

int main(){
    PRIME();

    //cout<<"prime generated"<<endl;
    int i,j;
    //for(i=0;i<=15;i++) cout<<v[i]<<" ";
    //factor(50);
    for(i=1;i<inf;i++){
        factor(i);
    }
    //cout<<"factor generated"<<endl;
    //for(i=0;i<=10;i++) cout<<f[50][i]<<" ";

/*for(i=0;i<=10;i++) cout<<f[10][i]<<" ";
cout<<endl;
for(i=0;i<=10;i++) cout<<f[2][i]<<" ";
cout<<endl;
for(i=0;i<=10;i++) cout<<f[4][i]<<" ";
cout<<endl;
*/
    int test,cs=1,a,b;
    scanf("%d",&test);
    while(test--){
        scanf("%d%d",&a,&b);
        printf("Case %d:\n",cs++);
        int ans=inf,aa[1250];
        for(i=0;i<1250;i++) aa[i] = f[a][i] - f[a-1][i];
        for(i=0;i<1250;i++){
            if(aa[i]>f[b][i]){
                ans=-1;
                //cout<<i<<"break"<<endl;
                break;
            }
            else{
                if(aa[i]){
                    ans = min(ans,f[b][i]/aa[i]);
                    //cout<<ans<<endl;
                }
            }
        }
        if(ans==-1) printf("Impossible to divide\n");
        else printf("%d\n",ans);
    }
    return 0;
}
