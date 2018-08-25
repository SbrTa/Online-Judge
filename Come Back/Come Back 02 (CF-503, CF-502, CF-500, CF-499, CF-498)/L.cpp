#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define x first
#define y second


int main()
{
    LL n,m,i,j;
    cin>>n;
    m = sqrt(n);
    for(i=1;i<=n/m;i++){
        LL a = n-(m*i)+1;
        for(j=1;j<=m;j++,a++) printf("%lld ",a);
    }
    for(i=1;i<=n%m;i++) printf("%lld ",i);

    return 0;
}

