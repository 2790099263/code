#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=100005;
struct query{
    int x,y,z,k;
}q[MAXN];
int n,m,a[MAXN];
int li[MAXN],top;
inline int getid(int x){return lower_bound(li+1,li+top+1,x)-li-1;}
struct node{
    int z;
    node *lef,*rig;
    node():z(0),lef(NULL),rig(NULL){}
};
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        li[top++]=a[i];
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&q[i].x,&q[i].y,&q[i].z);
        if(q[i].x!=3)
        {
            scanf("%d",&q[i].k);
            li[++top]=q[i].k;
        }
        else li[++top]=q[i].z;
    }
    sort(li+1,li+top+1);
    top=unique(li+1,li+top+1)-li-1;
    // for(int i=1;i<=n;i++)cout<<getid(a[i])<<" ";cout<<endl;
    return 0;
}