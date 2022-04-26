//树套树模板
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=1e5+20;
int n,m,a[N];
int b[N],cb;
struct Node{
    int id,x,y,z;
}q[N];
struct node{
    int z;
    node *zuo,*you;
    node():z(0),zuo(NULL),you(NULL){}
};
node *root[N];

int lowbit(int x){return x&(-x);}
void change(node *&now,int l,int r,int k,int v)
{
    if(now==NULL)now=new node();
    now->z+=v;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(k<=mid)change(now->zuo,l,mid,k,v);
    else change(now->you,mid+1,r,k,v);
    return;
}
int sum(node *now,int l,int r,int x,int y)
{
    if(now==NULL)return 0;
    if(l==x&&r==y)return now->z;
    int mid=(l+r)>>1;
    if(y<=mid)return sum(now->zuo,l,mid,x,y);
    return sum(now->you,mid+1,r,x,y);
}
//得到位置区间[x,y]，数值区间[l,r]的区间和
int getsum(int x,int y,int l,int r)
{
    int re=0;
    for(int i=y;i>0;i-=lowbit(i))
        re+=sum(root[i],1,cb,l,r);
    for(int i=x;i>0;i-=lowbit(i))
        re-=sum(root[i],1,cb,l,r);
    return re;
}
//返回位置区间[x,y]，数值区间[l,r]内，排名第z的数值
int ask(int x,int y,int l,int r,int z)
{
    if(l==r)
        return l;
    int mid=(l+r)>>1;
    int te=getsum(x,y,l,mid);
    if(z<=te)
        return ask(x,y,l,mid,z);
    return ask(x,y,mid+1,r,z-te);
}
//返回位置区间[x,y]，数值区间[l,r]内，数值z的排名
int query(int x,int y,int l,int r,int z)
{
    if(l==r)
        return 1;
    int mid=(l+r)>>1;
    if(z<=mid)
        return query(x,y,l,mid,z);
    return getsum(x,y,l,mid)+query(x,y,mid+1,r,z);
}
//返回位置区间[x,y]内数值z的前驱
int pre(int x,int y,int z)
{
    int rank=query(x,y,1,cb,z);
    rank--;//无论原区间含不含z，rank-1都会是他前驱，除非z自身为极小值
    if(!rank)return cb+1;
    return ask(x,y,1,cb,rank);
}
//返回位置区间[x,y]内数值z的后继
int nxt(int x,int y,int z)
{
    int rank=query(x,y,1,cb,z);
    if(rank==y-x+1)return cb+2;//z本身都放不下了，更别说后继了
    if(ask(x,y,1,cb,rank)==z)rank++;//需要判断原区间含不含z
    if(rank==y-x+1)return cb+2;//z本身是此区间内的极值，无更大值
    return ask(x,y,1,cb,rank);
}
//用于离散
int getid(int x)
{
    return lower_bound(b+1,b+cb+1,x)-b;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[++cb]=a[i];
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&q[i].id,&q[i].x,&q[i].y);
        if(q[i].id!=3)
        {
            scanf("%d",&q[i].z);
            if(q[i].id!=2)
                b[++cb]=q[i].z;
        }
        else
            b[++cb]=q[i].y;
    }
    //离散
    sort(b+1,b+cb+1);
    cb=unique(b+1,b+cb+1)-b-1;
    //处理不存在的情况
    b[cb+1]=-2147483647;
    b[cb+2]=2147483647;
    //建初始树
    for(int i=1;i<=n;i++)
    {
        int te=getid(a[i]);
        for(int j=i;j<=n;j+=lowbit(j))
            change(root[j],1,cb,te,1);
    }
    //操作
    for(int i=0;i<m;i++)
    {
        int x=q[i].x,y=q[i].y,z=q[i].z,te;
        switch(q[i].id)
        {
            case 1:
                printf("%d\n",query(x-1,y,1,cb,getid(z)));//直接输出排名，不必数组b映射
                break;
            case 2:
                printf("%d\n",b[ask(x-1,y,1,cb,z)]);//此处z是排名，不getid
                break;
            case 3:
                te=getid(a[x]);
                for(int i=x;i<=n;i+=lowbit(i))
                    change(root[i],1,cb,te,-1);
                a[x]=y;
                te=getid(a[x]);
                for(int i=x;i<=n;i+=lowbit(i))
                    change(root[i],1,cb,te,1);
                break;
        }
    }
    return 0;
}