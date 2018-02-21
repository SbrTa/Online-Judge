#include<string>
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    char c;
    string a;
    long long b;
    while(cin>>a)
    {
        while(1)
        {
            scanf("%c",&c);
            if(c=='/' || c=='%')
                break;
        }
        scanf("%lld",&b);
        //cout<<a<<c<<b<<endl;
        long long sz=a.size(),i,z=0,rem=0,n=0;
        if(c=='%')
        {
            for(i=0;i<sz;i++)
                rem=((rem*10) + (a[i]-'0')) % b;
            printf("%lld\n",rem);
        }
        else if(c=='/')
        {
            for(i=0;i<sz;i++)
            {
                n=((rem*10)+(a[i]-'0'))/b;
                rem=((rem*10) + (a[i]-'0')) % b;
                if(n>=1) z=1;
                if(z==1) printf("%lld",n);
            }
            if(z==0) printf("0");
            printf("\n");
        }
    }
    return 0;
}

