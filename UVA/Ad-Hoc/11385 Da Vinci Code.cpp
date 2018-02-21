#include<stdio.h>
#include<string.h>

int main()
{
    long long T,n,a[55],b[110],bb[110],i,j,max,found;
    char ch[110],c[110];
    a[0]=1;
    a[1]=2;
    for(i=2; i<50; i++)
        a[i]=a[i-1]+a[i-2];
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        max=-1;
        for(i=0; i<n; i++)
        {
            scanf("%lld",&b[i]);
            if(b[i]>max)
                max=b[i];
        }
        getchar();
        gets(ch);
        j=0;
        for(i=0; i<strlen(ch); i++)
        {
            if(ch[i]>='A'&&ch[i]<='Z')
            {
                c[j]=ch[i];
                j++;
            }
        }
        for(i=0; a[i]<=max; i++)
        {
            found=-1;
            for(j=0; j<n; j++)
            {
                if(a[i]==b[j])
                {
                    found=j;
                    break;
                }
            }
            if(found==-1)
                printf(" ");
            else
                printf("%c",c[found]);
        }
        puts("");
    }
    return 0;
}
