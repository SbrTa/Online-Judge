#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int x , y;
    int test;
    int steps = 0;
    cin>>test;

    for(int i=0; i<test ; i++)
    {
        cin>>x>>y;
        int diff=y-x;
        steps = 0;

        if(diff != 0)
        {
            int s = 0;
            int z = 2;
            while(diff > s)
            {
                s += (z / 2);
                steps++;
                z++;
            }
        }

        cout<<steps<<endl;
    }
    return 0;
}
