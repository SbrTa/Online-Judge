#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    char s[25][25],ss[25][25],ch[20];
    int n,m,i,j,len;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(i=0; i<n; i++)
        {
            scanf("%s",&s[i]);
            getchar();
            scanf("%s",&ss[i]);
            getchar();
        }
        for(i=0; i<m; i++)
        {
            gets(ch);
            int flag=0;
            for(j=0; j<n; j++)
            {
                if(strcmp(ch,s[j])==0)
                {
                    printf("%s\n",ss[j]);
                    flag++;
                }
            }
            if(flag>0)
                continue;
            len=strlen(ch);
            if(ch[len-1]=='y')
            {
                if(ch[len-2]=='a'||ch[len-2]=='e'||ch[len-2]=='i'||
                        ch[len-2]=='o'||ch[len-2]=='u')
                    printf("%ss\n",ch);
                else
                    for(j=0; j<len; j++)
                    {
                        if(j==len-1)
                        {
                            printf("ies\n");
                            continue;
                        }
                        else
                            printf("%c",ch[j]);
                    }
            }
            else if(ch[len-1]=='o'||ch[len-1]=='s'||ch[len-1]=='x'||
                    (ch[len-1]=='h'&&(ch[len-2]=='c'||ch[len-2]=='s')))
            {
                printf("%ses\n",ch);
            }
            else
                printf("%ss\n",ch);
        }
    }
    return 0;
}


