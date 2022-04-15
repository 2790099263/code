#include <bits/stdc++.h>
using namespace std;
int a,b;
int main()
{
	cin>>a>>b;
	int l=1,r=1000;
	while(l<r)
	{
		int mid=(l+r)>>1;
		cout<<l<<" "<<r<<" "<<mid<<endl;
		if((a+b)>mid)l=mid+1;
		else r=mid;
	}
	cout<<l<<endl;
	return 0;
}
