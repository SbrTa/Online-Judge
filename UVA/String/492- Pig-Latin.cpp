#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s,f;
    while(scanf("%c",&s)==1)
    {
        if(isalpha(s))
        {
            if(s=='A'||s=='E'||s=='I'||s=='O'||s=='U'||
                s=='a'||s=='e'||s=='i'||s=='o'||s=='u')
            {
                while(isalpha(s))
                {
                    printf("%c",s);
                    scanf("%c",&s);
                }
                printf("ay");
            }
            else
            {
                f=s;
                scanf("%c",&s);
                while(isalpha(s))
                {
                    printf("%c",s);
                    scanf("%c",&s);
                }
                printf("%cay",f);
            }
        }
        printf("%c",s);
    }
    return 0;
}
