#include<bits/stdc++.h>
using namespace std;

int main()
{
    double x,y;
    long i,j,cs=1;
    string s;
    char a,b;
    while(cin>>s&&s!="END"){
        x=0;
        y=0;
        long sz=s.size(),n=0,f=0;
        for(i=0;i<=sz;i++){
            if(s[i-1]=='.' || i==sz) continue;
            if(s[i]==',' || s[i]=='.'){
                //cout<<n<<endl;
                if(f==1){
                    //cout<<a<<endl;
                    if(a=='E') x+=n;
                    else if(a=='W') x-=n;
                    else if(a=='N') y+=n;
                    else if(a=='S') y-=n;
                }
                if(f==2){
                    //cout<<a<<b<<endl;
                    double t = n/(double)sqrt(2);
                    if(a=='N' && b=='E') x+=t,y+=t;
                    else if(a=='N' && b=='W') x-=t,y+=t;
                    else if(a=='S' && b=='E') x+=t,y-=t;
                    else if(a=='S' && b=='W') x-=t,y-=t;
                }
                n=0;
                f=0;
                //printf("%.3lf %.3lf\n",x,y);
            }
            else if(s[i]>='0' && s[i]<='9') n =(n*10) + (s[i]-'0');
            else{
                f++;
                if(f==1) a=s[i];
                else b=s[i];
            }
        }
        double dd = sqrt( (x*x)+(y*y) );
        //if(cs>1) printf("\n");
        printf("Map #%ld\nThe treasure is located at (%.3lf,%.3lf).\n",cs++,x,y);
        printf("The distance to the treasure is %.3lf.\n\n",dd);
    }
    return 0;
}
