#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#define inf -99999999
using namespace std;

int main()
{
    long b,s,i,cs=1,a;
    while(~scanf("%ld%ld",&b,&s))
    {
        if(b==0 && s==0) break;
        long m=100;
        for(i=0;i<b;i++)
        {
            scanf("%ld",&a);
            if(a<m) m=a;
        }
        for(i=0;i<s;i++)
            scanf("%ld",&a);
        if(b<=s) printf("Case %ld: 0\n",cs++);
        else printf("Case %ld: %ld %ld\n",cs++,b-s,m);
    }
    return 0;
}
