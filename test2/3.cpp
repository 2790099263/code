#include <bits/stdc++.h>
using namespace std;
int n;
string s[1005];
bool sort_it(string a,string b)
{
    return a<b;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        map<string,int>p1;
        map<int,string>p2;
        map<string,int>p3;
        int cnt=0;
        for(int i=1;i<=n;i++)
            cin>>s[i];
        sort(s+1,s+n+1,sort_it);
        for(int i=1;i<=n;i++)
        {
            if(!p1[s[i]])
            {
                p1[s[i]]=++cnt;
                p2[cnt]=s[i];
            }
            p3[s[i]]++;
        }
        int maxx=0,pos=0;
        for(int i=1;i<=cnt;i++)
        {
            if(p3[p2[i]]>maxx)
            {
                maxx=p3[p2[i]];
                pos=i;
            }
        }
        cout<<p2[pos]<<endl;
    }
}