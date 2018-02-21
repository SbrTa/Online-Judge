#include<stdio.h>
#include<string.h>

int main()
{
    int n,i,len1,len2,count;
    char s1[25],s2[25];
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        count=0;
        gets(s1);
        gets(s2);
        len1=strlen(s1);
        len2=strlen(s2);
        if(len1==len2)
        {
            for(i=0;i<len1;i++)
            {
                if((s1[i]=='a'||s1[i]=='e'||s1[i]=='i'||s1[i]=='o'||s1[i]=='u')
                   &&(s2[i]=='a'||s2[i]=='e'||s2[i]=='i'||s2[i]=='o'||s2[i]=='u'))
                   continue;
                if(s1[i]!=s2[i])
                {
                    count++;
                    break;
                }
            }
            if(count>0)
                printf("No\n");
            else
                printf("Yes\n");
        }
        else
            printf("No\n");
    }
    return 0;
}
