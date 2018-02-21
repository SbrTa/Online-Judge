#include<cstdio>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        stack<int>stk;
        queue<int>qe;
        priority_queue<int>pq;
        int choice,temp,stk_flag=1,qe_flag=1,pq_flag=1;
        while(n--)
        {
            scanf("%d",&choice);
            if(choice==1)
            {
                scanf("%d",&temp);
                //a[i++]=temp;
                stk.push(temp);
                qe.push(temp);
                pq.push(temp);
            }
            else if(choice==2)
            {
                scanf("%d",&temp);
                int stk_top,qe_front,pq_top;

                if(!stk.empty())
                {
                    stk_top=stk.top();
                    if(stk_top!=temp)   stk_flag=0;
                    stk.pop();
                }
                else    stk_flag=0;

                if(!qe.empty())
                {
                    qe_front=qe.front();
                    if(qe_front!=temp)  qe_flag=0;
                    qe.pop();
                }
                else    qe_flag=0;

                if(!pq.empty())
                {
                    pq_top=pq.top();
                    if(pq_top!=temp)  pq_flag=0;
                    pq.pop();
                }
                else    pq_flag=0;
            }
        }
        if(stk_flag+qe_flag+pq_flag>=2)
            printf("not sure\n");
        else if(stk_flag+qe_flag+pq_flag==0)
            printf("impossible\n");
        else
        {
            if(stk_flag)    printf("stack\n");
            else if(qe_flag)    printf("queue\n");
            else if(pq_flag)    printf("priority queue\n");
        }
    }
    return 0;
}
