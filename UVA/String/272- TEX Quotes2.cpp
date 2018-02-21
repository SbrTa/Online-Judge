#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main()
{
    long int len,i,l=0;
    char ch;
    while(scanf("%c",&ch)==1)
    {
        if(ch=='"')
        {
            l++;
            if(l&1)
                cout<<"``";
            else
                cout<<"''";
        }
        else
            cout<<ch;
    }
    return 0;
}

