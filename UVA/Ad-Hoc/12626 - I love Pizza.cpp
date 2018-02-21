#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main()
{
    int t,i,len;
    char s[1000];
    cin>>t;
    getchar();
    while(t--)
    {
        int a[6]={0};
        gets(s);
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]=='A')
                a[0]++;
            else if(s[i]=='G')
                a[1]++;
            else if(s[i]=='I')
                a[2]++;
            else if(s[i]=='M')
                a[3]++;
            else if(s[i]=='R')
                a[4]++;
            else if(s[i]=='T')
                a[5]++;
        }
        a[0]=a[0]/3;
        a[4]=a[4]/2;
        sort(a,a+6);
        cout<<a[0]<<endl;
    }
    return 0;
}
