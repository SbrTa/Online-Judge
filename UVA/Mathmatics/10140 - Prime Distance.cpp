#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#define inf 46340+100 //sqrt(2147483647)
#define MAX_DIF 1000006
using namespace std;

bool check[inf];
bool chk[MAX_DIF];
vector<long>v;

void PRIME()
{
    long i,j;
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
    v.push_back(2);
    for(i=3;i<=inf;i+=2)
        if(check[i]==true) v.push_back(i);
    //cout<<v[v.size()-1]<<endl;
}

int main()
{
    PRIME();
    long long low,up;
    while(scanf("%lld%lld",&low,&up)==2)
    {
        long long i,j,ii,x;
        for(i=0;i<=up-low;i++) chk[i]=true;

        for(i=0;;i++)
        {
            ii= (long long)v[i];
            if(ii*ii>up) break;
            //if(ii==11) break;
            //cout<<ii<<endl;
            if(low%ii==0)
                j=max(low,ii*2);
            else
            {
                x=low/ii;
                x=(x+1)*ii;
                j=max(x,ii*2);
            }
            //cout<<j<<endl;
            for(;j<=up;j+=ii)
                chk[j-low]=false;
            //cout<<j<<endl;
        }
        vector<long>prime;

        for(i=0;i<=up-low;i++)
            if(chk[i]==true)
            {
                if(i+low<=1) continue;
                prime.push_back(i+low);
            }
        //cout<<prime.size()<<endl;
        if(prime.size()<=1)
        {
            printf("There are no adjacent primes.\n");
            continue;
        }

        long Min=MAX_DIF,Max=-1,a,b,aa,bb,dif;
        for(i=1;i<prime.size();i++)
        {
            dif=prime[i]-prime[i-1];
            if(dif<Min)
            {
                Min=dif;
                a=prime[i-1];
                b=prime[i];
            }
            if(dif>Max)
            {
                Max=dif;
                aa=prime[i-1];
                bb=prime[i];
            }
        }
        printf("%ld,%ld are closest, %ld,%ld are most distant.\n",a,b,aa,bb);
    }
    return 0;
}
