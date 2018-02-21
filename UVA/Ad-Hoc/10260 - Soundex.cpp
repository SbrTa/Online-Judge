#include<bits/stdc++.h>
using namespace std;

int main()
{
    char str[7][10]={"BFPV","CGJKQSXZ","DT","L","MN","R"},s[22];
    while(cin>>s)
    {
        int i,j,k,flag,a[7]={0,0,0,0,0,0},n=0;
        for(i=0;i<strlen(s);i++)
        {
            for(j=0;j<6;j++)
            {
                k=0,flag=-1;
                while(str[j][k]!=NULL)
                {
                    if(s[i]==str[j][k])
                    {
                        flag=j;
                        break;
                    }
                    k++;
                }
                if(flag!=-1)
                    break;
            }
            for(j=0;j<6;j++)
            {
                if(flag!=-1&&j==flag&&a[flag]==0)
                {
                    //cout<<s[i]<<endl;
                    cout<<flag+1;
                }
                if(j!=flag)
                    a[j]=0;
            }
            a[flag]=1;
        }
        cout<<endl;
    }
    return 0;
}
