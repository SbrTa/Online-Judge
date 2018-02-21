#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define max 1005

int prime[max];
int check[inf];

void PRIME()
{
    int i,j;
    for(i=3;i<=inf;i+=2)
        check[i]=0;
    for(i=3;i*i<=inf;i+=2)
    {
        if(check[i]==0)
        {
            for(j=i*i;j<=inf;j+=i+i)
                check[j]=1;
        }
    }
    v[0]=2;
    j=1;
    for(i=3;i<=inf;i+=2)
        if(check[i]==0) v[j++]=i;
}
int main()
{
    long int i,j,N,count,start,end,c,size;
    while(scanf("%ld %ld",&N,&c)==2)
    {
        sieve();
        count=0;
        for(i=1;i<=N;i++)
        {
            if(prime[i]==1)
            {
                prime2[count]=i;
                count++;
            }
        }
        size=(c*2)-(count%2);
        start=size>count?0:(count-size)/2;
        end=size>count?count:start+size;
        printf("%ld %ld:",N,c);
        for(i=start;i<end;i++)
            printf(" %ld",prime2[i]);
        printf("\n\n");
    }
return 0;
}
