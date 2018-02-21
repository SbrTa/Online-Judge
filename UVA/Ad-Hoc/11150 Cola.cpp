#include<stdio.h>
int main()
{
int n,cola,r,a;

while(scanf("%d",&n)==1)
{
    if(n>=1&&n<=200)
    {
        cola=n;
        saf:    a=n/3;
                r=n%3;
                cola=cola+a;
                n=r+a;
        if(n>=3)
            goto saf;
        if(n==2)
        cola++;
        printf("%d\n",cola);
    }
}
return 0;
}
