#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main()
{
    int m,n,len,i,j,k,l,ll,a,arr[75],set=1,count;
    char key[25][75],excuse[25][75],excuse2[25][75],st[75];
    while(scanf("%d%d",&m,&n)==2)
    {
        getchar();
        memset(arr,0,70);
        ll=0;
        for(i=0; i<m; i++)
            gets(key[i]);
        for(i=0; i<n; i++)
        {
            gets(excuse[i]);
            strcpy(excuse2[i],excuse[i]);
            len=strlen(excuse[i]);
            excuse[i][len]='.';
            len++;
            l=0;  a=1;
            count=0;
            for(j=0; j<len; j++)
            {
                if(isalpha(excuse[i][j]))
                {
                    a=0;
                    st[l++]=excuse[i][j];
                }
                else
                {
                    if(a==0)
                    {
                        st[l]='\0';
                        for(k=0; k<m; k++)
                        {
                            int no=0;
                            if(strlen(key[k])==strlen(st))
                            {
                                for(int ii=0; ii<strlen(st); ii++)
                                {
                                    if(key[k][ii]!=st[ii]&&toupper(key[k][ii])!=st[ii])
                                    {
                                        no=1;
                                        break;
                                    }
                                }
                                if(no==0)
                                    count++;
                            }
                        }
                    }
                    a++;
                    l=0;
                }
            }
            arr[ll++]=count;
        }
        int max=0;
        for(i=0; i<ll; i++)
        {
            if(arr[i]>max)
                max=arr[i];
        }
        printf("Excuse Set #%d\n",set++);
        for(i=0; i<ll; i++)
        {
            if(arr[i]==max)
                printf("%s\n",excuse2[i]);
        }
        puts("");
    }
    return 0;
}

