#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 32000 //sqrt(1000000000)
using namespace std;

queue<string>Ja,Sam,Sha,Sid,Tan;

void Reset()
{
    while(!Ja.empty()) Ja.pop();
    while(!Sam.empty()) Sam.pop();
    while(!Sha.empty()) Sha.pop();
    while(!Sid.empty()) Sid.pop();
    while(!Tan.empty()) Tan.pop();
}

int main()
{
    int test,cs=1,m,n,k,i;
    string start,s;
    cin>>test;
    while(test--)
    {
        Reset();
        cin>>m>>n>>start;
        cin>>k;
        for(i=0;i<k;i++)
        {
            cin>>s;
            Ja.push(s);
        }

        cin>>k;
        for(i=0;i<k;i++)
        {
            cin>>s;
            Sam.push(s);
        }

        cin>>k;
        for(i=0;i<k;i++)
        {
            cin>>s;
            Sha.push(s);
        }

        cin>>k;
        for(i=0;i<k;i++)
        {
            cin>>s;
            Sid.push(s);
        }

        cin>>k;
        for(i=0;i<k;i++)
        {
            cin>>s;
            Tan.push(s);
        }
        /*input complete*/

        int JA=0,SAM=0,SHA=0,SID=0,TAN=0;

        for(i=0;;)
        {
            if(start=="Ja")
            {
                if(i+m<=n)
                    JA+=m;
                else
                    JA+=(n-i);
                i+=m;
                start=Ja.front();
                Ja.pop();
                Ja.push(start);
            }
            else if(start=="Sam")
            {
                if(i+m<=n)
                    SAM+=m;
                else
                    SAM+=(n-i);
                i+=m;
                start=Sam.front();
                Sam.pop();
                Sam.push(start);
            }
            else if(start=="Sha")
            {
                if(i+m<=n)
                    SHA+=m;
                else
                    SHA+=(n-i);
                i+=m;
                start=Sha.front();
                Sha.pop();
                Sha.push(start);
            }
            else if(start=="Sid")
            {
                if(i+m<=n)
                    SID+=m;
                else
                    SID+=(n-i);
                i+=m;
                start=Sid.front();
                Sid.pop();
                Sid.push(start);
            }
            else if(start=="Tan")
            {
                if(i+m<=n)
                    TAN+=m;
                else
                    TAN+=(n-i);
                i+=m;
                start=Tan.front();
                Tan.pop();
                Tan.push(start);
            }
            i+=2;
            if(i>=n) break;
        }
        printf("Case %d:\n",cs++);
        printf("Ja %d\n",JA);
        printf("Sam %d\n",SAM);
        printf("Sha %d\n",SHA);
        printf("Sid %d\n",SID);
        printf("Tan %d\n",TAN);
    }
    return 0;
}
