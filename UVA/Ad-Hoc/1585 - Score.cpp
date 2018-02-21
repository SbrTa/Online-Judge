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
    long i,t;
    scanf("%ld",&t);
    while(t--)
    {
        string s;
        cin>>s;
        long n=0,l=0,len = s.size();
        for(i=0;i<len;i++)
        {
            if(s[i]=='X') l=0;
            else
            {
                l++;
                n+=l;
            }
        }
        printf("%ld\n",n);
    }
    return 0;
}
