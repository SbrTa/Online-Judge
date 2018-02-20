#include<stdio.h>
#define mx 100005
#define INF 2147483646

long tree[mx*3],arr[mx];

long min(long a, long b)
{
    if(a<b)
        return a;
    return b;
}

void segment(long node, long Begin, long End)
{
    if(Begin==End)
    {
        tree[node]=arr[Begin];
        return;
    }
    long left=node*2;
    long right=node*2+1;
    long mid=(Begin+End)/2;
    segment(left,Begin,mid);
    segment(right,mid+1,End);
    tree[node]=min(tree[left],tree[right]);
}

long quest(long node, long Begin, long End, long a, long b)
{

    if(a>End||b<Begin||Begin>End)
        return INF;
    if((Begin>=a&&End<=b))//&&(Begin==End))
        return tree[node];
    long left=node*2;
    long right=node*2+1;
    long mid=(Begin+End)/2;
    long x = quest(left,Begin,mid,a,b);
    long y = quest(right,mid+1,End,a,b);
    return min(x,y);
}

int main()
{
    long test,cs,n,q,i,a,b,v;
    scanf("%ld",&test);
    for(cs=1;cs<=test;cs++)
    {
        scanf("%ld%ld",&n,&q);
        for(i=1;i<=n;i++)
            scanf("%ld",&arr[i]);
        segment(1,1,n);
        printf("Case %ld:\n",cs);
        while(q--)
        {
            scanf("%ld%ld",&a,&b);
            printf("%ld\n",quest(1,1,n,a,b));
        }
    }
    return 0;
}
