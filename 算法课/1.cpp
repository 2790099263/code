#include <bits/stdc++.h>
using namespace std;
int a[10];
//记录第i个♂匹配哪个♀；
bool v[10];
//标记第i个数字有没有被用过
int ans1,ans2;  
//ans1是所有可能的情况有多少种；ans2是符合题意的情况有多少种
inline bool check()
{
    //check函数如果不符合题意就return 0;否则return1；
    for(int i=1;i<=5;i++)
    {
        if(a[i]==i)return 0;
    }
    return 1;
}
void dfs(int pos)
{
    if(pos==6)//pos==6时候搜索结束
    {
        ans1++;//总情况数目加一
        if(check())ans2++;//合法情况数目加一
        return ;//到达了搜索边界，回溯
    }
    for(int i=1;i<=5;i++)
    {
        if(v[i])continue;
        a[pos]=i;v[i]=1;//这个数字被使用了，v=1；
        dfs(pos+1);
        a[pos]=0;v[i]=0;//回溯之后这个数字应当被释放，v=0
    }
}
int main()
{
    dfs(1);
    double ans=(double)ans2/(double)ans1;
    cout<<ans<<endl;
    return 0;
}