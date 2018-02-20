#include<stdio.h>
#include<string.h>
int main()
{
    int T,t,queue[35];
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        memset(queue,0,sizeof(queue));
        int n,m,use=0,i=15,j=16,item,data;
        char s[20];
        printf("Case %d:\n",t);
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%s",s);
            if(strcmp(s,"pushLeft")==0)
            {
                scanf("%d",&item);
                if(use<n)
                {
                    queue[i]=item;
                    use++;
                    i--;
                    printf("Pushed in left: %d\n",item);
                }
                else
                    printf("The queue is full\n");
            }
            else if(strcmp(s,"pushRight")==0)
            {
                scanf("%d",&item);
                if(use<n)
                {
                    queue[j]=item;
                    use++;
                    j++;
                    printf("Pushed in right: %d\n",item);
                }
                else
                    printf("The queue is full\n");
            }
            else if(strcmp(s,"popLeft")==0)
            {
                if(use>0)
                {
                    i++;
                    data=queue[i];
                    use--;
                    printf("Popped from left: %d\n",data);
                }
                else
                    printf("The queue is empty\n");
            }
            else if(strcmp(s,"popRight")==0)
            {
                if(use>0)
                {
                    j--;
                    data=queue[j];
                    use--;
                    printf("Popped from right: %d\n",data);
                }
                else
                    printf("The queue is empty\n");
            }
        }
    }
    return 0;
}
