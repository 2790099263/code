#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN=1005;
struct node{
    int wight,price;
}obj[MAXN];
bool sort_obj(node a,node b)
{
    if(a.wight==b.wight)return a.price>b.price;
    else return a.wight<b.wight;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            cin>>obj[i].wight;
        for(int i=1;i<=n;i++)
            cin>>obj[i].price;
        sort(obj+1,obj+n+1,sort_obj);
        cout<<"result:"<<endl;
        for(int i=1;i<=n;i++)
            cout<<obj[i].wight<<" "<<obj[i].price<<endl;
    }
    return 0;
}