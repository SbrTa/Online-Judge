#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define x first
#define y second

struct info{
    LL marks,id;
};

bool srt(info a, info b)
{
    if(a.marks>b.marks) return true;
    if(a.marks<b.marks) return false;
    if(a.id<b.id) return true;
    return false;
}

int main()
{
    LL n,m,i,j,a,b,c,d;
    vector<info>v;

    cin>>n;
    for(i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        info tmp;
        tmp.id = i+1;
        tmp.marks = a+b+c+d;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),srt);
    for(i=0;i<n;i++){
        if(v[i].id==1) cout<<(i+1)<<endl;
    }
    return 0;
}

