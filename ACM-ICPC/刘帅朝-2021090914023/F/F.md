# F题题解

## 题目

今天 div2 开会，但 F_know 又睡过头了，于是问 stc 会上讲了啥。

stc 说今天总共讲了 n*n* 件事，每件事都有一个重要度，第 i*i* 件事的重要度为一个整数 a_i*a**i*。但 stc 记不清 a_i*a**i* 具体为多少了，他只记得 m*m* 个约束条件，第 j*j* 个约束条件有三个整数 u,v,w*u*,*v*,*w*，表示 a_u-a_v\le w*a**u*−*a**v*≤*w*。

请判断是否至少存在一组 a*a* 的值满足上述条件。

## Standard Input

第一行有两个整数 n,m*n*,*m*（1\le n,m \le 5\times 10^31≤*n*,*m*≤5×103）
接下来 m*m* 行每行三个整数 u,v,w*u*,*v*,*w*（1\le u,v\le n1≤*u*,*v*≤*n*，-10^4\le w\le 10^4−104≤*w*≤104）

## Standard Output

如果 a*a* 有解，输出 YES，否则输出 NO。

## Samples

| Input                    | Output |
| ------------------------ | ------ |
| `3 3 1 2 3 2 3 -2 1 3 1` | `YES`  |

| Problem ID    | 2714                               |
| ------------- | ---------------------------------- |
| Problem Title | 开会了                             |
| Time Limit    | 1000 ms                            |
| Memory Limit  | 64 MiB                             |
| Output Limit  | 64 MiB                             |
| Source        | 2022 UESTC ICPC Training for Graph |

## 题解

条件提取：

n个事情，m个限制，问是否有满足这个限制的${a_1,a_2,a_3...a_n}$成立的可能性。

分析：

根据每一个限制条件来说：$a_i-a_j\le w_k$ 

那么我们可以从$i$连到$j$一条边：即

![image-20220423160633622](https://raw.githubusercontent.com/2790099263/tuchuang/master/image-20220423160633622.png)

但是我们很容易想到会有环的情况出现，这也是可能出现不合法的情况。如下图所示

![image-20220423160512688](https://raw.githubusercontent.com/2790099263/tuchuang/master/image-20220423160512688.png) 

当我们手膜几个样例可以发现，题目中情况不合法当且仅当出现环并且这个环上的所有边的和是负数，我们就可以断定此时是非法情况，那么我们来考虑算法设计：

我们知道spfa在出现负环的时候会出现无限循环的现象，所以我们可以利用spfa的特性来设计spfa来判断负环的算法。

那么我们在spfa的算法中加入特判即可判断负环

## 代码

```c++
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
```



