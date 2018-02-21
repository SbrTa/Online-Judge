#include<bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////
///////////////////////////////////////////////

char s[100005];
char sub[1003];
int Rank[32][100005];
struct info{
    int a,b,indx;
}sa[100005];

bool srt(info x, info y)
{
    if(x.a==y.a) return x.b<y.b;
    return x.a<y.a;
}

void SuffixArray()
{
    int i,j,step;
    int n = strlen(s);
    for(i=0;i<n;i++)
        Rank[0][i] = s[i];
    for(step=1; ;step++){
        int add = 1<<(step-1);
        if(add>n) break;
        for(i=0;i<n;i++){
            sa[i].a = Rank[step-1][i];
            if(i+add>=n) sa[i].b = -1;
            else sa[i].b = Rank[step-1][i+add];
            sa[i].indx = i;
        }
        sort(sa, sa+n, srt);
        int p=0;
        Rank[step][sa[0].indx] = 0;
        for(i=1;i<n;i++){
            if(sa[i].a==sa[i-1].a && sa[i].b==sa[i-1].b);
            else p++;
            Rank[step][sa[i].indx] = p;
        }
    }
}

int Find()
{
    int m = strlen(sub);
    char ss[1003];
    int hi=strlen(s),lo=0,mid;
    while(lo<hi){
        mid = (hi+lo)/2;
        memset(ss,'\0',sizeof(ss));
        strncpy(ss,s+sa[mid].indx,m);
        int ok = strcmp(ss,sub);
        cout<<sub<<" "<<ss<<" "<<ok<<endl;
        if(!ok) return 1;
        if(ok==1) hi=mid;
        else lo=mid+1;
    }
    return 0;
}


int main()
{
    int test;
    int i,j;
    scanf("%d",&test);
    getchar();
    while(test--){
        gets(s);
        SuffixArray();
        int q;
        scanf("%d",&q);
        getchar();
        while(q--){
            gets(sub);
            if(Find()) printf("y\n");
            else printf("n\n");
        }
    }
    return 0;
}

/*
2
abcdefghABCDEFGH
2
abc
abAB
xyz
1
xyz
*/
