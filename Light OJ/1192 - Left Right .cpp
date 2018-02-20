#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
#define inf 0x7f7f7f7f
using namespace std;

int main()
{
    int test,cs=1;
    int n,i,j,a,b;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        int sol=0;
        while(n--){
            scanf("%d%d",&a,&b);
            sol=sol^(b-a-1);
        }
        printf("Case %d: ",cs++);
        if(sol) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
