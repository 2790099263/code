#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int n,m;
int main()
{
    scanf("%d %d",&n,&m);
    int x=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        v.push_back(x);
    }
    int opt=0,pos=0,k=0;
    while(m--)
    {
        scanf("%d",&opt);
        if(opt==1)
        {
            scanf("%d %d",&k,&pos);
            if(pos>v.size())
            {
                v.push_back(k);
            }
            else v.insert(v.begin()+pos-1,k);
        }
        else{
            scanf("%d",&pos);
            printf("%d\n",v[pos-1]);
        }
        // cout<<"test";
        // for(auto i=v.begin();i!=v.end();i++)
        //     cout<<*i<<" ";cout<<endl;
    }
    return 0;
}