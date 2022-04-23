//A题ac代码
//网络流最小割最大流问题
//StoerWagner算法
#include <bits/stdc++.h>
using namespace std;
const int MAXN=505;
const int INF=1e9;
int mp[MAXN][MAXN];
int vis[MAXN];
int dis[MAXN],part[MAXN];
int N;
int run(int x)
{
    int ret=INF;
    for(int i=0;i<x;i++) part[i]=i;
    while(x>1)
    {
        int pre=0;
        for(int i=0;i<=N;i++) vis[i]=dis[i]=0;
        for(int i=1;i<x;i++)
        {
            int k=-1;
            for(int j=1;j<x;j++)
            {
                if(vis[part[j]])continue;
                dis[part[j]]+=mp[part[pre]][part[j]];
                if(k==-1||dis[part[j]]>dis[part[k]]) 
                    k=j;
            }
            vis[part[k]]=1;
            if(i==x-1){
                int s=part[pre],t=part[k];
                if(ret>dis[t]&&dis[t])
                    ret=dis[t];
                for(int j=0;j<x;j++)
                {
                    mp[s][part[j]]+=mp[t][part[j]];
                    mp[part[j]][s]+=mp[t][part[j]];
                }
                part[k]=part[--x];
            }
            pre=k;
        }
    }
    return ret;
}
int main()
{
    int m=0,n=0;
    scanf("%d %d",&n,&m);N=n;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d %d",&u,&v);
        mp[u][v]++;
        mp[v][u]++;
    }
    int ans=run(n);
    cout<<ans<<endl;
    return 0;
}