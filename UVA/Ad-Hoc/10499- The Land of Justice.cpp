#include<stdio.h>
int main()
{
    long long int n;
    for(;;)
    {
        scanf("%lld",&n);
        if(n<0)
            break;
        if(n==0||n==1)
            printf("0%%\n");
        else
            printf("%lld%%\n",n*25);
    }
    return 0;
}
