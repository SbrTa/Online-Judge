#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long fact[22],i,l,flag,m,store[22],T,t;
    fact[0]=1;
    for(i=1; i<=20; i++)
        fact[i]=fact[i-1]*i;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>m;
        printf("Case %lld: ",t);
        for(i=0; i<=20; i++)
        {
            if(fact[i]>m)
                break;
        }
        i--;
        flag=0;
        l=0;
        while(1)
        {
            if(m==0)
            {
                flag=1;
                break;
            }
            else if(i<0)
                break;
            else
            {
                if(fact[i]<=m)
                {
                    store[l++]=i;
                    m=m-fact[i];
                }
            }
            i--;
        }
        l--;
        if(flag==1)
        {
            printf("%lld!",store[l]);
            for(i=l-1;i>=0;i--)
                printf("+%lld!",store[i]);
            puts("");
        }
        else
            cout<<"impossible\n";
    }
    return 0;
}
