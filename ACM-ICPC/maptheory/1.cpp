//![](https://raw.githubusercontent.com/2790099263/tuchuang/master/20220415111133.png)
//K居民们都住在房屋里
#include <bits/stdc++.h>
using namespace std;
int n,m;
const int MAXN=1000005;
int head[MAXN],ver[MAXN],nxt[MAXN],tot;
int qx[MAXN],qy[MAXN],cnt;
int dis[MAXN];
int fa[MAXN][30],deep[MAXN];
bool vis[MAXN];
int pw[30];
inline void add(int x,int y)
{
    ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
void dfs(int x,int f)
{
    vis[x]=1;
    fa[x][0]=f;
    deep[x]=deep[f]+1;
    for(int i=1;pw[i]<=deep[x];i++)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=head[x];i;i=nxt[i])
    {
        int y=ver[i];
        if(vis[y]==1)continue;
        if(y==f)continue;
        dfs(y,x);
    }
    vis[x]=0;
}
inline int LCA(int x,int y)
{
    if(deep[x]>deep[y])swap(x,y);
    for(int i=25;i>=0;i--)
    {
        if(!fa[y][i])continue;
        if(deep[fa[y][i]]>=deep[x])
        {
            y=fa[y][i];
        }
    }
    // cout<<" x  y  "<<x<<" "<<y<<endl;
    if(x==y)return x;
    for(int i=25;i>=0;i--)
    {
        if(!fa[x][i])continue;
        if(!fa[y][i])continue;
        if(fa[x][i]!=fa[y][i])
        {
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}
int main()
{
    scanf("%d %d",&n,&m);
    pw[0]=1;
    for(int i=1;i<=29;i++)
        pw[i]=pw[i-1]<<1;
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        add(x,y);add(y,x);
    }
    deep[1]=1;
    dfs(1,1);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        int lca=LCA(x,y);
        // cout<<"lca "<<lca<<endl;
        printf("%d\n",deep[x]-deep[lca]+deep[y]-deep[lca]);
    }
    return 0;
}