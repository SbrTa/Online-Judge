#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define inf 200000

vector<LL>p;
LL chk[inf];

void Prime()
{
    LL i,j;
    for(i=3;i<inf;i+=2){
        if(!chk[i]){
            for(j=i*i;j<inf;j+=i+i) chk[j]=1;
        }
    }
    p.push_back(2);
    for(i=3;i<inf;i+=2) if(!chk[i]) p.push_back(i);

}

int main()
{
    Prime();
    LL n,k,i,j,x,y;
    vector<LL>s;
    map<LL,LL>mp;
    //for(i=0;i<15;i++) cout<<p[i]<<" ";
    //cout<<(p[p.size()-1]*p[p.size()-1])<<endl<<endl;
    scanf("%lld",&n);
    for(k=0;k<n;k++){
        scanf("%lld",&x);
        scanf("%lld",&y);

        /////////////////////////////////////////
        if(k==0){
            LL m,sz = p.size();
            m=x;
            for(i=0;i<sz;i++){
                if(m<p[i]) break;
                if(m%p[i]==0){
                    while(m%p[i]==0) m=m/p[i];
                    s.push_back(p[i]);
                    mp[p[i]]=1;
                }
            }
            if(m>1){
                s.push_back(m);
                mp[m]=1;
            }

            m=y;
            for(i=0;i<sz;i++){
                if(m<p[i]) break;
                if(m%p[i]==0){
                    while(m%p[i]==0) m=m/p[i];
                    if(!mp[p[i]])s.push_back(p[i]);
                }
            }
            if(m>1){
                if(!mp[m])s.push_back(m);
            }
            //cout<<k<<" : ";for(i=0;i<s.size();i++) cout<<s[i]<<" "; cout<<endl;
            continue;
        }
        ////////////////////////////////////////////////

        for(i=0;i<s.size();i++){
            if(s[i]<2) continue;
            if(x%s[i]==0 || y%s[i]==0);
            else s[i] = 0;
        }
        //cout<<k<<" : ";for(i=0;i<s.size();i++) cout<<s[i]<<" "; cout<<endl;
    }

    LL f=-1;
    for(i=0;i<s.size();i++) if(s[i]>=2) f=s[i];
    cout<<f<<endl;
    return 0;
}

