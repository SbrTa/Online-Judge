#include<bits/stdc++.h>
using namespace std;

long gcd(long a, long b)
{
    while(b)
    {
        a=a%b;
        b^=a^=b^=a;
    }
    return a;
}

int main()
{
    long T,t,a[101],n,i,j,p,neg;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>n;
        p=0,neg=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<0)
            {
                a[i]=-a[i];
                neg++;
            }
            p+=a[i];
        }
        long pos=n-neg,s=gcd(p,pos);
        printf("Case %ld: ",t);
        if(neg==n)
            cout<<"inf\n";
        else
            printf("%ld/%ld\n",p/s,pos/s);
    }
    return 0;
}
