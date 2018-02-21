#include<stdio.h>

int f91(long int n)
{
    if(n<=100)
        return(f91(f91(n+11)));
    else
        return(n-10);
}

int main()
{
    long int num,num2;
    for(;;)
    {
        scanf("%ld",&num);
        if(num==0)  break;
        num2=f91(num);
        printf("f91(%ld) = %ld\n",num,num2);
    }
    return 0;
}
