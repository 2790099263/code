#include <bits/stdc++.h>
using namespace std;
char s[10];
int sta[10];
map<int,string>num;
map<int,string>p;
map<int,string>q;
int main()
{
    num[0]="零";
    num[1]="壹";
    num[2]="贰";
    num[3]="叁";
    num[4]="肆";
    num[5]="伍";
    num[6]="陆";
    num[7]="柒";
    num[8]="捌";
    num[9]="玖";
    p[1]="元";
    p[2]="拾";
    p[3]="佰";
    p[4]="仟";
    p[5]="万";
    p[6]="十万";
    p[7]="百万";
    q[1]="角";
    q[2]="分";
    scanf("%s",s);
    int cnt1=1,cnt2=1;
    int len=strlen(s);
    int pos=0;
    for(int i=0;i<len;i++)
        if(s[i]=='.')pos=i;
    cnt1=pos;
    for(int i=0;i<=pos-1;i++)
    {
        // if(s[i]=='0'&&cnt1!=1)
        // {
        //     cout<<num[0];
        //     continue;
        // }
        // else 
        // {
            cout<<num[s[i]-'0'];
            cout<<p[cnt1];
        // }
        cnt1--;
    }
    for(int i=pos+1;i<len;i++)
    {
        if(cnt2==2&&s[i]=='0')
            continue;
        // if(s[i]=='0')
        // {
        //     cout<<num[s[i]-'0'];
        //     continue;
        // }
        // else 
        // {
            cout<<num[s[i]-'0'];
            cout<<q[cnt2];
        // }
        cnt2++;
    }
    cout<<endl;
}  