//B题
#include<bits/stdc++.h>
using namespace std;
#define LL long long 
const int MAXN=200005;
const int p=998244353;
int n,m;
LL a[MAXN];
struct node
{
    int x,y;
    LL v,mul_laz,add_laz;
};
node t[MAXN<<2];
void push(int xx)
{
    int lc=xx<<1;
    int rc=(xx<<1)+1;
    if (t[xx].mul_laz!=1||t[xx].add_laz!=0)
    {
        t[lc].v=((t[lc].v*t[xx].mul_laz)%p+((t[lc].y-t[lc].x+1)*t[xx].add_laz)%p)%p;
        t[lc].mul_laz=(t[xx].mul_laz*t[lc].mul_laz)%p;
        t[lc].add_laz=(t[lc].add_laz*t[xx].mul_laz)%p+t[xx].add_laz; 
        t[lc].add_laz%=p;

        t[rc].v=((t[rc].v*t[xx].mul_laz)%p+((t[rc].y-t[rc].x+1)*t[xx].add_laz)%p)%p;
        t[rc].mul_laz=(t[xx].mul_laz*t[rc].mul_laz)%p;
        t[rc].add_laz=(t[rc].add_laz*t[xx].mul_laz)%p+t[xx].add_laz; 
        t[rc].add_laz%=p;

        t[xx].add_laz=0;
        t[xx].mul_laz=1;
    }
    return;
}

void build(int xx,int l,int r)
{
    t[xx].x=l;
    t[xx].y=r;
    t[xx].mul_laz=1; 
    t[xx].add_laz=0;
    if (l==r)
    {
        t[xx].v=a[l]%p;
        return;
    }
    int mid=(l+r)>>1;
    build(xx<<1,l,mid);
    build(xx<<1|1,mid+1,r);
    t[xx].v=t[xx<<1].v+t[(xx<<1)+1].v;
    t[xx].v%=p;
}

void add(int xx,int l,int r,int val)
{
    push(xx);
    if (t[xx].x>=l&&t[xx].y<=r)
    {
        t[xx].add_laz+=val; 
        t[xx].add_laz%=p;
        t[xx].v=(t[xx].v*t[xx].mul_laz%p+((t[xx].y-t[xx].x+1)*t[xx].add_laz)%p)%p;
        return;
    }
    int mid=(t[xx].x+t[xx].y)>>1;
    if (l<=mid) add(xx<<1,l,r,val);
    if (r>mid) add((xx<<1)+1,l,r,val);
    t[xx].v=t[xx<<1].v+t[(xx<<1)+1].v;
    t[xx].v%=p;
}

void mul(int xx,int l,int r,int val)
{
    push(xx);
    if (t[xx].x>=l&&t[xx].y<=r)
    {
        t[xx].mul_laz*=val; 
        t[xx].mul_laz%=p;
        t[xx].v=(t[xx].v*t[xx].mul_laz%p+((t[xx].y-t[xx].x+1)*t[xx].add_laz)%p)%p;
        return;
    }
    int mid=(t[xx].x+t[xx].y)>>1;
    if (l<=mid) mul(xx<<1,l,r,val);
    if (r>mid) mul((xx<<1)+1,l,r,val);
    t[xx].v=t[xx<<1].v+t[(xx<<1)+1].v;
    t[xx].v%=p;
}

LL ask(int xx,int l,int r)
{
    push(xx);
    if (t[xx].x>=l&&t[xx].y<=r)
        return t[xx].v%p;
    LL ans=0;
    int mid=(t[xx].x+t[xx].y)>>1;
    if (l<=mid) ans+=ask(xx<<1,l,r);
    if (r>mid) ans+=ask((xx<<1)+1,l,r);
    return ans%p;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(1,1,n);
    int opt=0,l=0,r=0,k=0;
    while(m--)
    {
        scanf("%d",&opt);
        if(opt==1)
        {
            scanf("%d %d %d",&l,&r,&k);
            // cout<<l<<" "<<r<<" "<<k<<endl;
            mul(1,l,r,k);
        }
        else if(opt==2)
        {
            scanf("%d %d %d",&l,&r,&k);
            // cout<<l<<" "<<r<<" "<<k<<endl;
            add(1,l,r,k);
        }
        else if(opt==3)
        {
            scanf("%d %d",&l,&r);
            // cout<<l<<" "<<r<<endl;
            LL ans =ask(1,l,r);
            printf("%lld\n",ans%p);
        }
    }
}