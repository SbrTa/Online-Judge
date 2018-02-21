/*
If this code works, it was written by Subrata Roy.
If not, I don’t know who wrote it..
*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>

#define inInt(n) scanf("%d",&n)
#define inLong(n) scanf("%ld",&n)
#define inLong2(n,m) scanf("%ld%ld",&n,&m)
#define inLong3(n,m,l) scanf("%ld%ld%ld",&n,&m,&l)
#define inLL(n) scanf("%lld",&n)
#define inLL2(n,m) scanf("%lld%lld",&n,&m)
#define inFloat(n) scanf("%f",&n)
#define inDouble(n) scanf("%lf",&n)
#define inLD(n) scanf("%Lf",&n)
#define inStr(n) scanf("%s",n)
#define inChar(n) scanf("%c",&n)

#define Spc() printf(" ")
#define Line() printf("\n")
#define Case(n) printf("Case %ld:",n++)

#define INF 111
#define MX 111
#define PI acos(-1.0)
using namespace std;


long pw(long base, long p)
{
    long ans=1,i;
    for(i=1;i<=p;i++)
        ans=ans*base;
    return ans;
}


int main()
{
    //freopen("A.txt", "r", stdin);
    //freopen("A.out.txt", "w", stdout);
    long test,cs=1;
    long i,j;
    char s[100];
    while(cin>>s){
        if(s[0]=='-') break;
        long ans=0;
        long len = strlen(s);
        if(s[1]=='x'){
            for(i=2;i<len;i++){
                long b;
                if(s[i]>='0' && s[i]<='9') b=s[i]-'0';
                else if(s[i]=='A') b=10;
                else if(s[i]=='B') b=11;
                else if(s[i]=='C') b=12;
                else if(s[i]=='D') b=13;
                else if(s[i]=='E') b=14;
                else if(s[i]=='F') b=15;
                ans = ans + (b*pw(16,len-i-1));
            }
            printf("%ld",ans);
        }
        else{
            printf("0x");
            long n=0;
            for(i=0;i<len;i++)
                n = n*10 + (s[i]-'0');
            int ss[100];
            long ind=0;
            while(1){
                long d = n/16;
                long r = n%16;
                ss[ind++] = r;
                n=d;
                if(n==0) break;
            }
            //cout<<ind<<endl;
            for(i=ind-1;i>=0;i--)
            {
                if(ss[i]==15) printf("F");
                else if(ss[i]==14) printf("E");
                else if(ss[i]==13) printf("D");
                else if(ss[i]==12) printf("C");
                else if(ss[i]==11) printf("B");
                else if(ss[i]==10) printf("A");
                else printf("%ld",ss[i]);
            }
        }
        Line();
    }
    return 0;
}

