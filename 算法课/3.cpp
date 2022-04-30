#include <bits/stdc++.h>
using namespace std;
int n;
bool a[100005];
int main()
{
    cin>>n;

    if(n%2==0)cout<<"tan90"<<endl;
    int pos=0;
    for(int i=1;i<=n;i++)a[(pos+i)%n]=1,pos=(pos+i)%n;
    for(int i=0;i<n;i++)if(!a[i])cout<<(i==0?n:i)<<" ";cout<<endl;
    return 0;
}