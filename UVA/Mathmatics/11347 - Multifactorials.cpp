#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 1003
#define mx 1000000000000000000
using namespace std;

bool check[inf];
vector<int>prime;

void PRIME()
{
    int i,j;
    for(i=3;i<=inf;i+=2)
        check[i]=true;
    for(i=3;i*i<=inf;i+=2)
    {
        if(check[i]==true)
        {
            for(j=i*i;j<=inf;j+=i+i)
                check[j]=false;
        }
    }
    prime.push_back(2);
    for(i=3;i<=inf;i+=2)
        if(check[i]==true) prime.push_back(i);
    prime.push_back(inf+5);
}

int main()
{
    PRIME();
    int test,cs=1,i,j,a[175];
    char s[100];
    scanf("%d",&test);
    getchar();
    while(test--)
    {
        scanf("%s",s);
        int n=0;
        int len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]=='!') break;
            n=n*10+(s[i]-'0');
        }
        int fact=len-i,f=0;
        if(n==0)
        {
            printf("Case %d: 0\n",cs++);
            continue;
        }
        long long ans=1;
        for(i=0;i<=170;i++) a[i]=0;
        for(i=n;i>0;i-=fact)
        {
            n=i;
            for(j=0;j<170;j++)
            {
                if(n==1 || prime[j]>n) break;
                while(n%prime[j]==0)
                {
                    a[j]++;
                    n=n/prime[j];
                }
            }
        }
        for(i=0;i<=170;i++)
        {
            a[i]++;
            if(ans>mx/a[i])
            {
                f=1;
                break;
            }
            ans=ans*a[i];
        }
        printf("Case %d: ",cs++);
        if(f==1) printf("Infinity\n");
        else printf("%lld\n",ans);
    }
    return 0;
}
