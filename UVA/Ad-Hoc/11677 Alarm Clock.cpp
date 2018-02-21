#include<stdio.h>
int main()
{
    long int h1,m1,h2,m2,solve1,solve2,solve;
    for(;;)
    {
        scanf("%ld %ld %ld %ld",&h1,&m1,&h2,&m2);
        if(h1==0&&m1==0&&h2==0&&m2==0)
            break;
        solve1 = h1*60+m1;
        solve2 = h2*60+m2;
        if(solve1>solve2)
            solve2=1440+solve2;
        solve=solve2-solve1;
        printf("%ld\n",solve);
    }
    return 0;
}
