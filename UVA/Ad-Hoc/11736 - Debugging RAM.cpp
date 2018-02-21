#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#define inf 1000006
using namespace std;

unsigned long long pow(int p)
{
    unsigned long long ans=1;
    for(int i=0;i<p;i++) ans=ans*2;
    return ans;
}

int main()
{
    int b,n,m,i,j,l,q;
    string s;
    while(~scanf("%d%d",&b,&n))
    {
        vector<pair<string,unsigned long long> >v;
        map<string,int>mp;
        unsigned long long ans;

        for(i=0;i<n;i++)
        {
            cin>>s>>m;
            v.push_back(make_pair(s,m));
        }
        for(i=0;i<n;i++)
        {
            ans=0;
            int p = b*v[i].second;
            string str;
            for(j=0;j<v[i].second;j++)
            {
                cin>>s;
                str=str+s;
            }
            for(j=0;j<p;j++)
            {
                if(str[j]=='1') ans=ans+pow(p-j-1);
            }
            v[i].second=ans;
            mp[v[i].first]=i+1;
        }
        scanf("%d",&q);
        while(q--)
        {
            cin>>s;
            if(!mp[s]) cout<<s<<'='<<endl;
            else cout<<s<<'='<<v[mp[s]-1].second<<endl;
        }
    }
    return 0;
}


/*
4 4
ab 2
Cd 2
ef 3
gh 1
0101
1111
1111
0101
1010
1010
1010
1000
4
Ab
Cd
ef
gh
*/

