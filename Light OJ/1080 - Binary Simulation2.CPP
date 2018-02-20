#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define left node*2
#define right node*2+1
#define mid (beg+end)/2
#define common long node, long beg, long end

long arr[mx],tree[mx*3];

void update(common, long i, long j)
{
    if(i>end||j<beg)
        return;
    if(i<=beg&&j>=end)
    {
        tree[node]++;
        return;
    }
    update(left,beg,mid,i,j);
    update(right,mid+1,end,i,j);
}

long quest(common, long pos)
{
    if(beg==pos&&pos==end)
        return tree[node];

    if(pos<=mid)
        return tree[node]+quest(left,beg,mid,pos);
    else
        return tree[node]+quest(right,mid+1,end,pos);
}

int main()
{
    long n,q,i,test,cs;
    char str[mx],ch;
    scanf("%ld",&test);
    for(cs=1;cs<=test;cs++)
    {
        getchar();
        gets(str);
        n=strlen(str);
        memset(tree,0,sizeof(tree));
        scanf("%ld",&q);
        printf("Case %ld:\n",cs);
        while(q--)
        {
            long a,b,x;
            getchar();
            scanf("%c",&ch);
            if(ch=='I')  //Update
            {
                scanf("%ld%ld",&a,&b);
                update(1,1,n,a,b);
            }
            if(ch=='Q')   //Query
            {
                scanf("%ld",&a);
                x=quest(1,1,n,a);
                if(x%2==1)
                {
                    a--;
                    if(str[a]-'0'==0)
                        printf("1\n");
                    else
                        printf("0\n");
                }
                else
                {
                    a--;
                    printf("%ld\n",str[a]-'0');
                }
            }
        }
    }
    return 0;
}
