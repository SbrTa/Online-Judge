#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 32000
using namespace std;

int main()
{
    int ax1,ax2,ay1,ay2,bx1,bx2,by1,by2;
    int test,cs=1,land[111][111],i,j;
    cin>>test;
    while(test--)
    {
        cin>>ax1>>ay1>>ax2>>ay2;
        cin>>bx1>>by1>>bx2>>by2;
        for(i=0;i<100;i++)
            for(j=0;j<100;j++)
                land[i][j]=0;

        int full,week=0,strong=0;

        for(i=ax1;i<ax2;i++)
            for(j=ay1;j<ay2;j++)
            {
                week++;
                land[i][j]=1;
            }

        for(i=bx1;i<bx2;i++)
            for(j=by1;j<by2;j++)
            {
                week++;
                if(land[i][j]==1)
                    strong++;
            }
        //cout<<week<<" "<<strong<<endl;
        full=100*100 - week + strong;
        week=week-strong-strong;

        printf("Night %d: %d %d %d\n",cs++,strong,week,full);
    }
    return 0;
}

