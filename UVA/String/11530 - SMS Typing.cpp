#include<stdio.h>
#include<string.h>
int main()
{
    int t,sms_int[999],sum,i,j,k,reminder,length;;
    char sms[999];
    scanf("%d",&t);
    getchar();
    for(i=1;i<=t;i++)
    {
        sum=0;
        gets(sms);
        length=strlen(sms);
        for(j=0;j<length;j++)
            sms_int[j]=sms[j];
        for(k=0;k<length;k++)
        {
            if(sms_int[k]==122)     sum=sum+4;
            else if(sms_int[k]==32)     sum=sum+1;
            else if(sms_int[k]==115)    sum=sum+4;
            else
            {
                if(sms_int[k]>115)
                {
                    reminder=(sms_int[k]-1)%3;
                    if(reminder==1)     sum=sum+1;
                    else if(reminder==2)    sum=sum+2;
                    else    sum=sum+3;
                }
                else
                {
                    reminder=sms_int[k]%3;
                    if(reminder==1)     sum=sum+1;
                    else if(reminder==2)    sum=sum+2;
                    else    sum=sum+3;
                }
            }
        }
        printf("Case #%d: %d\n",i,sum);
    }
return 0;
}
