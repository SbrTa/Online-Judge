#include<stdio.h>
int main()
{
    int test_case,term1,term2,final,attendance,ct1,ct2,ct3,i,total,x,ct_avg;
    scanf("%d",&test_case);
    for(i=1;i<=test_case;i++)
    {
        scanf("%d %d %d %d %d %d %d",&term1,&term2,&final,&attendance,&ct1,&ct2,&ct3);
        x=(ct1<ct2)?((ct1<ct3)?ct1:ct3):((ct2<ct3)?ct2:ct3);
        ct_avg=(ct1+ct2+ct3-x)/2;
        total=term1+term2+final+attendance+ct_avg;
        if(total>=90)   printf("Case %d: A\n",i);
        else if(total>=80)  printf("Case %d: B\n",i);
        else if(total>=70)  printf("Case %d: C\n",i);
        else if(total>=60)  printf("Case %d: D\n",i);
        else    printf("Case %d: F\n",i);
    }
    return 0;
}
