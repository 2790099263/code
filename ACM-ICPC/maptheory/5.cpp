#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
int dis[MAXN];
int head[MAXN],ver[MAXN],nxt[MAXN],wi[MAXN],tot;
inline void add(int x,int y,int z){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;wi[tot]=z;}
char mp[505][505];
int n,m;
inline void dj()
{
    priority_queue<pair<int,int>>q;
    dis[1]=0;
    q.push({0,1});
    while(q.size())
    {
        int x=q.top().second;int v=q.top().first;
        q.pop();
        // cout<<x<<endl;
        if(dis[x]<-v)continue;
        for(int i=head[x];i;i=nxt[i])
        {
            int y=ver[i];
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
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",mp[i]+1);
    memset(dis,0x3f3f3f,sizeof(dis));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]=='/')
            {
                add(i*(m+1)+j,(i-1)*(m+1)+j+1,0);
                add((i-1)*(m+1)+j+1,i*(m+1)+j,0);
                add((i-1)*(m+1)+j,i*(m+1)+j+1,1);
                add(i*(m+1)+j+1,(i-1)*(m+1)+j,1);
            }
            else{
                add(i*(m+1)+j,(i-1)*(m+1)+j+1,1);
                add((i-1)*(m+1)+j+1,i*(m+1)+j,1);
                add((i-1)*(m+1)+j,i*(m+1)+j+1,0);
                add(i*(m+1)+j+1,(i-1)*(m+1)+j,0);
            }
        }
    }
    dj();
    if(dis[(n+1)*(m+1)]>500000)cout<<"NO SOLUTION"<<endl;
    else cout<<dis[(n+1)*(m+1)]<<endl;
    return 0;
}