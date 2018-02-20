#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,T,t,temp,last,end,start,i;
    long long sum;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>n;
        if(n==1)
            printf("Case %d: 1\n",t);
        else
        {
            sum = n;
            start = n;
            last = 1;
            for(i=2;; i++)
            {
                temp = n/i;
                end = temp;
                sum += (start - end)*last;
                if(end < i)
                    break;
                sum += temp;
                last = i;
                start = end;
                if(end==i)
                    break;
            }
            printf("Case %d: %lld\n",t, sum);
        }
    }
    return 0;
}
