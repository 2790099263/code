#include <iostream>
#include <cstdio>
using namespace std;
int T;
int n;
char mp[50][50];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>mp[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=n;j>=1;j--)
            {
                cout<<mp[j][i];
            }
            cout<<endl;
        }
    }
    return 0;
}