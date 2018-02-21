#include<cstdio>
#include<queue>
#include<string.h>
using namespace std;

struct info
{
    long id,n,plus;
} temp;

bool operator < (const info& x, const info& y)
{
    if(x.n==y.n)    return x.id > y.id;
    return x.n < y.n;
}

int main()
{
    long q;
    char str[100];
    priority_queue<info>pq;
    while(1)
    {
        scanf("%s",str);
        if(strcmp(str,"Register")==0)
        {
            scanf("%ld%ld",&temp.id,&temp.plus);
            temp.n=(-temp.plus);
            getchar();
            pq.push(temp);
        }
        else if(strcmp(str,"#")==0)
            break;
    }
    scanf("%ld",&q);
    while(q--)
    {
        info ans=pq.top();
        pq.pop();
        printf("%ld\n",ans.id);
        ans.n+=(-ans.plus);
        pq.push(ans);
    }
    return 0;
}
