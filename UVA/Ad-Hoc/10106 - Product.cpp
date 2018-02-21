#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a1,b1;
    while(cin>>a1>>b1)
    {
        //cin>>a1>>b1;
        long i,j,k,sa,sb;
        long a[30000],b[30000],t[30000],ans[60000];
        sa=a1.size();
        sb=b1.size();
        for(i=0; i<sa; i++) a[i] = a1[i] - '0';
        for(i=0; i<sb; i++) b[i] = b1[i] - '0';

        for(i=0; i<=sa+sb+10; i++) ans[i]=0;

        //for(i=0;i<sa;i++) cout<<a[i];
        //cout<<endl;
        //for(i=0;i<sb;i++) cout<<b[i];
        //cout<<endl;


        long sz, step=0;
        for(i=sb-1; i>=0; i--)
        {
            long n = b[i];
            long have=0,k=0;
            for(j=sa-1; j>=0; j--)
            {
                long x = a[j]*n;
                x=x+have;
                if(x>9)
                {
                    t[k]=x%10;
                    have=x/10;
                }
                else
                {
                    t[k]=x;
                    have=0;
                }
                k++;
            }
            t[k]=have;

            //temp+ans
            have=0;
            for(j=0,k=step; j<sa+1; j++,k++)
            {
                long x = ans[k]+t[j];
                x=x+have;
                if(x>9)
                {
                    ans[k]=x%10;
                    have=x/10;
                }
                else
                {
                    ans[k]=x;
                    have=0;
                }
            }
            while(have>0)
            {
                long x=have+ans[k];
                if(x>9)
                {
                    ans[k]=x%10;
                    have=x/10;
                }
                else
                {
                    ans[k]=x;
                    have=0;
                }
                k++;
            }

            //for(j=k-1;j>=0;j--) cout<<ans[j];
            //cout<<endl;
            step++;
            //sz=k;

        }
        j=sa+sb+5;
        while(ans[j]==0) j--;
        long f=0;
        for(; j>=0; j--){
            cout<<ans[j];
            f=1;
        }
        if(f==0) cout<<"0";
        cout<<endl;

    }
    return 0;
}

