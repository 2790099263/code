#include <iostream>
#include <cstdio>
using namespace std;
int T,n,m;
int f[10005];
int main()
{
    cin>>T;
	while (T--) {
		cin>>m>>n;
		f[1]=0;
        for(int i=2;i<=m;i++)
        {
            f[i]=(f[i-1]+n)%i;
        }
        printf("%d\n",f[m]+1);
	}
    return 0;
}
