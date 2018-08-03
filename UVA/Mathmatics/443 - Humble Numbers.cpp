#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main()
{
    LL n,i,h[5845];
    LL two,three,five,seven;
    h[1] = two = three = five = seven = 1;
    for(i=2;i<=5842;i++){
        h[i] = min(min(h[two]*2, h[three]*3), min(h[five]*5, h[seven]*7));
        if(h[i] == h[two]*2)    two++;
        if(h[i] == h[three]*3)  three++;
        if(h[i] == h[five]*5)   five++;
        if(h[i] == h[seven]*7)  seven++;
    }

    while(scanf("%lld",&n) && n>0){
        char s[5];
        if(n%100>=11 && n%100<=19) strcpy(s,"th");
        else if(n%10==1) strcpy(s,"st");
        else if(n%10==2) strcpy(s,"nd");
        else if(n%10==3) strcpy(s,"rd");
        else strcpy(s,"th");

        printf("The %lld%s humble number is %lld.\n",n,s,h[n]);
    }
    return 0;
}
