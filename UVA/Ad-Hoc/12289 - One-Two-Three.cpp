#include<stdio.h>
#include<string.h>
int main()
{
    int T,t;
    char num[10];
    scanf("%d",&T);
    getchar();
    for(t=1;t<=T;t++)
    {
        gets(num);
        if(strlen(num)==5)
            printf("3\n");
        else
        {
            int count=0;
            if(num[0]=='o') count++;
            if(num[1]=='n') count++;
            if(num[2]=='e') count++;
            if(count>=2)
                printf("1\n");
            else
                printf("2\n");
        }
    }
    return 0;
}
