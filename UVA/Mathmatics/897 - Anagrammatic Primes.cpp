#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#define inf 10000001
using namespace std;



bool chk[inf];

void Prime()
{
    long i,j;
    for(i=3; i<=inf; i+=2)
        chk[i]=true;
    for(i=3; i*i<=inf; i+=2)
    {
        if(chk[i]==true)
        {
            for(j=i*i; j<=inf; j+=i+i)
                chk[j]=false;
        }
    }
}



int ang[inf];
vector<int>digit;
vector<long>v;

void generate_vector(long n)
{
    digit.clear();
    int m;
    while(n!=0)
    {
        m=n%10;
        digit.push_back(m);
        n=n/10;
    }
    sort(digit.begin(),digit.end());
}



void Anagram()
{
    long i,j;
    v.push_back(2);
    for(i=3; i<=inf; i+=2)
    {
        if(chk[i]==true)
        {
            bool flag = true;
            generate_vector(i);
            do
            {
                long n=0;
                for(j=0; j<digit.size(); j++)
                    n = n*10 + digit[j];
                if((n>1 && n%2==1 && chk[n]==true) || n==2);
                else
                {
                    flag=false;
                    break;
                }
            }
            while( next_permutation(digit.begin(),digit.end()) );
            if(flag==true)
                v.push_back(i);
        }
    }
}

int main()
{
    Prime();
    Anagram();
    long n;
    while(cin>>n && n!=0)
    {
        long up = upper_bound(v.begin(),v.end(),n) - v.begin();
        int d=0;
        while(n!=0)
            n=n/10,d++;
        if(v[up]<=pow(10,d))
            cout<<v[up]<<endl;
        else
            cout<<"0\n";
    }
    return 0;
}
