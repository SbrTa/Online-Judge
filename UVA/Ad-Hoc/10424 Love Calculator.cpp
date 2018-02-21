#include<stdio.h>
#include<string.h>

int love_test(char name[])
{
    int a[50],b[50];

    int i=0,j=0;
    while(name[i]!='\0')
    {
        if(name[i]>='a'&&name[i]<='z')
        {
            a[j]=(name[i]-'a'+1);
            i++;
            j++;
        }
        else if(name[i]>='A'&&name[i]<='Z')
        {
            a[j]=(name[i]-'A'+1);
            i++;
            j++;
        }
        else
            i++;
    }
    int sum1=0,j1,sum11,r;
    for(j1=0; j1<j; j1++)
    {
        sum1=sum1+a[j1];
    }

lover:
    sum11=0;
    while(sum1!=0)
    {
        r=sum1%10;
        sum11=sum11+r;
        sum1=sum1/10;
    }
    sum1=sum11;
    if(sum1>9)
        goto lover;
    return sum1;
}

int main()
{
    char name1[50],name2[50],ch;
    int num1,num2,temp;
    float love;

    while(gets(name1))
    {
        gets(name2);
        num1=love_test(name1);
        num2=love_test(name2);
        if(num1>num2)
        {
            temp=num1;
            num1=num2;
            num2=temp;
        }
        love=(float)(100*num1)/num2;
        printf("%.2f %%\n",love);
    }
    return 0;
}
