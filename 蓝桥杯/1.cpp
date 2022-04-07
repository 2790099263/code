// 蓝桥杯第十二届 双向排序A
// 单调队列
// 有问题的方案
#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;
struct node
{
	int p,q;
}qer[MAXN],que[MAXN];//单调队列 
int tot=0;
int a[MAXN];
void push(node a)
{
	while(tot&&a.q<=que[tot].q)
	{
		tot--;
	}
	que[++tot]=a;
	return ;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>qer[i].p>>qer[i].q;
		//p=0降序p=1升序
		push(qer[i]);
	}
	que[0].p=1;
	que[0].q=1;
	que[++tot].p=1;
	que[tot].q=n;
	int l=1,r=n;
	for(int i=0;i<=tot;i++)
	{
		if(que[i].p==1)
		{
			for(int j=que[i].q;j<que[i+1].q;j++)
			{
				a[j]=l;
				l++;
			}
		}
		else{
			for(int j=que[i].q;j<=que[i+1].q;j++)
			{
				a[j]=r;
				r--;
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;
} 
