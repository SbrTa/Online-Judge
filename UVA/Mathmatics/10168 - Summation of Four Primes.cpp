#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define inf 10000001
using namespace std;

vector<long>v;
bool check[inf];
void PRIME()
{
    long i,j;
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
    {
        if(check[i]==true)
            v.push_back(i);
    }
}

int main()
{
    PRIME();
    long n,i;
    while(cin>>n)
    {
        if(n<8)
        {
            cout<<"Impossible."<<endl;
            continue;
        }
        if(n%2==0)
        {
            cout<<"2 2 ";
            n=n-4;
        }
        else
        {
            cout<<"2 3 ";
            n=n-5;
        }

        for(i=0;i<v.size();i++)
        {
            long temp = n-v[i];
            if((temp%2 && temp>0 && check[temp]==true) ||temp==2)
            {
                cout<<v[i]<<" "<<temp<<endl;
                break;
            }
        }
    }
    return 0;
}
