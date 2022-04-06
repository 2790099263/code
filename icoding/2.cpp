#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
// #include "list.h" // 请不要删除，否则检查不通过
#include <stack>
using namespace std;
stack<int>S;
int compute_reverse_polish_notation(char *str){
    // init_stack(&S);
    int len =strlen (str),f=0;
    cout<<"len"<<len<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<"str[]"<<"  "<<i<<" "<<str[i]<<endl;
        if(str[i]>='0'&&str[i]<='9')
        {
            f=0;
            while(str[i]>='0'&&str[i]<='9')
            {
                // cout<<"while "<<i<<endl;
                f=f*10+str[i]-'0';
                i++;
            }
            i--;
            S.push(f);
            // push(&S,f);
        }
        else if(str[i]==' ')continue;
        else
        {
            int a,b;
            a=S.top();S.pop();
            b=S.top();S.pop();
            cout<<a<<" ab "<<b<<endl;
            // pop(&S,&a);
            // pop(&S,&b);
            if(str[i]=='-')
            {
                f=a-b;
                S.push(f);
                // push(&S,f);
            }
            if(str[i]=='+')
            {
                f=a+b;
                // push(&S,f);
                S.push(f);
            }
            if(str[i]=='*')
            {
                f=a*b;
                // push(&S,f);
                S.push(f);
            }
            if(str[i]=='/')
            {
                f=a/b;
                // push(&S,f);
                S.push(f);
            }
            if(str[i]=='%')
            {
                f=a&b;
                // push(&S,f);
                S.push(f);
            }
        }
    }
    int pp=0;
    pp=S.top();
    S.pop();
    return pp;
}
int main()
{
    char s[1000];
    cin.getline(s,999);
    cout<<"ss"<<s<<endl;
    int ss=compute_reverse_polish_notation(s);
    cout<<ss<<endl;
}