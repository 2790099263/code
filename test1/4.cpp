#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int T,n;
int mp[50][50];
int main() 
{
	cin>>T;
	while(T--) 
    {
		cin>>n;
		memset(mp,0,sizeof(mp));
		int x=0,y=n,num=0,number=n*n;
		while(1)
        {
			while (x<n&&!mp[x + 1][y]&&num<number)mp[++x][y]=++num;
			while (y>1&&!mp[x][y - 1]&&num<number)mp[x][--y]=++num;
			while (x>1&&!mp[x - 1][y]&&num<number)mp[--x][y] = ++num;
			while (y<n&&!mp[x][y + 1]&&num<number)mp[x][++y] = ++num;
			if (num == number) break;
		}
		for(int i=1;i<=n;i++) 
        {
			for(int j=1;j<=n;j++)
				printf("%4d",mp[i][j]);
			putchar('\n');
		}
	}
	return 0;
}