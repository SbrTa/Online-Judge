#include<stdio.h>
int main()
{
    long long T,up,low,i,j,mx,c,n;
    scanf("%lld",&T);
    while(T--)
    {
        mx=-1;
        scanf("%lld%lld",&low,&up);
        for(i=low; i<=up; i++)
        {
            c=0;
            for(j=1; j*j<=i; j++)
            {
                if(i%j==0)
                    c+=2;
                if(j*j==i)
                    c--;
            }
            if(c>mx)
            {
                n=i;
                mx=c;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",low,up,n,mx);
    }
    return 0;
}
