#include<stdio.h>
#include<string.h>

int divider(char year[],int len,int num)
{
    int result=0,i,a;
    for(i=0;i<len;i++)
        result=((year[i]-'0')+result*10)%num;
    if(result==0)    return 0;
    else    return 1;
}

int main()
{
    int count,len,leap,p=0;
    char year[1000000];
    while(scanf("%s",year)!=EOF)
    {
    if(p==1)
        printf("\n");
    p=1;
    len=strlen(year);
    count=0;
    leap=0;
    if((divider(year,len,4)==0 && divider(year,len,100)!=0)
                                ||(divider(year,len,400)==0))
    {
        printf("This is leap year.\n");
        leap=1;
        count=1;
    }
    if((leap==1 || leap==0) && divider(year,len,15)==0)
    {
        printf("This is huluculu festival year.\n");
        count=1;
    }
    if(leap==1 && divider(year,len,55)==0)
        printf("This is bulukulu festival year.\n");
    if(count==0)
        printf("This is an ordinary year.\n");
    }
return 0;
}
