#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
int main()
{
    string a[44],b[44],c;
    int n,m,i,j;
    cin>>n;
    getchar();
    i=1;
    while(i<=n)
    {
        getline(cin,a[i]);
        getline(cin,b[i]);
        i++;
    }
    cin>>m;
    getchar();
    i=1;
    while(i<=m)
    {
        getline(cin,c);
        for(j=1;j<=n;j++)
        {
            if(c==a[j])
            {
                cout<<b[j]<<endl;
                break;
            }
        }
        i++;
    }
    return 0;
}
