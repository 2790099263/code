#include <iostream>
#include <cstring>
using namespace std;
const int MAXN=10004;
int T;
bool jud[MAXN];
int main ()
{
    cin>>T;
    while(T--)
    {
        memset(jud,0,sizeof(jud));
        int n,k;
        cin>>n>>k;
        for(int i=2;i<=k;i++)
        {
            int res=1;
            while(res*i<=n)
            {
                jud[res*i]^=1;
                res++;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(jud[i]==0)cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}