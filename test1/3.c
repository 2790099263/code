#include<stdio.h>
int n,m;
int dp[1005][1005];
int s[1005][1005];
int max(int a,int b){return a>b?a:b;}
int main()
{
    scanf("%d %d",&n,&m);
    //数n，分成m份
    for(int i=0;i<=n;i++)dp[0][i]=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=n;j>=0;j--)
        {
            for(int k=n;k>j;k--)
            if(dp[i-1][k]*(k-j)>=dp[i][j])
            {
                dp[i][j]=dp[i-1][k]*(k-j);
                s[i][j]=k-j;
            }
        }
    }
    int ans=0;
    printf("%d\n",dp[m][0]);
    int sum=0;
    for(int i=m;i>=1;i--)
    {
        printf("%d ",s[i][sum]);
        sum+=s[i][sum];
    }
    return 0;
}