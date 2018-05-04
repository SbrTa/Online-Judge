#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s;
    int i,len;
    while(scanf("%c",&s)==1)
    {
        if(s=='/') cout<<".";
        if(s=='.')  cout<<",";
        if(s==',')  cout<<"M";
        if(s=='M')  cout<<"N";
        if(s=='N')  cout<<"B";
        if(s=='B')  cout<<"V";
        if(s=='V')  cout<<"C";
        if(s=='C')  cout<<"X";
        if(s=='X')  cout<<"Z";
        if(s=='Z')  cout<<"Z";

        if(s=='\n') cout<<"\n";
        if(s=='\'')  cout<<";";
        if(s==';')  cout<<"L";
        if(s=='L')  cout<<"K";
        if(s=='K')  cout<<"J";
        if(s=='J')  cout<<"H";
        if(s=='H')  cout<<"G";
        if(s=='G')  cout<<"F";
        if(s=='F')  cout<<"D";
        if(s=='D')  cout<<"S";
        if(s=='S')  cout<<"A";
        if(s=='A')  cout<<"A";

        if(s=='\\')  cout<<"]";
        if(s==']')  cout<<"[";
        if(s=='[')  cout<<"P";
        if(s=='P')  cout<<"O";
        if(s=='O')  cout<<"I";
        if(s=='I')  cout<<"U";
        if(s=='U')  cout<<"Y";
        if(s=='Y')  cout<<"T";
        if(s=='T')  cout<<"R";
        if(s=='R')  cout<<"E";
        if(s=='E')  cout<<"W";
        if(s=='W')  cout<<"Q";
        if(s=='Q')  cout<<"Q";

        if(s=='=')  cout<<"-";
        if(s=='-')  cout<<"0";
        if(s=='0')  cout<<"9";
        if(s>='2'&&s<='9')
            cout<<s-'1';
        if(s=='1')  cout<<"`";
        if(s=='`')  cout<<"`";

        if(s==' ')  cout<<" ";

    }
    return 0;
}
