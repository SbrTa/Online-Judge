#include<stdio.h>
#include<math.h>
int main()
{
    long long int n,a,b,c,i,big,small,mid;
    float x;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        if((a+b>c)&&(b+c>a)&&(c+a>b))
        {
            big=(float)(a>b)?((a>c)?a:c):((b>c)?b:c);
            small=(a<b)?((a<c)?a:c):((b<c)?b:c);
            mid=a+b+c-big-small;
            x=(float)sqrt((small*small)+(mid*mid));
            if(big==x)
                printf("Case %d: yes\n",i);
            else
                printf("Case %d: no\n",i);
        }
        else
            printf("Case %d: no\n");
    }
return 0;
}
