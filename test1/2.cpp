#include<bits/stdc++.h>
using namespace std;
int n,m;
int dp[1005][1005];
int main()
{
    cin>>n>>m;
    //数n，分成m份
    for(int i=0;i<=n;i++)dp[0][i]=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=n;j>=0;j--)
        {
            for(int k=n;k>j;k--)
            dp[i][j]=max(dp[i][j],dp[i-1][k]*(k-j));
        }
    }
    int ans=0;
    printf("%d\n",dp[m][0]);
    return 0;
}