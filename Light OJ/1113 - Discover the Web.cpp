#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main()
{
    char s[1000][1000],ch[100];
    long int T,t,i,j,k,n;
    scanf("%ld",&T);
    getchar();
    for(t=1; t<=T; t++)
    {
        j=-1;
        printf("Case %ld:\n",t);
        i=0;
        while(1)
        {
            scanf("%s",&ch);
            getchar();
            if(strcmp(ch,"QUIT")==0)
                break;
            if(strcmp(ch,"VISIT")==0)
            {
                i++;
                gets(s[i]);
                printf("%s\n",s[i]);

                j=i;
            }

            else if(strcmp(ch,"BACK")==0)
            {
                i--;
                if(i==0)
                    printf("http://www.lightoj.com/\n");
                else if(i<0)
                {
                    printf("Ignored\n");
                    i=0;
                }
                else
                    printf("%s\n",s[i]);
            }
            else if(strcmp(ch,"FORWARD")==0)
            {

                i++;
                if(i>j)
                {
                    printf("Ignored\n");
                    i--;
                }

                else
                    printf("%s\n",s[i]);
            }
        }
    }
    return 0;
}

