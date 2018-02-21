#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[10000];
    float m;
    int t,n,len,i,j,k;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(s);
        len=strlen(s);
        m=sqrt(len);
        n=(int)m;
        if(n!=m)
            printf("INVALID");
        else
        {
            k=0;
            for(i=0;k<n;i+=n)
            {
                if(i>=len)
                {
                    k++;
                    i=k;
                }
                if(k==n)
                    continue;
                printf("%c",s[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
