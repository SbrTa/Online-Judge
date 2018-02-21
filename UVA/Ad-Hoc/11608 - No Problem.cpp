#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 32000 //sqrt(1000000000)
using namespace std;

int main()
{
    int have[14],need[14],cs=1,n,i,j;
    while(cin>>n)
    {
        if(n<0)break;
        have[0]=n;
        for(i=1;i<=12;i++)
            cin>>have[i];
        for(j=0;j<12;j++)
            cin>>need[j];

        cout<<"Case "<<cs++<<":\n";
        for(i=0;i<12;i++)
        {
            if(have[i]>=need[i])
            {
                have[i+1]=have[i+1]+have[i]-need[i];
                cout<<"No problem! :D\n";
            }
            else
            {
                have[i+1]+=have[i];
                cout<<"No problem. :(\n";
            }
        }
    }
    return 0;
}

