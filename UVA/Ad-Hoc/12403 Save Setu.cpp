#include<stdio.h>
#include<string.h>
int main()
{
    int T,t,n,total=0,don,rep;
    char a[10];
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%s",a);
        don=strcmp(a,"donate");
        rep=strcmp(a,"report");
        if(don==0)
        {
            scanf("%d",&n);
            total=total+n;
        }
        else if(rep==0)
            printf("%d\n",total);

    }
    return 0;
}
