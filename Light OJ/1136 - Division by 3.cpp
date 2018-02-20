#include<bits/stdc++.h>
using namespace std;

//#define cal(n)  ((n/3*2)+(n%3==2))

int cal(int n)
{
    int m=n/3*2;
    if(n%3==2) m++;
    return m;
}

int main()
{
    int test,cs=1,a,b;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&a,&b);
        a--;
        printf("Case %d: %d\n",cs++,cal(b)-cal(a));
    }
    return 0;
}
