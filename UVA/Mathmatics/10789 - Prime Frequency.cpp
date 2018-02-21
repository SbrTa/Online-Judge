#include<bits/stdc++.h>
#define maxx 2005
using namespace std;

int seive[maxx];
int seiv()
{
    int i,j;
    for(i=3; i<=maxx; i+=2)
        seive[i]=0;
    for(i=3; i*i<=maxx; i+=2)
    {
        if(seive[i]==0)
        {
            for(j=i*i; j<=maxx; j+=i+i)
                seive[j]=1;
        }
    }
}

int main()
{
    seiv();
    long int n[200],test,cs,i,flag,len;
    char str[2002];
    cin>>test;
    for(cs=1; cs<=test; cs++)
    {
        flag=0;
        for(i=0; i<=130; i++)
            n[i]=0;
        cin>>str;
        len=strlen(str);
        for(i=0; i<len; i++)
            n[str[i]]++;
        printf("Case %ld: ",cs);
        for(i=48; i<=122; i++)
        {
            if(n[i]>0 &&(n[i]==2||(n[i]>1&&n[i]%2==1&&seive[n[i]]==0)))
            {
                printf("%c",i);
                flag=1;
            }
        }
        if(flag==0)
            printf("empty");
        cout<<endl;
    }
    return 0;
}
