/*In this problem 1 is also a prime number*/
#include<stdio.h>
#include<string.h>

long int cheak_prime(int number)
{
    if(number==0)
        return 1;
    if(number==2||number==1)
        return 0;
    if(number%2==0)
        return 1;
    for(int i=3;i*i<=number;i+=2)
    {
      if(number%i==0&&i!=number)
        return 1;
    }
    return 0;
}

int main()
{
    int len,num[20],i,sum;
    char word[20];
    while(gets(word))
    {
        sum=0;
        len=strlen(word);
        for(i=0;i<len;i++)
        {
            num[i]=word[i];
            if(num[i]>=65&&num[i]<=90)
                sum=sum+num[i]-65+27;
            else if(num[i]>=97&&num[i]<=122)
                sum=sum+num[i]-97+1;
        }
        if(cheak_prime(sum)==0)
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }
    return 0;
}
