#include<stdio.h>
int main()
{
    long long int a,b,c,e,f,x,y,z;
    for(;;)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        z=((a>b)?((a>c)?a:c):((b>c)?b:c));
        x=((a<b)?((a<c)?a:c):((b<c)?b:c));
        y=a+b+c-x-z;
        if(a==0&&b==0&&c==0)
            break;
        e=(x*x)+(y*y);
        f=z*z;
        if(e==f)
            printf("right\n");
        else
            printf("wrong\n");
    }
    return 0;
}
