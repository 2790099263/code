//created by lsc 20220426 16:59
//无注释版本
#include <bits/stdc++.h>
using namespace std;
int a[10];
bool v[10];
int ans1,ans2;  
inline bool check()
{
    for(int i=1;i<=5;i++)if(a[i]==i)return 0;
    return 1;
}
void dfs(int pos)
{
    if(pos==6)
    {
        check()?ans2++:1;
        ans1++;
        return ;
    }
    for(int i=1;i<=5;i++)
    {
        if(v[i])continue;
        a[pos]=i;v[i]=1;
        dfs(pos+1);
        a[pos]=0;v[i]=0;
    }
}
int main()
{
    dfs(1);
    double ans=(double)ans2/(double)ans1;
    cout<<ans<<endl;
    return 0;
}