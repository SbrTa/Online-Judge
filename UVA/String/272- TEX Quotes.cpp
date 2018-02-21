#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main()
{
    long int len,i,l=0;
    char s[100000];
    while(gets(s))
    {
        len=strlen(s);
        for(i=0; i<len; i++)
        {
            if(s[i]=='"')
            {
                l++;
                if(l&1)
                    cout<<"``";
                else
                    cout<<"''";
            }
            else
                cout<<s[i];
        }
        puts("");
    }
    return 0;
}

