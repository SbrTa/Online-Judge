#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t=0,n,a[15][15],sum,m,i,j,k;
    for(;;)
    {
        cin>>n;
        if(n==0)
            break;
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                cin>>a[i][j];
        k=0;
        m=n/2;
        printf("Case %lld:",++t);
        while(m--)
        {
            sum=0;
            if(k==n/2)
                break;
            for(i=k; i<n-k; i++)
            {
                for(j=k; j<n-k; j++)
                {
                    if(i==k||i==n-k-1||j==k||j==n-k-1)
                        sum=sum+a[i][j];
                }
            }
            k++;
            cout<<" "<<sum;
        }
        if(n&1)
            cout<<" "<<a[n/2][n/2];
        cout<<endl;
    }
    return 0;
}
