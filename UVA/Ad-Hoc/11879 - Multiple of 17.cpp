#include<stdio.h>
#include<string.h>

int test (char num2[], int len2)
{
    long long int count=0,result=0,j;
    for(j=0;j<len2;j++)
        result=((result*10)+(num2[j]-'0'))%17;
    if(result==0)
        return 0;
    else
        return 1;
}


int main()
{
    char num[1000];
    long long int len,i;

    for(;;)
    {
        gets(num);
        len=strlen(num);
        if(len==1&&num[0]=='0')
            break;
        if(test(num,len)==0)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
