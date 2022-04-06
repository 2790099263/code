#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int T,n;
int a[1005];
int t[305];
int main()
{
    cin>>T;
    while(T--)
    {
        for(int i=1;i<=304;i++)t[i]=0;
        cin>>n;
        bool flag=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=2;i<=n;i++)
        {
            if(abs(a[i]-a[i-1])>=n)
            {
                flag=1;
                break;
            }
            else 
            {
                if(t[abs(a[i]-a[i-1])])
                    flag=1;
                else 
                    t[abs(a[i]-a[i-1])]=1;
            }
        }
        if(flag==0)cout<<"Jolly"<<endl;
        else cout<<"Not jolly"<<endl;
    }
    return 0;
}