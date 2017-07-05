#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int sum,n,L,a[100];
bool vis[100];
bool dfs(int l,int lpos) {
	bool f=0;
	for(int i=1; i<=n; i++) if(!vis[i]) {
			f=1;
			break;
		}
	if(l==0) {
		if(!f) return true;
		else return dfs(L,0);
	}
	if(!f) return false;
	for(int i=lpos+1; i<=n; i++) {
//		cout<<"IN "<<i<<" L: "<<L<<" l: "<<l<<endl;
		if(i>1 && (a[i]==a[i-1]) && (!vis[i-1])) continue;
		if(!vis[i]&&a[i]<=l) {
			vis[i]=true;
			if(dfs(l-a[i],i)) return true;
			vis[i]=false;
			if(a[i]==l) return false;
		}
	}
	return false;
}
int main() {
	while(1) {
		scanf("%d",&n);
		if(n==0) goto ed;
		else {
			memset(a,0,sizeof a);
			memset(vis,0,sizeof vis);
			sum=0;
			for(int i=1; i<=n; i++) {
				scanf("%d",&a[i]);
				sum+=a[i];
			}
			sort(a+1,a+n+1);
			reverse(a+1,a+n+1);
			for(L=a[n]; L<=sum; L++) {
				if(sum%L) continue;
				if(dfs(L,0)) {
					printf("%d\n",L);
				}
			}
		}
	}
ed:
	return 0;
}