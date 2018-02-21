#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    char a[1000], b[1000],c[1000];
    int len_a,len_b,num_a[1000],num_b[1000],num_result[1000],i,j,k,l,m,n;
    while(gets(a))
    {
        gets(b);
        len_a=strlen(a);
        len_b=strlen(b);
        k=0;
        for(i=0;i<len_a;i++)
        {
            num_a[k]=a[i];
            k++;
        }
        l=0;
        for(i=0;i<len_b;i++)
        {
            num_b[l]=b[i];
            l++;
        }
        sort(num_a,num_a+k);
        sort(num_b,num_b+l);
        m=0;
        for(i=0;i<k;i++)
            for(j=0;j<l;j++)
                if(num_a[i]==num_b[j])
                {
                    num_b[j]=0;
                    num_result[m]=num_a[i];
                    m++;
                    break;
                }
        n=0;
        for(i=0;i<m;i++)
        {
            c[n]=num_result[i];
            n++;
        }
        for(i=0;i<n;i++)
            printf("%c",c[i]);

        printf("\n");
    }
return 0;
}
