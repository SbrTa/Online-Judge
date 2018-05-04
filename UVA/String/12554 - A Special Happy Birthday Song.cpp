#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main()
{
    string man[105],s[5]= {"Happy","birthday","to","you","Rujia"};
    long n,i,j,k,line;

    while(cin>>n)
    {
        getchar();
        for(i=0; i<n;i++)
            getline(cin,man[i]);
        j=0; line=0; k=0;
        for(;;)
        {
            line++;
            for(i=0;i<4;i++)
            {
                cout<<man[k]<<": ";
                if(line==3&&i==3)
                    cout<<s[4]<<endl;
                else
                    cout<<s[i]<<endl;
                j++;
                k++;
                if(k==n)
                    k=0;
            }
            if(j>=n-1)
                if(line==4)
                    break;
            if(line==4)
                line=0;
        }
    }
    return 0;
}
