#include<bits/stdc++.h>

using namespace std;

int main()
{
    long T, a, b, c[100000];

    while(cin>>T && T)
    {
        long flag=1, i;
        for(i=0; i<T; i++)
        {
            cin>>c[i];
        }
        c[i]=1422;
        sort(c,c+T);
        for(a=1; a<T; a++)
        {

            if( labs(c[a]-c[a-1]) > 200)
            {
                flag=-2;
                break;
            }
        }

        if((2*(c[i] - c[i-1])) > 200) flag=-2;

        if(flag==1)
            cout<<"POSSIBLE"<<endl;
        else
            cout<<"IMPOSSIBLE"<<endl;
    }


    return 0;
}
