#include<bits/stdc++.h>
using namespace std;

#define     mx       100005
#define     left     node*2
#define     right    node*2+1
#define     mid      (beg+end)/2
#define     common   long node, long beg, long end

struct info
{
    long sum,prop;
}tree[mx*3];

void update(common, long i, long j, long x)
{
    if(i>end||j<beg)
        return;
    if(i<=beg&&j>=end)
    {
        tree[node].sum+=((end-beg+1)*x);
        tree[node].prop+=x;
        return;
    }

    update(left,beg,mid,i,j,x);
    update(right,mid+1,end,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+((end-beg+1)*tree[node].prop);
}

long quest(common, long i, long j, long carry)
{
    if(i>end||j<beg)
        return 0;
    if(i<=beg&&j>=end)
        return tree[node].sum+carry*(end-beg+1);

    long p1=quest(left,beg,mid,i,j,carry+tree[node].prop);
    long p2=quest(right,mid+1,end,i,j,carry+tree[node].prop);
    return p1+p2;
}

int main()
{
    long n,q,i,test,cs;
    scanf("%ld",&test);
    for(cs=1;cs<=test;cs++)
    {
        scanf("%ld%ld",&n,&q);
        //for(i=0;i<=3*n;i++)
            //tree[i].prop=tree[i].sum=0;
        memset(tree,0,sizeof(tree));
        printf("Case %ld:\n",cs);
        while(q--)
        {
            long choice,a,b,v;
            scanf("%ld%ld%ld",&choice,&a,&b);
            if(choice==0)  //Update
            {
                scanf("%ld",&v);
                update(1,0,n-1,a,b,v);
            }
            if(choice==1)   //Query
            {
                v=quest(1,0,n-1,a,b,0);
                printf("%ld\n",v);
            }
        }
    }
    return 0;
}
