#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int test,cs=1,n,i;
    char s[1000];
    cin>>test;
    getchar();
    getchar();
    while(test--)
    {
        if(cs>1)
            cout<<endl;
        cout<<"Case #"<<cs++<<":\n";
        while(gets(s))
        {
            if(s[0]=='\0')
                break;
            int p=1,l=0,flag=0;
            for(i=0;i<strlen(s);i++)
            {
                if(s[i]==' ')
                {
                    l=0;
                    flag=0;
                }
                else
                {
                    l++;
                    if(l==p && flag==0)
                    {
                        p++;
                        flag=1;
                        cout<<s[i];
                    }

                }
            }
            cout<<endl;
        }
    }
    return 0;
}
