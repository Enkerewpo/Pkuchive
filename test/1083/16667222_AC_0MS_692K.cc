/*poj1083*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int s[401]={0};
int res=0;
int n;
int i,j;
int a,b;

int main()
{
    int T;
     scanf("%d",&T);
    while(T--)
    {
         memset(s,0,sizeof(s));
         res=0;
        scanf("%d",&n);
        for(i=1;i<=n;++i)
        {
            scanf("%d%d",&a,&b);
            if(a>b) {int t=a;a=b;b=t;}
            if(!(a&1)) a--;
            if(b&1) b++;
            for(j=a;j<=b;++j)
            {
                s[j]++;
                //printf("%d\n",s[j]);
            }
        }
        for(i=1;i<=400;++i) if(s[i]>res) res=s[i];
        res*=10;
        printf("%d\n",res);
    }

    return 0;
}