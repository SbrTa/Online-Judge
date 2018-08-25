#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define x first
#define y second
LL a[2000];

int main()
{
    LL n,k,d,i,j;
    string s;
    cin>>n>>k;
    cin>>s;
    for(i=0;i<n;i++) a[i] = s[i] - 'a' + 1;
    sort(a,a+n);
    //for(i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;

    LL taken=0,t=0,last=-2;

    for(i=0;i<n;i++){
        if(a[i]-last > 1){
            taken++;
            t+=a[i];
            last=a[i];
        }
        if(taken==k){
            cout<<t<<endl;
            return 0;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}
