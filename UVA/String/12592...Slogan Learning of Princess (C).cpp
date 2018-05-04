#include<stdio.h>
#include<string.h>

int main()
{
    int n,m,i,j;
    char s1[22][105],s2[22][105],q[105][105];
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        gets(s1[i]);
        gets(s2[i]);
    }
    scanf("%d",&m);
    getchar();
    for(i=0;i<m;i++)
    {
        gets(q[i]);
        for(j=0;j<n;j++)
        {
            if(strcmp(q[i],s1[j])==0)
            {
                puts(s2[j]);
                break;
            }
        }
    }
    return 0;
}
