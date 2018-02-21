#include<stdio.h>
int main()
{
int t,cdd,cmm,cyyyy,bdd,bmm,byyyy,age,i;
char x,y;
scanf("%d",&t);
for(i=1;i<=t;i++)
{
   scanf("%d%c%d%c%d",&cdd,&x,&cmm,&y,&cyyyy);
   scanf("%d%c%d%c%d",&bdd,&x,&bmm,&y,&byyyy);
   if(x=='/'&&y=='/'&&cdd<=31&&bdd<=31&&cmm<=12&&bmm<=12)
    {
	if(cdd<bdd)
	    bmm++;
	if(cmm<bmm)
	    byyyy++;
	age=cyyyy-byyyy;
	if(age<0)
	    printf("Case #%d: Invalid birth date\n",i);
	else if(age>130)
	    printf("Case #%d: Check birth date\n",i);
	else
	    printf("Case #%d: %d\n",i,age);
    }
    else if(x==' '&&y==' ')
	printf("Case #%d: Invalid birth date\n",i);
}
return 0;
}
