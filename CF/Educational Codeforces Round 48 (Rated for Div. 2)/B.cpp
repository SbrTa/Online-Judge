#include<bits/stdc++.h>
#define inf 100000000
using namespace std;

int y[111];

char str[111],substr[111];
long fail[111];

void preProces(char *substr)
{
    long i=0,j=-1,len;
    len=strlen(substr);
    fail[i]=j;
    while(i<len)
    {
        while(j>=0&&substr[i]!=substr[j])
            j=fail[j];
        i++;
        j++;
        fail[i]=j;
    }
}

void KMP(char *str, char *substr)
{
    long i=0,j=0,count=0,lenStr,lenSub;
    lenStr=strlen(str);
    lenSub=strlen(substr);
    preProces(substr);
    while(i<lenStr)
    {
        while(j>=0&&str[i]!=substr[j])
            j=fail[j];
        i++;
        j++;
        if(j==lenSub)
        {
            y[j]=1;
            cout<<j<<endl;
            count++;
            j=fail[j];
        }
    }
}

int main()
{
    int n,m,q,l,r,i,ii,j,x[111];
    scanf("%d%d%d",&n,&m,&q);
    getchar();
    gets(str);
    gets(substr);
    KMP(str,substr);
    for(i=0;i<n;i++) cout<<y[i]<<" "; cout<<endl;
    x[0]=0;
    for(i=0;i<n;i++){
        x[i+1] = x[i];
        if(y[i]) x[i+1]++;
    }


    for(i=0;i<n;i++) cout<<str[i]<<" "; cout<<endl;
    for(i=0;i<n;i++) cout<<y[i]<<" "; cout<<endl;


    for(i=0;i<q;i++){
        scanf("%d%d",&l,&r);
        if(r-l+1 < m){
            printf("0\n");
            continue;
        }
        int ans = x[r-m+1] - x[l-1];
        printf("%d\n",ans);
    }


    return 0;
}

