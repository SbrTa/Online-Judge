#include<stdio.h>
int main()
{
    long long int bin[999],dec,reminder,count,i,j;
    for(;;)
    {
        scanf("%lld",&dec);
        if(dec==0)
            break;
        i=0;
        count=0;
        while(dec!=0)
        {
            reminder=dec%2;
            if(reminder==1)
                count++;
            bin[i]=reminder;
            dec=dec/2;
            i++;
        }
        printf("The parity of ");
        for(j=i-1;j>=0;j--)
            printf("%lld",bin[j]);
        printf(" is %lld (mod 2).\n",count);
    }
    return 0;
}
