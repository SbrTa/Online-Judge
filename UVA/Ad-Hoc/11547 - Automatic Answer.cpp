#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    long int n=0,t,sum=0,i,result;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        sum=abs((((((n*567)/9)+7492)*235)/47)-498);
        result=(sum/10)%10;
        printf("%d\n",result);
    }
    return 0;
}
