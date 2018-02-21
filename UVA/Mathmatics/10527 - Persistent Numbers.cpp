#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstdlib>
#define inf 100
#define eps 1e-9
using namespace std;

vector<int>v,vv,ans;

int Do()
{
    int i,j,r,sz,n,d;
    while(v.size()>1)
    {
        for(n=9; n>=2; n--)
        {
            vv.clear();
            r=0;
            sz=v.size();
            for(i=0; i<sz; i++)
            {
                d=(r*10+v[i])/n;
                r=(r*10+v[i])%n;
                vv.push_back(d);
            }
            if(r==0)
            {
                ans.push_back(n);
                v.clear();
                sz=vv.size();
                int zero=1;
                for(i=0;i<sz;i++)
                {
                    if(zero&&vv[i]==0)
                        continue;
                    zero=0;
                    v.push_back(vv[i]);
                }
                break;
            }
        }
        if(r) return 1;
    }
    if(v[0]>0) ans.push_back(v[0]);
    return 0;
}

int main()
{
    string str;
    int i,j;
    while(cin>>str)
    {
        if(str[0]=='-' && str[1]=='1')
            break;
        if(str.size()==1)
        {
            cout<<'1'<<str<<endl;
            continue;
        }
        v.clear();
        ans.clear();
        for(i=0; i<str.size(); i++)
            v.push_back(str[i]-'0');
        //for(i=0;i<v.size();i++) cout<<v[i];
        //cout<<endl;
        if(Do()==1)
        {
            printf("There is no such number.\n");
            continue;
        }
        sort(ans.begin(),ans.end());
        for(i=0;i<ans.size();i++)
            printf("%d",ans[i]);
        puts("");
    }
    return 0;
}
