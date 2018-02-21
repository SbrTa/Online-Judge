#include<stdio.h>
#include<string.h>

int main()
{
    int t,i,j;
    char s[222],stack[222];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(s);
        int top=0,len=strlen(s);
        if(len==0)
        {
            printf("Yes\n");
            continue;
        }
        stack[top++]=s[0];
        for(i=1;i<len;i++)
        {
            if(stack[top-1]=='('&&s[i]==')')
                top--;
            else if(stack[top-1]=='['&&s[i]==']')
                top--;
            else
                stack[top++]=s[i];
        }
        if(top==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
