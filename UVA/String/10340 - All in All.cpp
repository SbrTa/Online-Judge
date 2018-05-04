#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#define inf 1000006
using namespace std;

int main()
{
    string str,s;
    while(cin>>s>>str)
    {
        int i,l=0,f=0;
        int strlen=str.size();
        int slen=s.size();
        for(i=0;i<strlen;i++)
        {
            if(str[i]==s[l])
            {
                l++;
                if(l==slen) break;
            }
        }
        if(l==slen) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

