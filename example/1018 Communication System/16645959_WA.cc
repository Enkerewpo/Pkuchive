#include<cstdio>
#include<iostream>
using namespace std;
class device{
	public:
	int b,p;
}dp[150];
int t,n;
int main(){
	scanf("%d%d",&t,&n);
	for(int it=1;it<=t;it++){
		for(int d,i=1;i<=n;i++){
			scanf("%d",&d);
			double tmpl,tmpn;
			double ans=0;
			for(int j=1;j<=d;j++){
				int mb,mp;
				scanf("%d%d",&mb,&mp);
				tmpn=mb/mp;
				if(tmpn>=ans){
					ans=tmpn;
					dp[i].b=mb;
					dp[i].p=mp;	
				} 
			}
			dp[i].p+=dp[i-1].p;
		}
		int anss=0x7f;
		for(int i=1;i<=n;i++) anss=min(anss,dp[i].b);
		double _a=(double)anss/(double)(dp[n].p);
		printf("%.3lf\n",_a);
	}
	return 0;
}