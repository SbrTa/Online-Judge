#include<stdio.h>
#define mx 100005

long tree[mx*3],arr[mx];

void segment(long node, long beg, long end)
{
    if(beg==end)
    {
        tree[node]=arr[beg];
        return;
    }
    long left=node*2;
    long right=node*2+1;
    long mid=(beg+end)/2;
    segment(left,beg,mid);
    segment(right,mid+1,end);
    tree[node]=tree[left]+tree[right];
}

void update(long node, long beg, long end, long index, long value)
{
    if(beg>index||end<index||beg>end)
        return;
    if(beg==end&&end==index)
    {
        tree[node]=value;
        return;
    }
    long left=node*2;
    long right=node*2+1;
    long mid=(beg+end)/2;
    update(left,beg,mid,index,value);
    update(right,mid+1,end,index,value);
    tree[node]=tree[left]+tree[right];
}

long quest(long node, long beg, long end, long a, long b)
{
    if(beg>b||end<a)
        return 0;
    if(beg>=a&&end<=b)
        return tree[node];
    long left=node*2;
    long right=node*2+1;
    long mid=(beg+end)/2;
    long x=quest(left,beg,mid,a,b);
    long y=quest(right,mid+1,end,a,b);
    return (x+y);
}

int main()
{
    long test,cs,i,n,q,choice;
    scanf("%ld",&test);
    for(cs=1;cs<=test;cs++)
    {
        scanf("%ld %ld",&n,&q);
        for(i=1;i<=n;i++)
            scanf("%ld",&arr[i]);
        segment(1,1,n);
        printf("Case %ld:\n",cs);
        while(q--)
        {
            scanf("%ld",&choice);
            if(choice==1)
            {
                long index;
                scanf("%ld",&index);
                index++;
                printf("%ld\n",arr[index]);
                update(1,1,n,index,0);
                arr[index]=0;
            }
            else if(choice==2)
            {
                long index,value;
                scanf("%ld%ld",&index,&value);
                index++;
                arr[index]=arr[index]+value;
                update(1,1,n,index,arr[index]);
            }
            else if(choice==3)
            {
                long a,b;
                scanf("%ld%ld",&a,&b);
                a++;b++;
                printf("%ld\n",quest(1,1,n,a,b));
            }
        }
    }
    return 0;
}
