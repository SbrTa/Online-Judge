#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#define LL long long
#define inf 32000
using namespace std;

int coin[6+1] = {1,2,4,10,20,40};
int have[7];
int change[101];

void CoinChange()
{
    int i,j;
    for(i=0;i<=100;i++) change[i]=inf;
    change[0]=0;
    for(i=0;i<6;i++)
    {
        for(j=coin[i];j<=100;j++)
            change[j] = min( change[j], change[j - coin[i]]+1 );
    }
}

int f(int target, int index)
{
    if(target<-100 || target>100) return inf;
    else if(target<=0&&index<0) return change[-target];
    else if(index<0) return inf;
    else if(!have[index]) return f(target,index-1);
    else{
        have[index]--;
        int a = f(target-coin[index],index);
        have[index]++;
        int b = f(target,index-1);
        return min(a+1,b);
    }
}


int main()
{
    CoinChange();
    int i,j;
    while(1)
    {
        int zero=0;
        for(i=0;i<6;i++)
        {
            scanf("%d",&have[i]);
            if(have[i]==0) zero++;
        }
        if(zero==6) break;

        int target,a,b;
        scanf("%d.%d",&a,&b);
        target = (a*100+b)/5;

        printf("%3d\n",f(target,5));
    }
    return 0;
}
