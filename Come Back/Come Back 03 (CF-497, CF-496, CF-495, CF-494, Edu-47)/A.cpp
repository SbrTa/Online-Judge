#include<bits/stdc++.h>
using namespace std;
#define LL long long


int main()
{
    LL n,m,i,j,a[1003];
    cin>>n>>m;
    stack<LL>cost,bill;

    for(i=0;i<n;i++) cin>>a[i];
    for(i=n-1;i>=0;i--) cost.push(a[i]);

    for(i=0;i<m;i++) cin>>a[i];
    for(i=m-1;i>=0;i--) bill.push(a[i]);

    LL s=0;
    while(1){
        if(bill.empty() || cost.empty()) break;
        if(bill.top()>=cost.top()){
            bill.pop();
            s++;
        }
        cost.pop();
    }
    cout<<s<<endl;
    return 0;
}

