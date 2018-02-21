#include<bits/stdc++.h>
using namespace std;

int main()
{
    long n,m,sum,i;
    while(scanf("%ld",&n)==1)
    {
        priority_queue<long>q;
        if(n==0)
            break;
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%ld",&m);
            q.push(-m);
        }
        while(q.size()>1)
        {
            long total=q.top();
            q.pop();
            total+=q.top();
            q.pop();
            sum+=total;
            q.push(total);
        }
        printf("%ld\n",-sum);
    }
    return 0;
}
