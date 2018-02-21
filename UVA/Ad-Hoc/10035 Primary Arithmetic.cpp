#include<stdio.h>
int main()
{
   long long int a,b,sum,r1,r2,car,carry;
    for(;;)
    {
        scanf("%lld %lld",&a,&b);
        if(a==0&&b==0)  break;
        else
        {
            car=0;
            carry=0;
            if(a>=b)
            {
                while(a!=0)
                {
                    r1=a%10;
                    r2=b%10;
                    if(a==0)    r1=0;
                    if(b==0)    r2==0;
                    sum=r1+r2+car;
                    if(sum>9)   {carry++; car=1;}
                    a=a/10;
                    b=b/10;
                }
            }
            else
            {
                while(b!=0)
                {
                    r1=a%10;
                    r2=b%10;
                    if(a==0)    r1=0;
                    if(b==0)    r2==0;
                    sum=r1+r2+car;
                    if(sum>9)   {carry++;   car=1;}
                a=a/10;
                b=b/10;
                }
            }

            if(carry==1)
                printf("%lld carry operation.\n",carry);
            else if(carry>1)
                printf("%lld carry operations.\n",carry);
            else
                printf("No carry operation.\n");
        }
    }

    return 0;
}
