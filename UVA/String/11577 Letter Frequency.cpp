#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[26],b[26],T,i,j,len;
    char s[210];
    cin>>T;
    getchar();
    while(T--)
    {
        gets(s);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if (isalpha(s[i]))
            {
                s[i]=tolower(s[i]);
                a[s[i]-'a']++;
                b[s[i]-'a']++;
            }
        }
        sort(a,a+26);
        for(i=0;i<26;i++)
        {
            if(b[i]==a[25])
                printf("%c",97+i);
        }
        puts("");
    }
    return 0;
}
