#include<stdio.h>
#include<math.h>
int main()
{
long int a,b,count,i,j;
for(;;)
{
    scanf("%ld %ld",&a,&b);
    if(a==0&&b==0)
        break;

     count=(int)sqrt(b)-(int)sqrt(a-1);

    printf("%ld\n",count);
}
return 0;
}
