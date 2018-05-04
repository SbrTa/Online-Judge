#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,mx=-1,len;
    char s[10001],st[10001];

    while(cin>>s)
    {
        if(strcmp(s,"E-N-D")==0)
            break;
        len=0;
        for(i=0;i<strlen(s);i++)
        {
            if(isalpha(s[i]) || s[i]=='-')
                len++;
        }
        if(len>mx)
        {
            mx=len;
            strcpy(st,s);
        }
    }
    for(i=0;i<strlen(st);i++)
    {
        if(isalpha(st[i]) || st[i]=='-')
            printf("%c",tolower(st[i]));
    }
    cout<<endl;
    return 0;
}
