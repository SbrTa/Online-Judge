#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    char num[999];
    long int result,len,i,l;
    for(;;)
    {
        gets(num);
        len=strlen(num);
        l=len;
        result=0;
        for(i=0;i<len;i++)
        {
            result=result+((num[i]-'0')*(pow(2,l)-1));
            l--;
        }
        if(result==0)
            break;
        printf("%ld\n",result);
    }
}
