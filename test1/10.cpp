#include<iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int p[8]={1,1,2,0,2,2,1,0};
int T,a,b,m,res;
int main()
{
    freopen("10.in","r",stdin);
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>m;
        a=a%3;
        b=b%3;
        while(m--)
        {
            cin>>res;
            if(res==0)
            {
                if(a%3==0)cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
            else {
                int q=((p[(res-1)%8]*b)%3-(p[(res-1)%8]*a)%3+(p[res%8]*a)%3)%3;
                if(q==0)cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}