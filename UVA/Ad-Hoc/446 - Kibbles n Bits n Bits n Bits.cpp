#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#define inf 1000006
using namespace std;

int print(string s)
{
    int p=s.size(),ans=0;
    printf("0");
    if(p==1) printf("00000000");
    if(p==2) printf("0000");
    for(int i=0;i<p;i++)
    {
        if(s[i]=='0')      {printf("0000"); ans=ans+0;}
        else if(s[i]=='1') {printf("0001"); ans=ans+(1*pow(16,p-i-1));}
        else if(s[i]=='2') {printf("0010"); ans=ans+(2*pow(16,p-i-1));}
        else if(s[i]=='3') {printf("0011"); ans=ans+(3*pow(16,p-i-1));}
        else if(s[i]=='4') {printf("0100"); ans=ans+(4*pow(16,p-i-1));}
        else if(s[i]=='5') {printf("0101"); ans=ans+(5*pow(16,p-i-1));}
        else if(s[i]=='6') {printf("0110"); ans=ans+(6*pow(16,p-i-1));}
        else if(s[i]=='7') {printf("0111"); ans=ans+(7*pow(16,p-i-1));}
        else if(s[i]=='8') {printf("1000"); ans=ans+(8*pow(16,p-i-1));}
        else if(s[i]=='9') {printf("1001"); ans=ans+(9*pow(16,p-i-1));}
        else if(s[i]=='A') {printf("1010"); ans=ans+(10*pow(16,p-i-1));}
        else if(s[i]=='B') {printf("1011"); ans=ans+(11*pow(16,p-i-1));}
        else if(s[i]=='C') {printf("1100"); ans=ans+(12*pow(16,p-i-1));}
        else if(s[i]=='D') {printf("1101"); ans=ans+(13*pow(16,p-i-1));}
        else if(s[i]=='E') {printf("1110"); ans=ans+(14*pow(16,p-i-1));}
        else if(s[i]=='F') {printf("1111"); ans=ans+(15*pow(16,p-i-1));}
    }
    return ans;
}

int main()
{
    int t,a,b,i;
    string m,n;
    char c;
    scanf("%d",&t);
    while(t--)
    {
        cin>>m>>c>>n;
        //cout<<m<<" "<<c<<" "<<n<<endl;
        a=print(m);
        printf(" %c ",c);
        b=print(n);
        if(c=='-')
            printf(" = %d\n",a-b);
        else
            printf(" = %d\n",a+b);
    }
    return 0;
}
