#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int test,p;
long i,n,b,s;
double f[1000010];
int main()
{
    f[0]=0;
    scanf("%d",&test);
    for(i=1; i<=1000000; i++)
        f[i]=log((i))+f[i-1];
    for(p=1; p<=test; p++)
    {
        scanf("%ld%ld",&n,&b);
        s=(long)(f[n]/log(b))+1;
        printf("Case %d: %ld\n",p,s);
    }
    return 0;
}
