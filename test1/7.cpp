#include <iostream>
#include <cstdio>
using namespace std;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int y,m,d;
int T;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>y>>m>>d;
        if(y%4==0&&y%100!=0)a[2]=29;
        else if(y%100==0&&y%400==0)a[2]=29;
        else a[2]=28;
        int sum=0;
        for(int i=1;i<=m-1;i++)
            sum+=a[i];
        sum+=d;
        cout<<sum<<endl;
    }
    return 0;
}