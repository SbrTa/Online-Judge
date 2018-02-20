#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,t,n,m,arr[110],ar[110],i,j,nn,x,y;
    char s;
    cin>>T;
    for(t=1; t<=T; t++)
    {
        cin>>n>>m;
        for(i=0; i<n; i++)
            cin>>arr[i];
        getchar();
        while(m--)
        {
            cin>>s;
            if(s=='S')
            {
                cin>>nn;
                for(i=0; i<n; i++)
                    arr[i]=arr[i]+nn;
            }
            else if(s=='M')
            {
                cin>>nn;
                for(i=0; i<n; i++)
                    arr[i]=arr[i]*nn;
            }
            else if(s=='D')
            {
                cin>>nn;
                for(i=0; i<n; i++)
                    arr[i]=arr[i]/nn;
            }
            else if(s=='R')
            {
                for(i=0; i<n; i++)
                    ar[i]=arr[i];
                for(i=n-1,j=0; i>=0; i--,j++)
                    arr[j]=ar[i];
            }
            else if(s=='P')
            {
                cin>>x>>y;
                int temp=arr[x];
                arr[x]=arr[y];
                arr[y]=temp;
            }
        }
        printf("Case %d:\n%d",t,arr[0]);
        for(i=1; i<n; i++)
            cout<<" "<<arr[i];
        puts("");
    }
    return 0;
}
