#include<stdio.h>
int main()
{
    long int t,a,b,c,i;
    scanf("%ld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%ld %ld %ld",&a,&b,&c);
        if((a+b>c)&&(b+c>a)&&(c+a>b))
            printf("OK\n");
        else
            printf("Wrong!!\n");
    }
    return 0;
}
