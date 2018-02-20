#include<bits/stdc++.h>
using namespace std;
#define Set(a,b) memset(a,b,sizeof(a))

int main()
{
    int T,t,len1,len2,i,j,array1[27],array2[27];
    char s1[110],s2[110],c;
    scanf("%d",&T);
    getchar();
    for(t=1;t<=T;t++)
    {
        gets(s1);
        gets(s2);
        len1=strlen(s1);
        len2=strlen(s2);
        Set(array1,0);
        Set(array2,0);

        for(i=0;i<len1;i++)
        {
            c=tolower(s1[i]);
            if(c>='a'&&c<='z')
            {
                array1[c-'a']++;
            }
        }
        for(i=0;i<len2;i++)
        {
            c=tolower(s2[i]);
            if(c>='a'&&c<='z')
            {
                array2[c-'a']++;
            }
        }
        int flag=0;
        for(i=0;i<26;i++)
        {
            if(array1[i]!=array2[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            printf("Case %d: No\n",t);
        else
            printf("Case %d: Yes\n",t);
    }
    return 0;
}
