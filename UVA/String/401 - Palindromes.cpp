#include<bits/stdc++.h>
using namespace std;

char str[100];
char chart1[22]={"AEHIJLMOSTUVWXYZ12358"};
char chart2[22]={"A3HILJMO2TUVWXY51SEZ8"};

int palindrome()
{
    int len,i,j,res=1;
    len=strlen(str);
    for(i=0; i<len/2; i++)
    {
        if(str[i]!=str[len-1-i])
        {
            res=0;
            break;
        }
    }
    return res;
}

int mirrored()
{
    int i,l,k,len,res=1;
    len=strlen(str);

    for(i=0,l=0; i<=len/2; i++)
    {
        for(k=0; k<21; k++)
        {
            if(str[i]==chart1[k]&&str[len-1-i]==chart2[k])
                break;
        }
        if(k==21)
        {
            res=0;
            break;
        }
    }
    return res;
}


int main()
{
    int p,m;
    while(cin>>str)
    {
        p=palindrome();
        m=mirrored();

        if(p==0 && m==0)
            printf("%s -- is not a palindrome.\n\n",str);
        else if(p==1 && m==0 )
            printf("%s -- is a regular palindrome.\n\n",str);
        else if(p==0 && m==1)
            printf("%s -- is a mirrored string.\n\n",str);
        else if(p==1 && m==1)
            printf("%s -- is a mirrored palindrome.\n\n",str);
    }
    return 0;
}
