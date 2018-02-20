#include<cstdio>

int main()
{
    int test,cs=1;
    long n,m,r,cnt,temp;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%ld %ld",&n,&m);
        cnt=0;
        temp=0;
        while(temp<n)
        {
            cnt++;
            temp=temp*10+m;
            r=temp%n;
            if(r==0)
                break;
            temp=r;
        }
        printf("Case %d: %ld\n",cs++,cnt);
    }
    return 0;
}
