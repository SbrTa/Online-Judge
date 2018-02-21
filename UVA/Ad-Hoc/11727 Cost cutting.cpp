#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
int t,a[3],b,c,i,sum,x,y,result;
scanf("%d",&t);
for(i=1;i<=t;i++)
{
    scanf("%d%d%d",&a[0],&a[1],&a[2]);
    sort(a,a+3);
    printf("Case %d: %d\n",i,a[1]);
}
return 0;
}
