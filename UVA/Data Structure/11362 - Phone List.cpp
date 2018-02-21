#include<bits/stdc++.h>
using namespace std;

bool check(string a, string b)
{
    if(a.size()>b.size())
        return false;
    for(int i=0; i<a.size(); i++)
        if(a[i]!=b[i])
            return false;
    return true;
}

int main()
{
    int test,n,i,flag;
    string str[10004];
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        getchar();
        for(i=0; i<n; i++)
            cin>>str[i];
        sort(str,str+n);
        flag=0;
        for(i=0; i<n-1; i++)
        {
            if(check(str[i],str[i+1]))
            {
                flag=1;
                break;
            }
        }
        if(flag==0) printf("YES\n");
        else    printf("NO\n");
    }
    return 0;
}

