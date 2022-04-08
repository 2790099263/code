#include <bits/stdc++.h>
using namespace std;
const int MAXN=10005;
int ver[MAXN],nxt[MAXN],head[MAXN],tot;
int dis[MAXN];
bool v[MAXN];
inline void add (int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
priority_queue<pair<int,int>>q;
void dji()
{
    memset(dis,0x3f,sizeof(dis));
    memset(v,0,sizeof(v));
    dis[1]=0;
    q.push({0,1});
    while(!q.empty())
    {
        int x=q.top().second;
        q.pop();
        for(int i=head[x];i;i=nxt[i])
        {
            int y=ver[i];
            if(dis[y]>=dis[x]+1)
            {
                dis[y]=dis[x]+1;
                q.push({-dis[y],y});
            }
        }
    }
    return ;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dji();
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" ";
    cout<<endl;
    return 0;
}