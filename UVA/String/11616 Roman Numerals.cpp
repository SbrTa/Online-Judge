#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;


//NUMERAL TO ROMAN
int n_r( char s[])
{
    int n;
    n=atoi(s);
    while(n!=0)
    {
        if(n>=1000)
        {
            printf("M");
            n-=1000;
        }
        else if(n>=900)
        {
            printf("CM");
            n-=900;
        }
        else if(n>=500)
        {
            printf("D");
            n-=500;
        }
        else if(n>=400)
        {
            printf("CD");
            n-=400;
        }
        else if(n>=100)
        {
            printf("C");
            n-=100;
        }
        else if(n>=90)
        {
            printf("XC");
            n-=90;
        }
        else if(n>=50)
        {
            printf("L");
            n-=50;
        }
        else if(n>=40)
        {
            printf("XL");
            n-=40;
        }
        else if(n>=10)
        {
            printf("X");
            n-=10;
        }
        else if(n>=9)
        {
            printf("IX");
            n-=9;
        }
        else if(n>=5)
        {
            printf("V");
            n-=5;
        }
        else if(n>=4)
        {
            printf("IV");
            n-=4;
        }
        else if(n>=1)
        {
            printf("I");
            n-=1;
        }
    }
    puts("");
}


//ROMAN TO NUMERAL
int r_n( char s[])
{
    int i,c=0,x=0,xx=0,cc=0,j=0,jj=0;
    int m=0;
    int len=strlen(s);
    for(i=0; i<len; i++)
    {
        if(cc==2)
            c=0;
        if(xx==2)
            x=0;
        if(jj==2)
            j=0;
        if(c==1&&s[i]=='M')
        {
            m=m+900-100;
            c=0;
        }
        else if(c==1&&s[i]=='D')
        {
            m=m+400-100;
            c=0;
        }
        else if(x==1&&s[i]=='C')
        {
            m=m-10+90;
            x=0;
        }
        else if(x==1&&s[i]=='L')
        {
            m=m-10+40;
            x=0;
        }
        else if(j==1&&s[i]=='X')
        {
            m=m-1+9;
            j=0;
        }
        else if(j==1&&s[i]=='V')
        {
            m=m-1+4;
            j=0;
        }
        else if(s[i]=='M')
            m+=1000;
        else if(s[i]=='D')
            m+=500;
        else if(s[i]=='C')
        {
            m+=100;
            c++;
        }
        else if(s[i]=='L')
            m+=50;
        else if(s[i]=='X')
        {
            m+=10;
            x++;
        }
        else if(s[i]=='V')
            m+=5;
        else if(s[i]=='I')
        {
            m+=1;
            j++;
        }
        if(j==1)
            jj++;
        if(x==1)
            xx++;
        if(c==1)
            cc++;
    }
    printf("%d\n",m);
}


int main()
{
    char s[1000];
    while(gets(s))
    {
        if(isdigit(s[0]))
            n_r(s);
        else
            r_n(s);
    }
    return 0;
}








