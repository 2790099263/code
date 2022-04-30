#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=100005;
const int INF=1000000007;
struct query{
    int x,y,z,k;
}q[MAXN];
int n,m,a[MAXN];
int li[MAXN],top;
inline int getid(int x){return lower_bound(li+1,li+top+1,x)-li;}
inline int lowbit(int x){return x&(-x);}
struct node
{
    int z;
    node *lef,*rig;
    node():z(0),lef(NULL),rig(NULL){}
};
node *root[MAXN];
void change(node* &now,int l,int r,int k,int v)
{
    if(now==NULL)now=new node();
    now->z+=v;
    if(l==r)return ;
    int mid=(l+r)>>1;
    if(k<=mid)change(now->lef,l,mid,k,v);
    else change(now->rig,mid+1,r,k,v);
    return ;
}
int sum(node *now,int l,int r,int x,int y)
{
    if(now==NULL)return 0;
    if(l==x&&r==y)return now->z;
    int mid=(l+r)>>1;
    if(y<=mid)return sum(now->lef,l,mid,x,y);
    return sum(now->rig,mid+1,r,x,y);
}
int getsum(int x,int y,int l,int r)
{
    int res=0;
    for(int i=y;i>0;i-=lowbit(i))res+=sum(root[i],1,top,l,r);
    for(int i=x;i>0;i-=lowbit(i))res-=sum(root[i],1,top,l,r);
    return res;
}
int query(int x,int y,int l,int r,int z)
{
    if(l==r)return 1;
    int mid=(l+r)>>1;
    if(z<=mid)return query(x,y,l,mid,z);
    return getsum(x,y,l,mid)+query(x,y,mid+1,r,z);
}
int ask(int x,int y,int l,int r,int z)
{
    if(l==r)return l;
    int mid=(l+r)>>1;
    int te=getsum(x,y,l,mid);
    if(z<=te)return ask(x,y,l,mid,z);
    return ask(x,y,mid+1,r,z-te);
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        li[++top]=a[i];
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&q[i].x,&q[i].y,&q[i].z);
        if(q[i].x!=3)
        {
            scanf("%d",&q[i].k);
            if(q[i].x==1)li[++top]=q[i].k;
        }
        else li[++top]=q[i].z;
    }
    sort(li+1,li+top+1);
    top=unique(li+1,li+top+1)-li-1;
    // for(int i=1;i<=n;i++)cout<<getid(a[i])<<" ";cout<<endl;
    li[top+1]=-INF;
    li[top+2]=INF;
    for(int i=1;i<=n;i++)
    {
        int res=getid(a[i]);
        for(int j=i;j<=n;j+=lowbit(j))
            change(root[j],1,top,res,1);
    }
    for(int i=1;i<=m;i++)
    {
        if(q[i].x==1)
        {
            printf("%d\n",query(q[i].y-1,q[i].z,1,top,getid(q[i].k))-1);
        }
        else if(q[i].x==2)
        {
            printf("%d\n",li[ask(q[i].y-1,q[i].z,1,top,q[i].k)]);
        }
        else 
        {
            int res=getid(a[q[i].y]);
            for(int j=q[i].y;j<=n;j+=lowbit(j))
                change(root[j],1,top,res,-1);
            a[q[i].y]=q[i].z;
            res=getid(q[i].z);
            for(int j=q[i].y;j<=n;j+=lowbit(j))
                change(root[j],1,top,res,1);

        }
    }
    return 0;
}