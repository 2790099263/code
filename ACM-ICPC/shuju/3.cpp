//I题
//n过大，离散化
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
int sta[MAXN];
int fa[MAXN];
#define getchar() (frS==frT&&(frT=(frS=frBB)+fread(frBB,1,1<<15,stdin),frS==frT)?EOF:*frS++)
char frBB[1<<15],*frS=frBB,*frT=frBB;
template<typename T>
inline void read(T &x)
{
    x=0;char c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
}
int main()
{

}