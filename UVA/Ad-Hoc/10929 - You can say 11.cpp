#include<stdio.h>
#include<string.h>

int test(char num2[],int len2)
{
    long long int j,result=0;
    for(j=0;j<len2;j++)
        result=((result*10)+(num2[j]-'0'))%11;
    if(result==0)
        return 0;
    else
        return 1;
}

int main()
{
    char num[1000];
    long long int i,len;//count;
    for(;;)
    {
        //count=0;
        gets(num);
        len=strlen(num);
        if(len==1&&num[0]=='0')
            break;
        if(test(num,len)==0)
            printf("%s is a multiple of 11.\n",num);
        else
            printf("%s is not a multiple of 11.\n",num);
    }
    return 0;
}
