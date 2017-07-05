#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[400], n, q;
int main() {
	cin >> q;
	while(q--) {
		memset(dp, 0, sizeof dp);
		cin >> n;
		for(int i = 1; i <= n; i++) {
			int a,b;
			cin >> a >> b;
			if( !(a & 1) ) a--;
            if(b & 1) b++;
			if(a > b) swap(a, b);
			for(int j = a; j <= b; j++) {
				dp[j] += 10;
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}