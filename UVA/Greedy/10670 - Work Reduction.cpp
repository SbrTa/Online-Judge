#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

int main()
{
    //freopen("A.txt", "r", stdin);
    //freopen("A.out.txt", "w", stdout);
    long t,cs=1,n,m,l,a,b,i,j,in;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld%ld%ld",&n,&m,&l);
        vector<pair<long,string> >v;
        char c;
        string name="AAAAAAAAAAAAAAAAAAAA";
        for(in=1; in<=l; in++)
        {
            i=0;
            getchar();
            while(scanf("%c",&c) && c!=':')
                name[i++]=c;
            name[i]=':';
            scanf("%ld,%ld",&a,&b);
            long cost=0,temp=n;

            while(temp!=m)
            {
                long half = (temp%2) ? ((temp/2)+1) : (temp/2);
                //cout<<half<<endl;
                if(temp-half<m)
                {
                    half=temp-m;
                    temp=m;
                    cost+=(half*a);
                    break;
                }
                else temp-=half;
                //cout<<half<<endl;
                if(half*a>b) cost+=b;
                else cost+=(half*a);
                //cout<<temp<<" "<<cost<<endl;
            }
            //cout<<endl;
            v.push_back(make_pair(cost,name));
        }
        sort(v.begin(),v.end());
        printf("Case %ld\n",cs++);
        for(i=0;i<l;i++)
        {
            for(j=0;j<20;j++)
            {
                if(v[i].second[j]==':')
                {
                    printf(" ");
                    break;
                }
                else printf("%c",v[i].second[j]);
            }
            printf("%ld\n",v[i].first);
        }
    }
    return 0;
}


/*
input:
7
100 51 3
ABC:10,1
ABD:1,10
BCD:5,5
100 49 3
DDD:10,1
BBB:1,10
AAAAA:5,5
1300 1 3
EASY:100,1
MEDIUM:1,100
HARD:1,1000
1500 88 3
SECOND:0,0
LAST:10,0
FIRST:0,10
1000 1000 3
A:100,100
B:10,10
C:0,0
100000 1 2
B:10000,10
A:10,10000
100000 9 1
ABC:10000,10000

Output:
Case 1
ABD 49
BCD 245
ABC 490
Case 2
AAAAA 10
BBB 11
DDD 11
Case 3
EASY 10
MEDIUM 461
HARD 1299
Case 4
FIRST 0
SECOND 0
LAST 50
Case 5
A 0
B 0
C 0
Case 6
B 160
A 75610
Case 7
ABC 160000
*/
