#include<stdio.h>
#include<string.h>

int main()
{
    char num[1010];
    long i,j,len,n,sum;
    for(;;)
    {
        gets(num);
        len=strlen(num);
        if(len==1&&num[0]=='0')
            break;
        n=0;
        for(j=0;j<len;j++)
            n+=(long)(num[j]-'0');
        i=1;
        if(n%9==0)
        {
            while(n!=9)
            {
                sum=0;
                while(n!=0)
                {
                    sum=sum+n%10;
                    n=n/10;
                }
                n=sum;
                i++;
            }
            printf("%s is a multiple of 9 and has 9-degree %ld.\n",num,i);
        }
        else
            printf("%s is not a multiple of 9.\n",num);
    }
    return 0;
}
