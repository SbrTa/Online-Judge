#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define x first
#define y second

int main()
{
    LL n,i,j,a=0,b=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>j;
        a+=j;
    }
    for(i=0;i<n;i++){
        cin>>j;
        b+=j;
    }
    if(b<=a) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
