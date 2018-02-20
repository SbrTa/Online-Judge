#include<bits/stdc++.h>
using namespace std;

int main()
{
    string ch,stk[105],s;
    int T,t,i,top;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        printf("Case %d:\n",t);
        for(i=0;i<105;i++)
            stk[i].clear();
        top=i=0;
        stk[top]="http://www.lightoj.com/";
        while(cin>>ch)
        {
            if(ch=="VISIT")
            {
                cin>>s;
                cout<<s<<endl;
                stk[++top]=s;
                i=top;
            }
            if(ch=="BACK")
            {
                if(top==0)
                    cout<<"Ignored"<<endl;
                else
                    cout<<stk[--top]<<endl;
            }
            if(ch=="FORWARD")
            {
                if(top==i)
                    cout<<"Ignored"<<endl;
                else
                    cout<<stk[++top]<<endl;
            }
            if(ch=="QUIT")
                break;
        }
    }
    return 0;
}
