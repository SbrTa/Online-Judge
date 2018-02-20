#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test,cs=1,n;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        printf("Case %lld: ",cs++);
        double m = (double)sqrt(n);
        long long lm=floor(m);
        if(m==lm&&lm%2==0)
            printf("%lld 1\n",lm);
        else if(m==lm&&lm%2==1)
            printf("1 %lld\n",lm);
        else if(lm%2==0)
        {
            double x=m-lm;
            if(x<0.500000)
                printf("%lld %lld\n",lm+1,n-(lm*lm));
            else
                printf("%lld %lld\n",(lm+1)*(lm+1)-n+1,lm+1);
        }
        else if(lm%2==1)
        {
            double x=m-lm;
            if(x>=0.500000)
                printf("%lld %lld\n",lm+1,(lm+1)*(lm+1)-n+1);
            else
                printf("%lld %lld\n",n-(lm*lm),lm+1);
        }
    }
    return 0;
}
