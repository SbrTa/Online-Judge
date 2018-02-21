#include<stdio.h>
#include<math.h>

int main()

{
  int i,t,d,u,v;
  float p,q,r;

  scanf("%d",&t);
  for(i=1;i<=t;i++)
  {
      scanf("%d %d %d",&d,&v,&u);
      if((u<=0&&v<=0)||u<=v)
       printf("Case %d: can't determine\n",i);
       else
       {
      p=(float)d/(sqrt(u*u-v*v));
      q=(float)d/u;
      r=p-q;
        if(r<=0)
        printf("Case %d: can't determine\n",i);
         else
        printf("Case %d: %.3f\n",i,r);
      }
  }
    return 0;
}
