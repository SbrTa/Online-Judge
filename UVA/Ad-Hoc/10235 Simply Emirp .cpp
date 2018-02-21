#include<stdio.h>

int check_prime( long int n)
{
    int i;
    if(n==0)
        return false;
    if(n==1||n==2)
        return true;
    if(n%2==0)
        return false;
    for(i=3;i*i<=n;i+=2)
    {
        if(n%i==0&&i!=n)
            return false;
    }
    return true;
}
int main()
{
    long int num,r,m,n;
    while(scanf("%ld",&num)==1)
    {
        m=0;
        n=num;
        if(check_prime(num)==true)
        {
            while(num!=0)
            {
                r=num%10;
                m=m*10+r;
                num=num/10;
            }
            if(m!=n&&check_prime(m)==true)
                printf("%ld is emirp.\n",n);
            else
                printf("%ld is prime.\n",n);
        }
        else
            printf("%ld is not prime.\n",n);
    }
    return 0;
}
