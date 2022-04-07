// 线段树，普通
// 建树，单点修改，区间查询
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
const int MAXN=100005;
int L[MAXN],R[MAXN],p[MAXN],a[MAXN],laz[MAXN];
int max(int A,int B){return A>B?A:B;}
void down(int x)
{
    laz[x<<1]=laz[x<<1|1]=laz[x];
    laz[x]=0;
}
void build(int x,int l,int r)
{
    L[x]=l,R[x]=r;laz[x]=0;
    if(l==r){
        p[x]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    p[x]=max(p[x<<1],p[x<<1|1]);
    return ;
}
void change(int x,int pos,int v)
{
    if(L[x]==R[x])
    {
        p[x]=v;
        return ;
    }
    int l=L[x],r=R[x];
    int mid=(l+r)>>1;
    down(x);
    if(pos>=l&&pos<=mid)change(x<<1,pos,v);
    else change(x<<1|1,pos,v);
    p[x]=max(p[x<<1],p[x<<1|1]);
    return ;
}
int query(int x,int queryl,int queryr)
{
    if(L[x]>=queryl&&R[x]<=queryr)return p[x];
    int mid=(L[x]+R[x])>>1;
    int val=0;
    down(x);
    if(queryl<=mid)val=max(query(x<<1,queryl,queryr),val);
    if(queryr>=mid+1)val=max(query(x<<1|1,queryl,queryr),val);
    p[x]=val;
    return val;
}
void changeLR(int x,int l,int r,int v)
{
    if(L[x]>=l&&R[x]<=r)
    {
        laz[x]+=v;
        return ;
    }
    down(x);
    int mid=(l+r)>>1;
    int val=0;
    if(l<=mid)changeLR(x<<1,l,mid,v);
    if(r>=mid+1)changeLR(x<<1|1,mid+1,r,v);
    p[x]=max(p[x<<1],p[x<<1|1]);
    return ;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    return 0;
}