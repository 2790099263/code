#include <bits/stdc++.h>
using namespace std;
const int MAXN=20005;
queue<int>q;
bool flag=0;
int n,m;
int ver[MAXN],nxt[MAXN],head[MAXN],wi[MAXN],tot;
int sum[MAXN],dis[MAXN],vis[MAXN];
inline void add(int x,int y,int z){ver[++tot]=y;wi[tot]=z;nxt[tot]=head[x];head[x]=tot;}
void spfa(int x)
{
    
    memset(vis,0,sizeof(vis));
    memset(sum,0,sizeof(sum));
    while(q.size())q.pop();
    sum[x]=1;
    dis[x]=0;
    q.push(x);
    while(q.size())
    {
        int k=q.front();q.pop();
        vis[k]=0;
        for(int i=head[k];i;i=nxt[i])
        {
            int y=ver[i];
            if(dis[k]+wi[i]<dis[y])
            {
                dis[y]=dis[k]+wi[i];
                sum[y]=sum[k]+1;
                if(sum[y]>n)
                {
                    flag=1;
                    return ;
                }
                if(!vis[y])
                {
                    q.push(y);
                    vis[y]=1;
                }
            }
        }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w);
    }
    memset(dis,0x3f3f3f,sizeof(dis));
    flag=0;
    for(int i=1;i<=n;i++)
        if(dis[i]>60000000)spfa(i);
    // for(int i=1;i<=n;i++)cout<<dis[i]<<" ";cout<<endl;
    if(flag==1)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}