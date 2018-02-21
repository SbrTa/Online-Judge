#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define inf 1000000+10
using namespace std;

vector<long>v;
bool check[inf];
long l=0;

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
        if(check[i]==true)  v.push_back(i);
}


int main()
{
    PRIME();
    long n,i;
    while(cin>>n && n!=0)
    {
        bool flag=false;
        printf("%ld:\n",n);
        for(i=0;v[i]+v[i]<=n;i++)
        {
            long m=n-v[i];
            if((m%2==1 && check[m]==true && m>1) || m==2)
            {
                flag=true;
                if(m<v[i])  printf("%ld+%ld\n",m,v[i]);
                else    printf("%ld+%ld\n",v[i],m);
                break;
            }
        }
        if(flag==false)
            printf("NO WAY!\n");
    }
    return 0;
}
