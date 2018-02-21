#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
/*
long gcd(long a, long b)
{
    while(b>0)
        a=a%b,a^=b^=a^=b;
    return a;
}

int Gcd(long a, long b)
{
    return (b==0)?a:Gcd(b,a%b);
}
*/
int main()
{
    long a[101],t,i,j;
    string s;
    cin>>t;
    getchar();
    while(t--)
    {
        getline(cin,s);
        long n=0,l=0;
        for(i=0;i<=s.size();i++)
        {
            if(s[i]==' ' || i==s.size())
            {
                if(n>0)
                    a[l++]=n;
                n=0;
            }
            else
            {
                n=n*10+(s[i]-'0');
            }
        }
        long m=1;
        for(i=0;i<l;i++)
        {
            for(j=i+1;j<l;j++)
                if(__gcd(a[i],a[j])>m)
                    m = __gcd(a[i],a[j]);
                    //m = gcd(a[i],a[j]);
        }
        cout<<m<<endl;
    }
    return 0;
}

