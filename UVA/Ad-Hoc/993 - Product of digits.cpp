#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 32000
using namespace std;

int main()
{
    long t,n,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int>ans;
        if(n==1) ans.push_back(1);
        for(i=9;i>1 && n>1;i--)
        {
            while(n%i==0)
            {
                n=n/i;
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        if(ans.size()==0 || n>1) cout<<"-1\n";
        else
        {
            for(i=0;i<ans.size();i++)
                cout<<ans[i];
            cout<<endl;
        }
    }
    return 0;
}
