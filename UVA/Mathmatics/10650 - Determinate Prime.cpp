#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define inf 0x7f7f
using namespace std;

bool check[inf];
vector<int>v;

void PRIME()
{
    int i,j;
    for(i=3;i<=inf;i+=2)
        check[i]=true;
    for(i=3;i*i<=inf;i+=2)
    {
        if(check[i]==true)
        {
            for(j=i*i;j<=inf;j+=i+i)
                check[j]=false;
        }
    }
    v.push_back(2);
    for(i=3;i<=inf;i+=2)
        if(check[i]==true)  v.push_back(i);
}

int main()
{
    PRIME();
    int a,b,i,j,k;
    while(cin>>a>>b)
    {
        if(a==0 && b==0)
            break;
        if(a>b)    swap(a,b);
        int low = lower_bound(v.begin(),v.end(),a) - v.begin();
        int up = lower_bound(v.begin(),v.end(),b) - v.begin();
        int dif;
        for(i=low;i<=up;i++)
        {
            dif = v[i+1]-v[i];
            if(dif==(v[i+2]-v[i+1]))
            {
                int l = i+2;
                while( (v[l+1]-v[l])==dif )
                    l++;
                if(v[l]>b)
                    break;
                if( (v[i]-v[i-1]==dif && i>0) )
                {
                    i=l;
                    continue;
                }
                cout<<v[i];
                for(j=i+1;j<=l;j++)
                    cout<<" "<<v[j];
                cout<<endl;
            }
        }
    }
    return 0;
}
