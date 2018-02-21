#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,x,y,x1,y1;
    while(scanf("%d",&n) && n)
    {
        scanf("%d%d",&x,&y);
        while(n--)
        {
            scanf("%d%d",&x1,&y1);
            if(x1==x || y1==y)
                printf("divisa\n");
            else if(x1>x && y1>y)
                printf("NE\n");
            else if(x1<x && y1>y)
                printf("NO\n");
            else if(x1<x && y1<y)
                printf("SO\n");
            else if(x1>x && y1<y)
                printf("SE\n");
        }
    }
    return 0;
}

