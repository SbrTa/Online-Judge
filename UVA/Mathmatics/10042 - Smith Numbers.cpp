#include<bits/stdc++.h>
using namespace std;
#define inf 100005
#define LL long long


int chk[inf];
vector<int>p;

void prime()
{
    int i,j;
    for(i=4;i<inf;i+=2) chk[i]=1;
    for(i=3;i*i<inf;i+=2){
        if(!chk[i]){
            for(j=i*i; j<inf; j+=i+i){
                chk[j]=1;
            }
        }
    }
    p.push_back(2);
    for(i=3;i<inf;i+=2) if(!chk[i]) p.push_back(i);
}

int findsum(int n)
{
    int sum=0;
    while(n){
        sum+=(n%10);
        n = n/10;
    }
    return sum;
}

int main()
{
    prime();
    int i,j,n,m,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ps = p.size();

        for(m=n+1;;m++){
            //if(m>n+10) break;
            int sum1=findsum(m);
            int sum=0,x=m;
            for(i=0;i<ps && x>=p[i];i++){
                while(x%p[i]==0){
                    x/=p[i];
                    sum+=findsum(p[i]);
                    //cout<<"in "<<x<<" "<<p[i]<<endl;
                }
            }
            if(x>1) sum+=findsum(x);
            //cout<<m<<" "<<x<<endl<<endl;
            if(x==m) continue;
            if(m<inf && !chk[m]) continue;
            if(sum==sum1){
                printf("%d\n",m);
                break;
            }
            //cout<<m<<endl<<sum1<<endl<<sum<<endl<<endl;
        }
    }
    return 0;
}

//4937774
