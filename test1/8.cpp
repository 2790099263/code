#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int T;
char s[1005];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>s;
        int len=strlen(s);
        int ji=0,ou=0;
        for(int i=0;i<len;i++)
        {
            if(i%2==0)ou+=s[i]-'0';
            else ji+=s[i]-'0';
        }
        if((ji+ou)%3==0)printf("Yes ");
        else printf("No ");
        if((abs(ji-ou))%11==0)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}