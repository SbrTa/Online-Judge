#include<bits/stdc++.h>
int main()
{
    int len_a,i,j,k;
    char a[10000],b[10000],c[10000];
    while(gets(a)&&strcmp(a,"DONE")!=0)
    {
        len_a=strlen(a);
        j=0;
        for(i=0; i<len_a; i++)
        {
            if(isalpha(a[i]))
            {
                b[j]=tolower(a[i]);
                j++;
            }
        }
        k=0;
        for(i=0; i<j/2; i++)
        {
            if(b[i]!=b[j-i-1])
            {
                k=1;
                break;
            }
        }
        if(k==0)
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
    }
    return 0;
}
