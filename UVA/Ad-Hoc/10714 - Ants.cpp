#include<stdio.h>
#define inf 1000000+1000000

long min(long a, long b)
{
    return (a<b)?a:b;
}

long max(long a, long b)
{
    return (a>b)?a:b;
}

int main()
{
    long n,i,m,T;
    scanf("%ld",&T);
    while(T--){
        scanf("%ld %ld",&m,&n);
        long Min=-1, Max=-1;
        while(n--){
            long a,b;
            scanf("%ld",&a);
            b = m-a;
            if(min(a,b)>Min) Min=min(a,b);
            if(max(a,b)>Max) Max=max(a,b);
        }
        printf("%ld %ld\n",Min,Max);
    }
    return 0;
}
