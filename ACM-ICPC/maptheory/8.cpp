//J题
// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
#define MAXN 2000005
int head[MAXN],ver[MAXN],nxt[MAXN],tot=1;
inline void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
int dfn[MAXN],low[MAXN],num;
bool bridge[MAXN];
int n,m;
int ans1,ans2,ans4;
void tarjan(int x,int  in_edge)
{
	dfn[x]=low[x]=++num;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(!dfn[y])
		{
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(low[y]>dfn[x])
				bridge[i]=bridge[i^1]=1;
		}
		else if(i!=(in_edge^1))
		{
			low[x]=min(low[x],dfn[y]);
		}
	}
}

int root;
bool cut[MAXN];
void tarjan2(int x)
{
	dfn[x]=low[x]=++num;
	int flag=0;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(!dfn[y])
		{
			tarjan2(y);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x])
			{
				flag++;
				if(x!=root||flag>1)cut[x]=1;
			}
		}
		else low[x]=min(low[x],dfn[y]);
	}
}
int sta[MAXN],top,cnt;
vector<int>dcc[MAXN];
void tarjan3(int x)
{
	dfn[x]=low[x]=++num;
	sta[++top]=x;
	if(x==root&&head[x]==0)
	{
		// dcc[++cnt].push_back(x);
		return ;
	}
	int flag=0;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(!dfn[y])
		{
			tarjan3(y);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x])
			{
				flag++;
				if(x!=root||flag>1)cut[x]=1;
				cnt++;
				int z;
				do{
					z=sta[top--];
					dcc[cnt].push_back(z);
				}while(z!=y);
				dcc[cnt].push_back(x);
			}
		}
		else low[x]=min(low[x],dfn[y]);
	}
}
bool vis[MAXN],is_dcc[MAXN];
int edge_cnt;
void dfs(int x) {
		vis[x] = 1;
		for(int i=head[x];i;i=nxt[i]) 
        {
			int v=ver[i];
			if (!is_dcc[v]) continue;
			++edge_cnt;
			if (!vis[v])
				dfs(v);
		}
	}
int belong[MAXN],res[MAXN];
int main()
{
	// freopen("run.in","r",stdin);
	// freopen("opt.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        add(x,y),add(y,x);
    }
	num=0;
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
			tarjan(i,0);
	}
	for(int i=2;i<tot;i+=2)
	{
		if(bridge[i])
		{
			// printf("%d %d\n",ver[i^1],ver[i]);
			ans2++;//求割边
		}
	}
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	num=0;ans1=0;
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i]){
			root=i;
			tarjan2(i);
		}
	}
	// int rs1=0;
	for(int i=1;i<=n;i++)
	{
		// if(cut[i])cout<<"gedian   "<<i<<endl;
		if(cut[i])ans1++;
	}
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(cut,0,sizeof(cut));
	num=0;top=0;cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		{
			root=i;
			tarjan3(i);
		}
	}
    int x;
	for (int i = 1; i <= cnt; ++i) 
    {
		for (int j = 0; j < dcc[i].size(); ++j) 
        {
			x = dcc[i][j];
			is_dcc[x] = 1;
		}
		x = dcc[i][0];
		edge_cnt = 0;
		dfs(x);
		ans4 = max(ans4, edge_cnt/2);
		for (int j = 0; j < dcc[i].size(); ++j) {
			x = dcc[i][j];
			is_dcc[x] = vis[x] = 0;
		}
	}
	cout<<ans1<<" "<<ans2<<" "<<cnt<<" "<<ans4<<endl;
}