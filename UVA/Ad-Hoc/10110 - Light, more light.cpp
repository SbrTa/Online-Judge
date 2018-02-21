#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#define inf 0x7f7f
using namespace std;

int main()
{
    long n,i;
    while(scanf("%ld",&n)==1 && n)
    {
        long a=sqrt(n);
        if(a*a==n)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

