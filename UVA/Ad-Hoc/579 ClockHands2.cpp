#include<stdio.h>
int main()
{
    int m,h;
    float md,hd,fd;
    char c;
    for(;;)
    {
	scanf("%d%c%d",&h,&c,&m);

	if(h==0&&m==0)
	    break;
	if(c==':')
	{
	    md=m*6;
	    hd=((h*30)+(m*0.5));
	    fd=(md-hd);
	    if(fd<0)	fd=fd*-1;
	    if(fd>180)	fd=360-fd;
	    printf("%.3f\n",fd);
	}
    }
return 0;
}
