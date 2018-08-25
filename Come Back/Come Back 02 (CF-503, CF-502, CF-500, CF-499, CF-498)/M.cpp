#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define x first
#define y second

LL abs(LL n)
{
    if(n<0) n=n*(-1);
    return n;
}

int main()
{
    LL n,h,a,b,k,i,j;
    cin>>n>>h>>a>>b>>k;
    while(k--){
        LL t1,l1,t2,l2;
        cin>>t1>>l1>>t2>>l2;
        if(t1==t2){
            cout<<(abs(l1-l2))<<endl;
            continue;
        }
        if(l1==l2 && (l1==a || l1==b)){
            cout<<(abs(t1-t2))<<endl;
            continue;
        }
        LL mn=1000000000000;
        mn = min(mn,abs(l1-a)+abs(l2-a));
        mn = min(mn,abs(l1-b)+abs(l2-b));

        mn += abs(t1-t2);
        cout<<mn<<endl;
    }

    return 0;
}


/*
2 6 2 5 12
1 1 1 1
1 1 1 2
1 2 2 2
1 2 1 5
1 6 2 3
1 2 2 2
1 6 2 1
1 4 2 4
1 3 2 4
1 2 2 5
1 3 2 3
1 2 2 3
*/
