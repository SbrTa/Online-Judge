#include<stdio.h>
int main()
{
    long long n,m,s,i,len,wide,left,right;
    scanf("%lld",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%lld", &m);
        len=100*m/20;//length=100*(2*m)/40
        wide=60*len/100;
        left=45*len/100;
        right=len-left;

        printf("Case %lld:\n",i);
        printf("-%lld %lld\n",left,wide/2);
        printf("%lld %lld\n",right,wide/2);
        printf("%lld -%lld\n",right,wide/2);
        printf("-%lld -%lld\n",left,wide/2);
    }
    return 0;

}
