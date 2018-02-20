#include<stdio.h>

int main()

{
   long int t,i,a,b,c,e,f,g;
    scanf("%ld",&t);
    for(i=1;i<=t;i++)
    {
    scanf("%ld%ld%ld",&a,&b,&c);
        e=a*a;
        f=b*b;
        g=c*c;
        if((e==f+g) || (f==e+g) || (g==e+f))
      printf("Case %d: yes\n",i);
            else
                printf("Case %d: no\n",i);
        }


    return 0;
}
