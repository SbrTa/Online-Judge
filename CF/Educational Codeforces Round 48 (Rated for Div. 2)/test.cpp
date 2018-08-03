#include<bits/stdc++.h>
#define inf 100000000
using namespace std;

int y[111];

void findAllOccurances(std::string data, std::string toSearch)
{
	size_t pos = data.find(toSearch);
	while( pos != std::string::npos){
		y[pos] = 1;
		pos =data.find(toSearch, pos + toSearch.size());
	}
}

int main()
{
    int n,m,q,i,j,x[111],l,r;
    cin>>n>>m>>q;
	string s,t;
	cin>>s>>t;
	findAllOccurances(s , t);

    //for(i=0;i<n;i++) cout<<y[i]<<" ";

    x[0]=0;
    for(i=0;i<n;i++){
        x[i+1] = x[i];
        if(y[i]) x[i+1]++;
    }

    //for(i=0;i<n;i++) cout<<s[i]<<" "; cout<<endl;
    //for(i=0;i<n;i++) cout<<x[i]<<" "; cout<<endl;


    for(i=0;i<q;i++){
        scanf("%d%d",&l,&r);
        if(r-l+1 < m){
            printf("0\n");
            continue;
        }
        int ans = x[r-m+1] - x[l-1];
        printf("%d\n",ans);
    }

	return 0;
}
