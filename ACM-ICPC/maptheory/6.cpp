#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int head[MAXN],ver[MAXN],nxt[MAXN],vx[MAXN],tot;
int dfn[MAXN],low[MAXN],cnt;
int ans1,ans2,ans3,ans4;
int n,m;
inline void add(int x,int y)
{
    ver[++tot]=y;vx[tot]=x;nxt[tot]=head[x];head[x]=tot;
}
int root;
bool flag[MAXN];
vector<pair<int,int> > bridge;
void Tarjan(int x,int father)
{
    int child = 0;
    dfn[x]=low[x]=++tot;
    for(int i=head[x];i;i=nxt[i])
    {
        int v =ver[i];
        if(!dfn[v])
        {
            child ++;
            Tarjan(v,x);
            low[x] = min(low[x],low[v]);
            if(x != root && dfn[x] <= low[v]) flag[x] = 1;    //表示当前节点为割点
            if(x == root  && child == 2) flag[x] = 1;
            if(low[v] > dfn[x]) {bridge.push_back(make_pair(x,v));ans2++;}
        }
        else if(v != father)
            low[x] = min(dfn[v],low[x]);
    }
}
int cut[MAXN];
int id,t;
int zhan[MAXN],belong[MAXN];
set<int> s[MAXN];//记录每个点双包含哪些点，如果题目不需要也可以不求
void dfs2(int x,int from)
{
	dfn[x]=low[x]=++id; int son=0;
	for(int i=head[x];i;i=nxt[i])
	{
		if(i==(from^1))continue;
		int y=ver[i];
		if(!dfn[y])
		{
			zhan[++t]=i; dfs2(y,i); son++;//先压栈再遍历
			if(low[y]<low[x])low[x]=low[y];
			if(low[y]>=dfn[x])//发现x是割点
			{
				cnt++;cut[x]=true;int xx=0;
                ans4=max(ans4,t);
				do{
					xx=zhan[t--];//弹出
					belong[vx[xx]]=belong[ver[xx]]=cnt;//标记
					s[cnt].insert(vx[xx]);s[cnt].insert(ver[xx]);//记录
				}while(vx[xx]!=x||ver[xx]!=y);
			}
		}
		else if(dfn[y]<low[x])low[x]=dfn[y];
	}
	if(from==-1&&son==1)cut[x]=false;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        add(x,y),add(y,x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
        {
            root=i;
            Tarjan(i,-1);
        }
    }
    ans2/=2;
    for(int i=1;i<=n;i++)
    {
        if(cut[i]==1)ans1++;
    }
    memset(cut,0,sizeof(cut));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
            dfs2(i,0);
    }
    cout<<ans1<<" "<<ans2<<" "<<cnt<<" "<<ans4<<endl;
    return 0;
}