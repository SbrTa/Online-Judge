#include<stdio.h>
int main()
{
    int T,t,e,f,c,m,n,reminder,count;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d%d%d",&e,&f,&c);
        n=e+f;
        count=0;
        while(n>=c)
        {
            m=n/c;
            reminder=n%c;
            n=m+reminder;
            count=count+m;
        }
        printf("%d\n",count);
    }
    return 0;
}
