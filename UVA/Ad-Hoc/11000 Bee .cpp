#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,female,female2,male,male2,total,i;
    while(1)
    {
        cin>>n;
        if(n==-1)
            break;
        total=1;
        female=1;
        female2=0;
        male=0;
        for(i=1; i<=n; i++)
        {
            male2=female;
            female=female+female2;
            total=female+total;
            female2=male2;
        }
        male=total-female;
        cout<<male<<" "<<total<<endl;
    }
    return 0;
}
