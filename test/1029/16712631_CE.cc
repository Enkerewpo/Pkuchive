#include<iostream>
#include<cstring>
#define MAXN 1001
using namespace std;
struct pp
{
    int w,s[MAXN];   
}h[101],temp;
int N,K,m,x,i;
bool f[MAXN]; 
char c;
int GetAnswer()
{
     int ans=0,i,type,k,left[MAXN],right[MAXN];
     memset(left,0,sizeof(left));
     memset(right,0,sizeof(right));
     for (k=1;k<=m;k++)
     {
         for (i=1;i<=h[k].w/2;i++) left[h[k].s[i]]++;
         for (i=h[k].w/2+1;i<=h[k].w;i++) right[h[k].s[i]]++;
     }
     for (i=1;i<=N;i++)
      if (left[i]==m && !f[i])
       {
          if (!ans) ans=i;
          else return 0;              
       }
     for (i=1;i<=N;i++)
      if (right[i]==m && !f[i])
       {
          if (!ans || ans==i) ans=i;
          else return 0;              
       }
     return ans;
}
int main()
{
     scanf("%d%d",&N,&K);
     memset(f,false,sizeof(f));
     m=0;
     while (K--)
     {
         scanf("%d",&temp.w);
         temp.w=temp.w*2;
         for (i=1;i<=temp.w;i++) scanf("%d",&temp.s[i]);
         getchar(); c=getchar();
         if (c=='=')
         {
            for (i=1;i<=temp.w;i++)
              f[temp.s[i]]=true;        
         }else
         {
            m++;
            h[m]=temp;
            if (c=='>')
            {
                for (i=1;i<=temp.w/2;i++) h[m].s[i+temp.w/2]=temp.s[i];
                for (i=temp.w/2+1;i<=temp.w;i++) h[m].s[i-temp.w/2]=temp.s[i];  
            } 
         }           
     }
     printf("%d\n",GetAnswer());
     return 0;   
}

