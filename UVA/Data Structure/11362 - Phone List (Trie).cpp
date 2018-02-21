#include<bits/stdc++.h>
using namespace std;

long flag;

struct node
{
    long endmark;
    node *next[11];
    node()
    {
        endmark = 0;
        for(long i=0; i<10; i++)
            next[i]=NULL;
    }
}*root;

void insert(string str)
{
    node *cur = root;
    for(long i=0; i<str.size(); i++)
    {
        long id = str[i]-'0';
        if(cur->endmark!=0)
            flag+=cur->endmark;
        if(cur->next[id]==NULL)
            cur->next[id] = new node();
        cur = cur->next[id];
    }
    cur->endmark++;
}

void del(node *cur)
{
    for(long i=0; i<10; i++)
        if(cur->next[i])
            del(cur->next[i]);
    delete(cur);
}

int main()
{
    long test,n,i;
    string str[10005];
    scanf("%ld",&test);
    while(test--)
    {
        root = new node();
        flag=0;
        scanf("%ld",&n);
        getchar();
        for(i=0;i<n;i++)
            cin>>str[i];
        sort(str,str+n);
        for(i=0;i<n;i++)
        {
            if(flag!=0)
                break;
            insert(str[i]);
        }
        if(flag==0)
            printf("YES\n");
        else
            printf("NO\n");
        del(root);
    }
    return 0;
}
