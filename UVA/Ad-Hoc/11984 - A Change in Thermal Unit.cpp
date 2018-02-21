#include<stdio.h>
int main()
{
int t,i;
float c,f;
scanf("%d",&t);
for(i=1;i<=t;i++)
{
    scanf("%f%f",&c,&f);
    f=f+((1.8*c)+32);
    c=(f-32)/1.8;
    printf("Case %d: %.2f\n",i,c);
}
return 0;
}
