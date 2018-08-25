#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define x first
#define y second
LL a[200];

int main()
{
    LL n,m,k,d,i,j;
    cin>>n>>k;
    for(i=0;i<k;i++){
        cin>>d;
        a[d]++;
    }

    for(m=k/n;m>0;m--){
        LL t=0;
        for(i=1;i<=100;i++){
            t+=(a[i]/m);
        }
        if(t>=n) break;
    }
    cout<<m<<endl;


    return 0;
}
