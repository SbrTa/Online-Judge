#include<stdio.h>
int main()
{
int t,n,m,i,j,r;
scanf("%d",&t);
for(i=1;i<=t;i++)
{
    int a0=0,a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0;
    scanf("%d",&n);
    for(j=1;j<=n;j++)
    {
        m=j;
        while(m!=0)
        {
        r=m%10;
        m=m/10;
        if(r==0)    a0++;
        else if(r==1)   a1++;
        else if(r==2)   a2++;
        else if(r==3)   a3++;
        else if(r==4)   a4++;
        else if(r==5)   a5++;
        else if(r==6)   a6++;
        else if(r==7)   a7++;
        else if(r==8)   a8++;
        else    a9++;
        }
    }
    printf("%d %d %d %d %d %d %d %d %d %d\n",a0,a1,a2,a3,a4,a5,a6,a7,a8,a9);
}
return 0;
}
