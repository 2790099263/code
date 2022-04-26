# O题题解

图图星球的晚晚国的公主阿晚一袭红衣坐在沙丘上，盼着与她少年时期定下十年之约的王子，可终究，没能等到他。既然等不到，那就去找他吧。图图星球上所有的国家都由非负权值的有向道路相互连接，该星球上没有远程通讯功能。阿晚记性很差，她不记得王子是哪个国家的了，但她手上有半块王子留下的玉佩。因此她决定派使臣们去每个国家问一问这是哪个王子留下的半块玉佩。现在她需要知道其他所有国家到晚晚国的最短距离，以便安排使臣们的行程。
如果晚晚国不能到达第 i*i* 个国家，则第 i*i* 行输出 -1−1。

## Standard Input

第一行为三个正整数 n*n*，m*m*，s*s*，分别表示共有 n*n* 个国家，m*m* 条道路，晚晚国位于编号 s*s*。
第二行起 m*m* 行，每行三个非负整数 u_i*u**i*​，v_i*v**i*​，w_i*w**i*​，表示从编号为 u_i*u**i*​ 的国家到编号为 v_i*v**i*​ 的国家有一条权值为 w_i*w**i*​ 的有向道路。

## Standard Output

输出 n*n* 行整数，每行有且只有一个数。第 i*i* 行表示晚晚国 s*s* 到编号为 i*i* 的国家的最短距离。

## Samples

| Input                                       | Output     |
| ------------------------------------------- | ---------- |
| `4 6 1 1 2 2 2 3 4 2 4 5 1 3 1 3 4 2 1 4 4` | `0  2 1 3` |

## Constraints

1 \leq n \leq 10^51≤*n*≤105；

1 \leq m \leq 2\times 10^51≤*m*≤2×105；

1 \leq s \leq n1≤*s*≤*n*；

1 \leq u_i, v_i\leq n1≤*u**i*,*v**i*≤*n*；

0 \leq w_i \leq 10 ^ 90≤*w**i*≤109,

| Problem ID    | 2730                               |
| ------------- | ---------------------------------- |
| Problem Title | 纯白色的少年郎，如今只身在何方     |
| Time Limit    | 1000 ms                            |
| Memory Limit  | 64 MiB                             |
| Output Limit  | 64 MiB                             |
| Source        | 2022 UESTC ICPC Training for Graph |

## 题解：

个人认为这个题不需要题解，就是罗的迪杰斯特拉板子题，如果距离仍为无穷大，那么就输出-1

注意特判松弛条件，我就是松弛条件没判断好TLE了几次

## 代码

```c++
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
```

