#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string,long>mp;
    string s[10004],str;
    long test,cs;
    cin>>test;
    getchar();
    getchar();
    for(cs=0;cs<test;cs++)
    {
        if(cs>0)
            cout<<endl;
        mp.clear();
        long i,n=0,m=0;
        while(1)
        {
            getline(cin,str);
            if(str[0]=='\0')
                break;
            if(!mp[str])
                s[m++]=str;
            mp[str]++;
            n++;
        }
        sort(s,s+m);
        for(i=0; i<m; i++)
        {

            float ans=(float)(100*mp[s[i]])/(float)n;
            cout<<s[i];
            printf(" %.4f\n",ans);
        }
    }
    return 0;
}
