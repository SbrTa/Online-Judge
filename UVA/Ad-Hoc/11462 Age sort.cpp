#include<stdio.h>
#include<algorithm>
#define MAX 2000005
using namespace std;

unsigned long long int age[MAX];
int main()
{
    long long int n,i;
    for(;;)
    {
        scanf("%lld",&n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
            scanf("%lld",&age[i]);
        sort(age,age+n);
        printf("%lld",age[0]);
        for(i=1;i<n;i++)
            printf(" %lld",age[i]);
        printf("\n");
    }
    return 0;
}
