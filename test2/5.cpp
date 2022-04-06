#include <bits/stdc++.h>
using namespace std;
int n;
int fa[100005],d[100005];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)fa[i]=i;
    for(int i=0;i<=n;i++)d[i]=1;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        cin>>sum;
        for(int j=1;j<=sum;j++)
        {
            int sp=0;
            cin>>sp;
            fa[sp]=i;
            d[sp]=d[i]+1;
        }
    }
    int maxx=0,pos=0;
    for(int i=0;i<n;i++)
    {
        if(d[i]>maxx)
        {
            maxx=d[i];
            pos=i;
        }
    }
    int sta[10005];
    int tot=0;
    cout<<d[pos]<<endl;
    for(int i=1;i<=d[pos];i++)
    {
        sta[++tot]=pos;
        pos=fa[pos];
    }
    while(tot)
    {
        cout<<sta[tot]<<" ";
        tot--;
    }
    cout<<endl;
}