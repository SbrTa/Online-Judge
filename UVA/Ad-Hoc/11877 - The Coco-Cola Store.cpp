#include<stdio.h>
int main()
{
    int empty,full;
    for(;;)
    {
        int total_bottle=0;
        scanf("%d",&empty);
        if(empty==0)    break;
        saf:    full=empty/3;
                empty=empty%3+full;
                total_bottle=total_bottle+full;

        if(empty>=3) goto saf;
        if(empty==2)    total_bottle=total_bottle+1;
        printf("%d\n",total_bottle);
    }
    return 0;
}
