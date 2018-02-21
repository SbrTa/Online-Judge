#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#define inf -99999999
using namespace std;

int main()
{
    int t,cs=1,i,j,l,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int vvv = n/2;
        int ccc = n/2;
        if(n%2) vvv++;
        char vowel[6] = {'A' , 'U' , 'E' , 'O' , 'I'};
        char conso[22] = {'J', 'S', 'B', 'K', 'T', 'C', 'L', 'D', 'M', 'V', 'N', 'W', 'F', 'X', 'G', 'P', 'Y', 'H', 'Q', 'Z', 'R'};

        map<char,int>v,c;
        // set vowel
        for(i=0; i<5 && vvv; i++)
        {
            if(vvv>21)
            {
                v[vowel[i]] = 21;
                vvv = vvv-21;
            }
            else
            {
                v[vowel[i]] = vvv;
                vvv = 0;
            }
        }

        // set consonant
        for(i=0; i<21 && ccc; i++)
        {
            if(ccc>5)
            {
                c[conso[i]] = 5;
                ccc = ccc-5;
            }
            else
            {
                c[conso[i]] = ccc;
                ccc = 0;
            }
        }

        // now print solution
        printf("Case %d: ",cs++);
        char vow[6] = { 'A', 'E', 'I', 'O', 'U' };
        char con[22] = { 'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};

        vvv=ccc=0;
        for(i=1;i<=n;i++)
        {
            if(i%2)
            {
                while(v[vow[vvv]] == 0)
                    vvv++;
                printf("%c",vow[vvv]);
                v[vow[vvv]]--;
            }
            else
            {
                while(c[con[ccc]] == 0)
                    ccc++;
                printf("%c",con[ccc]);
                c[con[ccc]]--;
            }
        }
        printf("\n");
    }
    return 0;
}
