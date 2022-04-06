#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
int T,n,m;
int t[1000005];
const int MID=500000;
int main()
{
    freopen("11.in","r",stdin);
    cin>>T;
    while(T--)
    {
        memset(t,0,sizeof(t));
        cin>>n>>m;
        int res=0;
        for(int i=1;i<=n;i++)
        {
            cin>>res;
            t[res+MID]++;
        }
        for(int i=1000001;i>=0;i--)
        {
            if(t[i])
            {
                while(t[i]&&m)
                {
                    cout<<i-MID<<" ";
                    t[i]--;
                    m--;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}