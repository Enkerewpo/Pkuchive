#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=110;
int a[maxn][maxn],dp[maxn];
int main(){
	int r;
	cin>>r;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=r;j++){
			cin>>a[i][j];
			a[i][j]+=a[i-1][j];
		}
	}
	int max=a[1][1];
	for(int i=0;i<=r-1;++i){
		for(int j=i+1;j<=r;++j){
			memset(dp,0,sizeof dp);
			for(int k=1;k<=r;++k){
				if(dp[k-1]>=0) dp[k]=dp[k-1]+a[j][k]-a[i][k];
				else dp[k]=a[j][k]-a[i][k];
				if(dp[k]>max) max=dp[k];
			}
		}
	}
	cout<<max;
	return 0;
}