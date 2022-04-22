<<<<<<< HEAD
// tarjan 算法求无向图的桥
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int SIZE = 100010;
int head[SIZE], ver[SIZE * 2], Next[SIZE * 2];
int dfn[SIZE], low[SIZE];
int n, m, tot, num;
bool bridge[SIZE * 2];
void add(int x, int y) {
    ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}
void tarjan(int x, int in_edge) {
    dfn[x] = low[x] = ++num;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (!dfn[y]) {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x])
                bridge[i] = bridge[i ^ 1] = true;
        }
        else if (i != (in_edge ^ 1))
            low[x] = min(low[x], dfn[y]);
    }
}

int main() {
    cin >> n >> m;
    tot = 1;
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i, 0);
    for (int i = 2; i < tot; i += 2)
        if (bridge[i])
            printf("%d %d\n", ver[i ^ 1], ver[i]);
=======
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
>>>>>>> 484b5dacbfe077f2dfbbda1b361fe732f39b1be0
}