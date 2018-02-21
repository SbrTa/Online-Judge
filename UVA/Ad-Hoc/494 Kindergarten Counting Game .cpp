#include<bits/stdc++.h>
using namespace std;

int main()
{
    int count,s,i;
    char ch[10000];
    while(gets(ch))
    {
        s=0;count=0;
        for(i=0; i<strlen(ch); i++)
        {
            if(isalpha(ch[i]))
            {
                if(s==0)
                    count++;
                s=1;
            }
            else
                s=0;
        }
        printf("%d\n",count);
    }
    return 0;
}
