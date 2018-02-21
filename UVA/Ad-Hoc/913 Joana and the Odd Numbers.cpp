#include<stdio.h>
int main()
{
    long long int n,i,sum,odd;
    while(scanf("%lld",&n)==1)
    {
        odd=(n/2+1)*(n/2+1)-3;
        odd*=2;
        sum=(odd+1)+(odd+3)+(odd+5);
        printf("%lld\n",sum);
    }
    return 0;
}
