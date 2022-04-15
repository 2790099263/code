//![](https://raw.githubusercontent.com/2790099263/tuchuang/master/20220415111037.png)
//O纯白色的少年郎，如今只身在何方
#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
const long long INF=200000000000000;
int n,m,s;
int head[MAXN],ver[MAXN],nxt[MAXN],wi[MAXN],tot;
inline void add(int x,int y,int w){ver[++tot]=y;wi[tot]=w;nxt[tot]=head[x];head[x]=tot;}
long long dis[MAXN];
priority_queue<pair<long long,int>>q;
inline void dji()
{
    memset(dis,127,sizeof(dis));
    // cout<<"diss  "<<dis[0]<<endl;
    dis[s]=0ll;
    q.push({0ll,s});
    while(q.size())
    {
        int x=q.top().second;
        int y2=q.top().first;
        // cout<<x<<endl;
        q.pop();
        int y=0;
        if(dis[x]<-y2)continue;
        for(register int i=head[x];i;i=nxt[i])
        {
            y=ver[i];
            if(dis[y]>dis[x]+wi[i])
            {
                dis[y]=dis[x]+wi[i];
                q.push({-dis[y],y});
            }
        }
    }
}
int main()
{
    scanf("%d %d %d",&n,&m,&s);
    for(register int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w);
    }
    dji();
    // cout<<0x3f3f3f3f3f<<endl;
    for(register int i=1;i<=n;i++)
    {
        if(dis[i]>INF)
            printf("-1\n");
        else printf("%lld\n",dis[i]);
    }
    return 0;
}
