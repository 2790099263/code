#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int a[MAXN];
int n,m;
bool q_0(int A,int B){return A<B;}
bool q_1(int A,int B){return A>B;}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)a[i]=i;
    for(int i=1;i<=m;i++)
    {
        int A,B;
        cin>>A>>B;
        if(A==0)
        {
            // cout<<"1111111"<<endl;
            sort(a+1,a+B+1,q_1);
        }
        else 
        {
            // cout<<"00000"<<endl;
            sort(a+B,a+n+1,q_0);
            // cout<<a+B+1<<" "<<a+n+1<<endl;
        }
        // for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    // cout<<endl;
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}